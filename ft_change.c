/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:51:21 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/03/09 01:28:04 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ANGLE	(check->angle * check->way / (180 / M_PI))
#define	PARAM 	data->params[y][x]
#define	PREV 	prev[y][x]


#include "fdf.h"

void	ft_count_coord(t_params *params, t_change *change, t_params start, t_change *check)
{
	double	y;
	double	x;
	double	z;

	y = params->y;
	x = params->x;
	z = params->z;
	check->x = change->x - x;
	check->y = change->y - y;
	check->z = change->z - z;
	change->x -= start.x;
	change->y -= start.y;
	change->z -= start.z;
}

void	ft_rotate_y(t_params *params, t_change *change, t_params start, t_change *check)
{
	change->y = change->y;
	change->x = params->x * cos(ANGLE) + params->z * sin(ANGLE);
	change->z = params->x * -sin(ANGLE) + params->z * cos(ANGLE);
	ft_count_coord(params, change, start, check);
}

void	ft_rotate_x(t_params *params, t_change *change, t_params start, t_change *check)
{
	change->x = change->x;
	change->y = params->y * cos(ANGLE) + params->z * sin(ANGLE);
	change->z = params->y * -sin(ANGLE) + params->z * cos(ANGLE);
	ft_count_coord(params, change, start, check);
}

void	ft_rotate_z(t_params *params, t_change *change, t_params start, t_change *check)
{
	change->z = change->z;
	change->x = params->x * cos(ANGLE) - params->y * sin(ANGLE);
	change->y = params->x * sin(ANGLE) + params->y * cos(ANGLE);
	ft_count_coord(params, change, start, check);
}

void	ft_set_change(t_change *change, t_params *prev, t_change *zoom)
{
	change->zm = zoom->zm;
	change->x = prev->x;
	change->y = prev->y;
	change->z = prev->z;
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

void		ft_choose_params(t_change *change, int keycode, t_mlx *data)
{
	if (keycode == 125 || keycode == 124 || keycode == 30)
		change->way = 1;
	else
		change->way = -1;
	if (!change->angle)
		change->angle = 45;
	else
		change->angle = 10;
	if (!change->zm)
		change->zm = 30;
	if (keycode == 53)
		exit(1);
	if (keycode == 24 && change->zm < 130)
		change->zm *= 1.5;
	if (keycode == 27 && change->zm > 10)
		change->zm /= 1.5;
	if (keycode == 13)
		data->move.y -= change->zm;
	if (keycode == 1)
		data->move.y += change->zm;
	if (keycode == 0)
		data->move.x -= change->zm;
	if (keycode == 2)
		data->move.x += change->zm;
}

void		ft_start_pic(t_params *prev, t_change *change, t_params params, t_change *move)
{
	ft_rotate_x(prev, change, params, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
	ft_set_change(change, prev, move);
	ft_rotate_y(prev, change, params, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
}

void		ft_rotate_up_down(t_params *prev, t_change *change, t_params params, t_change *move)
{
	ft_rotate_x(prev, change, params, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
}

void		ft_rotate_left_right(t_params *prev, t_change *change, t_params params, t_change *move)
{
	ft_rotate_y(prev, change, params, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
}

void		ft_rotate_around(t_params *prev, t_change *change, t_params params, t_change *move)
{
	ft_rotate_z(prev, change, params, move);
	prev->x += move->x;
	prev->y += move->y;
	prev->z += move->z;
}

void		ft_change_params(t_change *change, t_params params)
{
	change->x -= params.x;
	change->y -= params.y;
	change->z -= params.z;
}

int		ft_set_and_first(t_params *prev, t_change *change, t_params params, t_change *move)
{
	ft_set_change(change, prev, move);
	if (move->angle == 45)
	{
		ft_start_pic(prev, change, params, move);
		return (1);
	}
	return (0);
}

t_params		**ft_last_cut(t_change *change, int keycode, t_mlx *data, t_params **prev)
{
	ft_choose_params(change, keycode, data);
	if (!prev)
	{
		prev = ft_set_f_p(prev, data);
	}
	return (prev);
}

void		ft_change(t_mlx *data, int keycode)
{
	static	t_params	**prev;
	static t_change		change;
	static int			x;
	int			y;

	prev = ft_last_cut(&change, keycode, data, prev);
	y = -1;
	while (data->params[++y])
	{
		while (!PARAM.end)
		{
			if (ft_set_and_first(&PREV, &PARAM.change, PARAM, &change));
			else if (keycode == 126 || keycode == 125)
				ft_rotate_up_down(&PREV, &PARAM.change, PARAM, &change);
			else if (keycode == 123 || keycode == 124)
				ft_rotate_left_right(&PREV, &PARAM.change, PARAM, &change);
			else if (keycode == 30 || keycode == 33)
				ft_rotate_around(&PREV, &PARAM.change, PARAM, &change);
			else
				ft_change_params(&PARAM.change, PARAM);
			x++;
		}
		x = 0;
	}
}
