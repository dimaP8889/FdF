/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:43:43 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/24 17:43:44 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_finnish_x(t_mlx data, int x, int y)
{
	double 	delta;
	double 	y0;
	int 	sign;
	int 	dif_x;
	int 	dif_y;

	y0 = data.y;
	dif_x = abs(x - data.x);
	dif_y = abs(y - data.y);
	delta = ((double)dif_y) / ((double)dif_x);
	sign = (x > data.x ? 1 : -1);
	delta *= (y > data.y ? 1 : -1);
	while (data.x != x)
	{
		mlx_pixel_put(data.mlx, data.wnd, data.x, (int)(y0), ft_grad(0x654321, dif_x, &data));
		data.x += sign;
		y0 += delta;
	}
	return (0);
}

static int		ft_finnish_y(t_mlx data, int x, int y)
{
	double 	delta;
	double 	x0;
	int 	sign;
	int 	dif_x;
	int 	dif_y;

	x0 = data.x;
	dif_x = abs(x - data.x);
	dif_y = abs(y - data.y);
	delta = ((double)dif_x) / ((double)dif_y);
	sign = (y > data.y ? 1 : -1);
	delta *= (x > data.x ? 1 : -1);
	while (data.y != y)
	{
		mlx_pixel_put(data.mlx, data.wnd, (int)(x0), data.y, ft_grad(0x654321, dif_y, &data));
		data.y += sign;
		x0 += delta;
	}
	return (0);
}

int		ft_make_line(int button, int x, int y, void *d)
{
	static t_mlx	*data;

	data = ((t_mlx*)d);
	if (button == 1)
	{
		mlx_pixel_put(data->mlx, data->wnd, x, y, 0xFF0000);
		data->col = 0xFF0000;
		data->x = x;
		data->y = y;
	}
	if (button == 2)
	{
		if (abs(x - data->x) >= abs(y - data->y))
			ft_finnish_x(*data, x, y);
		else
			ft_finnish_y(*data, x, y);
	}
	return (0);
}