/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_central.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:54:38 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/02/28 01:34:43 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// x = (1000 - (sizes.x - 1) * 30) / 2;
// y = (1000 - sizes.y) / 2;


void	ft_make_central(t_params **params)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_print_params(params);
	while (params[y])
	{
		while (!params[y][x].end)
		{
			params[y][x].x = /*(1000 - (params[y][x].x - 1) * 30) / 2 */100 + params[y][x].x;
			params[y][x].y = /*(1000 - params[y][x].y) / 2*/100 + params[y][x].y;
			params[y][x].z = /*(1000 - (params[y][x].z - 1) * 30) / 2*/100 + params[y][x].z;
			printf("x pr:%i\n", params[y][x].x);
			printf("y pr:%i\n", params[y][x].y);
			printf("z pr:%i\n", params[y][x].z);
			x++;
		}
		x = 0;
		y++;
	}
}