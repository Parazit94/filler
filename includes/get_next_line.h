/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:21:51 by vferry            #+#    #+#             */
/*   Updated: 2018/12/08 17:34:57 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

int				get_next_line(const int fd, char **line);

#endif
