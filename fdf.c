/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:13:34 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/21 16:18:29 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_mlx
{
	void		*mlx;
	void		*wnd;
	int 		x;
	int 		y;
}				t_mlx;

void	ft_make_change(t_mlx *data, int *x, int *y)
{
	int change;

	change = data->x;
	data->x = *x;
	*x = change;
	change = data->y;
	data->y = *y;
	*y = change;
}

int		ft_finnish(t_mlx *data, int x, int y)
{
	int 	dif_x;
	int 	dif_y;
	int 	x0;
	int 	y0;
	int 	dx;
	int 	dy;
	double	d_y;
	double 	d_x;
	int 	length;

	x0 = data->x;
	y0 = data->y;
	dif_x = abs(x - x0);
	dif_y = abs(y - y0);
	dx = (x - x0 >= 0 ? 1 : -1);
    dy = (y - y0 >= 0 ? 1 : -1);
	length = dif_x > dif_y ? dif_x : dif_y;
	if (length == 0)
		mlx_pixel_put(data->mlx, data->wnd, data->x, data->y, 0xFF0000);
	if (dif_x <= dif_y)
	{
		d_y = y;
		length++;
		while (length--)
		{
			mlx_pixel_put(data->mlx, data->wnd, data->x, data->y, 0xFF0000);
			x0 += dx;
			y += dy * (double)(dif_y/dif_x);
		}
	}
	else
	{
		d_x = x0;

		length++;
		while (length--)
		{
			mlx_pixel_put(data->mlx, data->wnd, data->x, data->y, 0xFF0000);
			x0 += dx * (double)(dif_x/dif_y);
			y += dy;
		}
	}

	return (0);
}

int		ft_start(int button, int x, int y, void *d)
{
	t_mlx	*data;

	data = ((t_mlx*)d);
	if (button == 1)
	{
		mlx_pixel_put(data->mlx, data->wnd, x, y, 0xFFFFFF);
		data->x = x;
		data->y = y;
	}
	if (button == 2)
	{
		ft_finnish(data, x, y);
		//mlx_pixel_put(data->mlx, data->wnd, x, y, 0xFF0000);
	}
	return (0);
}

int 	main(int ac, char **av)
{
	ac = 0;
	**av = 0;
	t_mlx	data;
	int count;

	count = 0;
	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, 500, 500, "mlx 42");

	mlx_mouse_hook(data.wnd, ft_start, &data);
	mlx_loop(data.mlx);
	return (0);
}
