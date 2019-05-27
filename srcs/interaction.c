/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:59:21 by vferry            #+#    #+#             */
/*   Updated: 2019/02/18 14:59:23 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_clean(t_elem *info)
{
	if (info)
	{
		free(info->map);
		info->map = NULL;
		free(info->token->token);
		info->token->token = NULL;
		free(info->imap);
		info->imap = NULL;
	}
}

int		decision_me(t_elem *info, int fd)
{
	int		i;
	char	*buff;

	i = 0;
	get_next_line(fd, &buff);
	while (buff[i])
	{
		if (buff[i] == '1')
		{
			info->me = 'O';
			info->en = 'X';
			break ;
		}
		else if (buff[i] == '2')
		{
			info->me = 'X';
			info->en = 'O';
			break ;
		}
		i++;
	}
	if (buff)
		free(buff);
	return (i);
}

void	print_res(t_elem *info)
{
	int		x;
	int		y;
	int		res;

	res = info->res;
	x = res - ((res / (info->x + 1)) * (info->x + 1));
	y = res / (info->x + 1);
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int		take_params(t_elem *info, int fd)
{
	char	*line;
	int		i;

	i = 0;
	info->score = 1000000;
	info->res2 = -1;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			init_map(info, line, fd);
			ft_strdel(&line);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			init_token(info, line, fd);
			ft_strdel(&line);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

void	init_struct(t_elem *info)
{
	info->map = NULL;
	info->imap = NULL;
	info->token->token = NULL;
	info->token->x = 0;
	info->token->y = 0;
	info->me = 0;
	info->en = 0;
	info->x = 0;
	info->y = 0;
	info->res = 0;
	info->res2 = -1;
	info->score = 1000000;
}
