/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_and_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:05:11 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/09 19:05:12 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PARAM 	data->param[y][x]
#define PREV 	prev[y][x]

#include "fdf.h"

static void	ft_set_c(t_c *change, t_p *prev, t_c *zoom)
{
	change->zm = zoom->zm;
	change->x = prev->x;
	change->y = prev->y;
	change->z = prev->z;
	change->centre = 500;
}

static void	ft_start_pic(t_p *prev, t_c *change, t_p param, t_c *move)
{
	ft_rotate_x(prev, change, param, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
	ft_set_c(change, prev, move);
	ft_rotate_y(prev, change, param, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
}

int			ft_set_and_fir(t_p *prev, t_c *change, t_p param, t_c *move)
{
	ft_set_c(change, prev, move);
	if (move->angle == 45)
	{
		ft_start_pic(prev, change, param, move);
		return (1);
	}
	return (0);
}
