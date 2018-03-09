/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:16:02 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/09 19:16:03 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ANGLE	(check->angle * check->way / (180 / M_PI))

#include "fdf.h"

static void	ft_count_coord(t_p *param, t_c *change, t_p start, t_c *check)
{
	double	y;
	double	x;
	double	z;

	y = param->y;
	x = param->x;
	z = param->z;
	check->x = change->x - x;
	check->y = change->y - y;
	check->z = change->z - z;
	change->x -= start.x;
	change->y -= start.y;
	change->z -= start.z;
}

void		ft_rotate_y(t_p *param, t_c *change, t_p start, t_c *check)
{
	change->y = change->y;
	change->x = param->x * cos(ANGLE) + param->z * sin(ANGLE);
	change->z = param->x * -sin(ANGLE) + param->z * cos(ANGLE);
	ft_count_coord(param, change, start, check);
}

void		ft_rotate_x(t_p *param, t_c *change, t_p start, t_c *check)
{
	change->x = change->x;
	change->y = param->y * cos(ANGLE) + param->z * sin(ANGLE);
	change->z = param->y * -sin(ANGLE) + param->z * cos(ANGLE);
	ft_count_coord(param, change, start, check);
}

void		ft_rotate_z(t_p *param, t_c *change, t_p start, t_c *check)
{
	change->z = change->z;
	change->x = param->x * cos(ANGLE) - param->y * sin(ANGLE);
	change->y = param->x * sin(ANGLE) + param->y * cos(ANGLE);
	ft_count_coord(param, change, start, check);
}
