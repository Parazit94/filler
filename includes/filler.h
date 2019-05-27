/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:02:57 by vferry            #+#    #+#             */
/*   Updated: 2019/02/18 15:02:59 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_data
{
	int		x;
	int		y;
	char	*token;
}				t_data;

typedef struct	s_elem
{
	char	*map;
	t_data	*token;
	int		*imap;
	char	me;
	char	en;
	int		x;
	int		y;
	int		res;
	int		res2;
	int		score;
}				t_elem;

void			get_board(t_elem *info, char *str);
void			init_board(t_elem *info, int fd);
void			init_map(t_elem *info, char *line, int fd);
void			get_token(t_elem *info, int fd);
void			init_token(t_elem *info, char *line, int fd);
void			get_en(t_elem *info, int i, int len);
void			get_rait(t_elem *info, int rait, int i, int len);
void			put_rait(t_elem *info, int len);
void			get_imap(t_elem *info, int len);
void			init_imap(t_elem *info);
int				take_params(t_elem *info, int fd);
void			init_struct(t_elem *info);
void			print_res(t_elem *info);
void			ft_clean(t_elem *info);
int				decision_me(t_elem *info, int fd);
void			get_en(t_elem *info, int i, int len);
void			get_rait(t_elem *info, int rait, int i, int len);
void			put_rait(t_elem *info, int len);
void			get_imap(t_elem *info, int len);
void			init_imap(t_elem *info);
int				last_chance(t_elem *info);
int				put_token(t_elem *info);
void			get_score(t_elem *info);
int				try_to_put(t_elem *info, int im, int it);
int				number(char c);

#endif
