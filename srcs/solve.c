/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:59:28 by vferry            #+#    #+#             */
/*   Updated: 2019/02/18 14:59:29 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	put_score(t_elem *info, int score)
{
	if (info->score > score)
	{
		info->score = score;
		info->res2 = info->res;
	}
}

static int	put_res(t_elem *info)
{
	if (info->res2 > 0)
	{
		info->res = info->res2;
		return (0);
	}
	return (1);
}

void		get_score(t_elem *info)
{
	int		i;
	int		j;
	int		lol;
	int		score;

	i = info->res;
	j = 0;
	score = 0;
	while (info->token->token[j])
	{
		if (info->token->token[j] == '\n')
		{
			lol = i;
			while (info->map[i] && i < (lol + info->x - info->token->x + 1))
				i++;
			j++;
		}
		if (info->token->token[j] == '*')
			if (info->map[i] != info->me)
				score += info->imap[i];
		i++;
		j++;
	}
	put_score(info, score);
}

int			put_token(t_elem *info)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(info->map);
	i = 0;
	while (info->map[i] && i < len)
	{
		if (info->map[i] == info->me)
		{
			j = 0;
			while (info->token->token[j])
			{
				if (info->token->token[j] == '*')
					if (try_to_put(info, i, j) == 0)
						get_score(info);
				j++;
			}
		}
		i++;
	}
	return (put_res(info));
}

int			last_chance(t_elem *info)
{
	int		i;
	int		j;

	i = 0;
	while (info->map[i])
	{
		if (info->map[i] == info->me)
		{
			j = 0;
			while (info->token->token[j])
			{
				if (info->token->token[j] == '*')
					if (try_to_put(info, i, j) == 0)
						return (0);
				j++;
			}
		}
		i++;
	}
	return (-1);
}
