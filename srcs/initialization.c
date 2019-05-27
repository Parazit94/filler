/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:59:14 by vferry            #+#    #+#             */
/*   Updated: 2019/02/18 14:59:15 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_board(t_elem *info, char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*board;

	i = 0;
	j = 0;
	len = (info->x + 1) * info->y + 1;
	if (!(board = (char *)malloc(sizeof(char) * len)))
		return ;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == 'o' || str[i] == 'O' ||
			str[i] == 'x' || str[i] == 'X' || (str[i] == '\n' && j != 0))
		{
			board[j] = str[i];
			j++;
		}
		i++;
	}
	board[j] = 0;
	info->map = board;
	init_imap(info);
}

void	init_board(t_elem *info, int fd)
{
	char	*line;
	char	*map;
	char	*buff;
	int		i;

	i = 0;
	get_next_line(fd, &line);
	ft_strdel(&line);
	map = ft_strnew(0);
	while (i < info->y)
	{
		buff = map;
		get_next_line(fd, &line);
		map = ft_strjoin(buff, line);
		ft_strdel(&buff);
		ft_strdel(&line);
		buff = map;
		map = ft_strjoin(map, "\n");
		ft_strdel(&buff);
		i++;
	}
	get_board(info, map);
	ft_strdel(&map);
}

void	init_map(t_elem *info, char *line, int fd)
{
	int		i;
	int		tmp;

	info->x = 0;
	info->y = 0;
	i = 0;
	while (line[i])
	{
		tmp = 0;
		while (line[i] && number(line[i]) == 0)
		{
			tmp += line[i] - 48;
			if (number(line[i + 1]) == 0)
				tmp *= 10;
			i++;
		}
		if (info->y == 0)
			info->y = tmp;
		else if (info->x == 0)
			info->x = tmp;
		i++;
	}
	init_board(info, fd);
}

void	get_token(t_elem *info, int fd)
{
	char	*line;
	char	*buff;
	char	*token;
	int		i;

	i = 0;
	token = ft_strnew(0);
	while (i < info->token->y)
	{
		buff = token;
		get_next_line(fd, &line);
		token = ft_strjoin(token, line);
		ft_strdel(&line);
		ft_strdel(&buff);
		buff = token;
		token = ft_strjoin(token, "\n");
		ft_strdel(&buff);
		i++;
	}
	info->token->token = ft_strdup(token);
	ft_strdel(&token);
}

void	init_token(t_elem *info, char *line, int fd)
{
	int		i;
	int		tmp;

	i = 0;
	info->token->x = 0;
	info->token->y = 0;
	while (line[i])
	{
		tmp = 0;
		while (line[i] && number(line[i]) == 0)
		{
			tmp += line[i] - 48;
			if (number(line[i + 1]) == 0)
				tmp *= 10;
			i++;
		}
		if (info->token->y == 0)
			info->token->y = tmp;
		else if (info->token->x == 0)
			info->token->x = tmp;
		i++;
	}
	get_token(info, fd);
}
