/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:59:35 by vferry            #+#    #+#             */
/*   Updated: 2019/02/18 14:59:37 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		number(char c)
{
	return (!(c >= 48 && c <= 57));
}

static int		help_ttp2(t_elem *info, int move, int im, int *b)
{
	int		flag;
	int		a;

	a = move;
	flag = a;
	while (im - a >= 0 && a < (flag + info->x - info->token->x + 1))
		a++;
	*b = *b + 1;
	return (a);
}

static int		help_ttp(t_elem *info, int move, int im, int *j)
{
	int		flag;
	int		i;

	i = move;
	flag = i;
	while (info->map[im + i] && i < (flag + info->x - info->token->x + 1))
		i++;
	*j = *j + 1;
	return (i);
}

static int		try_to_put2(t_elem *info, int im, int it)
{
	int a;
	int b;

	a = 1;
	b = 1;
	while ((im - a) >= 0 && (it - b) >= 0)
		if (((info->map[im - a] == 'X' || info->map[im - a] == 'O') &&
			info->token->token[it - b] == '*') ||
			(info->map[im - a] == '\n' && info->token->token[it - b] != '\n'))
			return (-1);
		else if (info->token->token[it - b] == '\n')
		{
			a = help_ttp2(info, a, im, &b);
			if (im - a < 0 && it - b >= 0)
				return (-1);
		}
		else
		{
			a++;
			b++;
		}
	if (im - a < 0 && it - b >= 0)
		return (-1);
	info->res = im - (a - 1);
	return (0);
}

int				try_to_put(t_elem *info, int im, int it)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (info->map[im + i] && info->token->token[it + j])
		if (((info->map[im + i] == 'X' || info->map[im + i] == 'O') &&
			info->token->token[it + j] == '*') ||
			(info->map[im + i] == '\n' && info->token->token[it + j] != '\n'))
			return (-1);
		else if (info->token->token[it + j] == '\n')
		{
			i = help_ttp(info, i, im, &j);
			if (info->map[im + i] == 0 && info->token->token[it + j] != 0)
				return (-1);
		}
		else
		{
			i++;
			j++;
		}
	if (try_to_put2(info, im, it) == 0)
		return (0);
	return (-1);
}
