/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:19:16 by vferry            #+#    #+#             */
/*   Updated: 2019/02/18 17:19:19 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_elem	*info;
	t_data	*token;

	info = malloc(sizeof(t_elem));
	token = malloc(sizeof(t_data));
	info->token = token;
	init_struct(info);
	decision_me(info, 0);
	while (1)
	{
		take_params(info, 0);
		if (put_token(info) == 1)
			if (last_chance(info) != -1)
				print_res(info);
			else
			{
				info->res = 0;
				print_res(info);
				break ;
			}
		else
			print_res(info);
		ft_clean(info);
	}
	return (0);
}
