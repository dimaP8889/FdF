/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:51:21 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/03/10 11:55:13 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ANGLE	(check->angle * check->way / (180 / M_PI))
#define PARAM	data->param[y][x]
#define PREV	prev[y][x]

static void	ft_up_down(t_p *prev, t_c *change, t_p param, t_c *move)
{
	ft_rotate_x(prev, change, param, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
}

static void	ft_left_right(t_p *prev, t_c *change, t_p param, t_c *move)
{
	ft_rotate_y(prev, change, param, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
}

static void	ft_around(t_p *prev, t_c *change, t_p param, t_c *move)
{
	ft_rotate_z(prev, change, param, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
}

static void	ft_c_param(t_c *change, t_p param)
{
	change->x -= param.x;
	change->y -= param.y;
	change->z -= param.z;
}

void		ft_c(t_mlx *data, int keycode)
{
	static t_p		**prev;
	static t_c		change;
	static int		x;
	int				y;

	prev = ft_keycode(&change, keycode, data, prev);
	y = -1;
	while (data->param[++y])
	{
		while (!PARAM.end)
		{
			if (ft_set_and_fir(&PREV, &PARAM.change, PARAM, &change))
				;
			else if (keycode == 126 || keycode == 125)
				ft_up_down(&PREV, &PARAM.change, PARAM, &change);
			else if (keycode == 123 || keycode == 124)
				ft_left_right(&PREV, &PARAM.change, PARAM, &change);
			else if (keycode == 30 || keycode == 33)
				ft_around(&PREV, &PARAM.change, PARAM, &change);
			else
				ft_c_param(&PARAM.change, PARAM);
			x++;
		}
		x = 0;
	}
}
