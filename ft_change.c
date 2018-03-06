/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:51:21 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/03/05 19:25:29 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ANGLE	(10 * way / (180 / M_PI))
#define	PARAM 	data->params[y][x]
#define	PREV 	prev[y][x]


#include "fdf.h"

void	ft_count_coord(t_params params, t_change *change, t_params start, t_change *check)
{
	double	y;
	double	x;
	double	z;

	y = params.y;
	x = params.x;
	z = params.z;
	check->x = change->x - x;
	check->y = change->y - y;
	check->z = change->z - z;
	change->x -= start.x;
	change->y -= start.y;
	change->z -= start.z;
}

void	ft_rotate_y(t_params params, int way, t_change *change, t_params start, t_change *check)
{
	change->y = change->y;
	change->x = params.x * cos(ANGLE) + params.z * sin(ANGLE);
	change->z = params.x * -sin(ANGLE) + params.z * cos(ANGLE);
	ft_count_coord(params, change, start, check);
}

void	ft_rotate_x(t_params params, int way, t_change *change, t_params start, t_change *check)
{
	change->x = change->x;
	change->y = params.y * cos(ANGLE) + params.z * sin(ANGLE);
	change->z = params.y * -sin(ANGLE) + params.z * cos(ANGLE);
	ft_count_coord(params, change, start, check);
}

void	ft_rotate_z(t_params params, int way, t_change *change, t_params start, t_change *check)
{
	change->z = change->z;
	change->x = params.x * cos(ANGLE) - params.y * sin(ANGLE);
	change->y = params.x * sin(ANGLE) + params.y * cos(ANGLE);
	ft_count_coord(params, change, start, check);
}

void	ft_set_change(t_change *change, t_params prev, int zoom, t_change move)
{
	change->zm = zoom;
	change->x = prev.x + move.x;
	change->y = prev.y + move.y;
	change->z = prev.z + move.z;
	change->centre = 500;
}

t_params		**ft_set_f_p(t_params	**prev, t_mlx *data)
{
	int			x;
	int			y;
	int			cont;

	x = 0;
	y = 0;
	cont = data->sizes.y;
	prev = (t_params **)malloc(sizeof(t_params *) * (data->sizes.y + 1));
	while (data->params[y])
	{
		prev[y] = (t_params *)malloc(sizeof(t_params) * (data->sizes.x + 1));
		while (!data->params[y][x].end)
		{
			PREV.end = 0;
			PREV.x = PARAM.x;
			PREV.y = PARAM.y;
			PREV.z = PARAM.z;
			PREV.col = PARAM.col;
			x++;
		}
		PREV.end = 1;
		x = 0;
		y++;
	}
	prev[y] = NULL;
	return (prev);
}

void		ft_change(t_mlx *data, int keycode)
{
	static	t_params	**prev;
	static	int			zoom;
	t_change		*change;
	static t_change		move;

	int			x;
	int			y;

	change = (t_change *)malloc(sizeof(t_change));
	change->x = 0;
	change->y = 0;
	change->z = 0;
	if (!zoom)
		zoom = 30;
	if (!prev)
		prev = ft_set_f_p(prev, data);
	x = 0;
	y = 0;
	if (keycode == 24)
		zoom *= 1.5;
	if (keycode == 27)
		zoom /= 1.5;
	if (keycode == 13)
		data->move.y -= zoom;
	if (keycode == 1)
		data->move.y += zoom;
	if (keycode == 0)
		data->move.x -= zoom;
	if (keycode == 2)
		data->move.x += zoom;
	while (data->params[y])
	{
		while (!PARAM.end)
		{
			ft_set_change(&PARAM.change, PREV, zoom, move);
			if (keycode == 126 || keycode == 125)
			{
				ft_rotate_x(PREV, (keycode == 126 ? -1 : 1), &PARAM.change, PARAM, change);
				PREV.x += change->x;
				PREV.y += change->y;
				PREV.z += change->z;
			}
			else if (keycode == 123 || keycode == 124)
			{
				ft_rotate_y(PREV, (keycode == 123 ? -1 : 1), &PARAM.change, PARAM, change);
				PREV.x += change->x;
				PREV.y += change->y;
				PREV.z += change->z;
			}
			else if (keycode == 30 || keycode == 33)
			{
				ft_rotate_z(PREV, (keycode == 33 ? -1 : 1), &PARAM.change, PARAM, change);
				PREV.x += change->x;
				PREV.y += change->y;
				PREV.z += change->z;
				move.y = 0;
				move.x = 0;
			}
			else
			{
				PARAM.change.x -= PARAM.x;
				PARAM.change.y -= PARAM.y;
				PARAM.change.z -= PARAM.z;
			}
			x++;
		}
		x = 0;
		y++;
	}
	free(change);
}
