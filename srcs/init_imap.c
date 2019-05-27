/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:59:04 by vferry            #+#    #+#             */
/*   Updated: 2019/02/18 14:59:06 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_en(t_elem *info, int i, int len)
{
	if (i + 1 < len && info->imap[i + 1] == -1)
		info->imap[i] = 1;
	if (i - 1 >= 0 && info->imap[i - 1] == -1)
		info->imap[i] = 1;
	if ((i + info->x) < len && info->imap[i + info->x] == -1)
		info->imap[i] = 1;
	if ((i - info->x) >= 0 && info->imap[i - info->x] == -1)
		info->imap[i] = 1;
	if ((i + 1 + info->x) < len && info->imap[i + 1 + info->x] == -1)
		info->imap[i] = 1;
	if ((i + 2 + info->x) < len && info->imap[i + 2 + info->x] == -1)
		info->imap[i] = 1;
	if ((i - info->x - 1) >= 0 && info->imap[i - info->x - 1] == -1)
		info->imap[i] = 1;
	if ((i - info->x - 2) >= 0 && info->imap[i - info->x - 2] == -1)
		info->imap[i] = 1;
}

void	get_rait(t_elem *info, int rait, int i, int len)
{
	if (i + 1 < len && info->imap[i + 1] == rait)
		info->imap[i] = rait + 1;
	if (i - 1 >= 0 && info->imap[i - 1] == rait)
		info->imap[i] = rait + 1;
	if ((i + info->x) < len && info->imap[i + info->x] == rait)
		info->imap[i] = rait + 1;
	if ((i - info->x) >= 0 && info->imap[i - info->x] == rait)
		info->imap[i] = rait + 1;
	if ((i + 1 + info->x) < len && info->imap[i + 1 + info->x] == rait)
		info->imap[i] = rait + 1;
	if ((i + 2 + info->x) < len && info->imap[i + 2 + info->x] == rait)
		info->imap[i] = rait + 1;
	if ((i - info->x - 1) >= 0 && info->imap[i - info->x - 1] == rait)
		info->imap[i] = rait + 1;
	if ((i - info->x - 2) >= 0 && info->imap[i - info->x - 2] == rait)
		info->imap[i] = rait + 1;
}

void	put_rait(t_elem *info, int len)
{
	int		i;
	int		rait;

	rait = 1;
	while (rait < info->x)
	{
		i = 0;
		while (i < len)
		{
			if (info->imap[i] == 0)
				get_rait(info, rait, i, len);
			i++;
		}
		rait++;
	}
}

void	get_imap(t_elem *info, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (info->imap[i] == -3 || info->imap[i] == -1 || info->imap[i] == -2)
		{
			i++;
			continue ;
		}
		else
			get_en(info, i, len);
		i++;
	}
	put_rait(info, len);
}

void	init_imap(t_elem *info)
{
	int		*imap;
	int		len;
	int		i;

	len = ft_strlen(info->map);
	imap = malloc(sizeof(int) * len);
	i = 0;
	while (i < len && info->map[i])
	{
		if (info->map[i] == '.')
			imap[i] = 0;
		else if (info->map[i] == info->me)
			imap[i] = -2;
		else if (info->map[i] == info->en)
			imap[i] = -1;
		else
			imap[i] = -3;
		i++;
	}
	info->imap = imap;
	get_imap(info, i);
}
