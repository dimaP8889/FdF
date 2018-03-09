/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_cut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:21:23 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/09 19:21:23 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PARAM	data->param[y][x]
#define PREV 	prev[y][x]

#include "fdf.h"

static t_p		**ft_set_f_p(t_p **prev, t_mlx *data)
{
	static int			x;
	int					y;
	int					cont;

	y = 0;
	cont = data->sizes.y;
	prev = (t_p **)malloc(sizeof(t_p *) * (data->sizes.y + 1));
	while (data->param[y])
	{
		prev[y] = (t_p *)malloc(sizeof(t_p) * (data->sizes.x + 1));
		while (!data->param[y][x].end)
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

static void		ft_choose_param(t_c *change, int keycode, t_mlx *data)
{
	if (keycode == 125 || keycode == 124 || keycode == 30)
		change->way = 1;
	else
		change->way = -1;
	if (!change->angle)
		change->angle = 45;
	else
		change->angle = 5;
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

t_p				**ft_last_cut(t_c *chg, int kd, t_mlx *data, t_p **pv)
{
	ft_choose_param(chg, kd, data);
	if (!pv)
		pv = ft_set_f_p(pv, data);
	return (pv);
}
