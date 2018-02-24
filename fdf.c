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

#include "fdf.h"

int 	ft_make_col(int b_start, int r_start, int g_start)
{
	int ret;
	g_start <<= 8;
	r_start <<= 16;
	ret = r_start | g_start | b_start;
	return (ret);
}

t_grad	*ft_find_delta(t_mlx *data, int moves, int fin_col)
{
	t_grad *grad;

	grad = (t_grad *)malloc(sizeof(t_grad));
	grad->b_start = (data->col) & 255;
	grad->g_start = (data->col) >> 8;
	grad->g_start &= 255;
	grad->r_start = (data->col) >> 16;
	grad->b_to = fin_col & 255;
	grad->g_to = fin_col >> 8;
	grad->g_to = grad->g_to & 255;
	grad->r_to = fin_col >> 16;
	grad->r_delta = (((double)grad->r_start) - ((double)grad->r_to)) / (double)moves;
	grad->g_delta = (((double)grad->g_start) - ((double)grad->g_to)) / (double)moves;
	grad->b_delta = (((double)grad->b_start) - ((double)grad->b_to)) / (double)moves;
	data->check = 1;
	return (grad);
}

int 	ft_grad(int fin_col, int moves, t_mlx *data)
{
	static t_grad 	*grad;
	static 	double 		r;
	static 	double		g;
	static 	double		b;

	if (!data->check)
	{
		grad = ft_find_delta(data, moves, fin_col);
		r = grad->r_start;
		g = grad->g_start;
		b = grad->b_start;
	}
	b -= grad->b_delta;
	r -= grad->r_delta;
	g -= grad->g_delta;
	data->col = ft_make_col((int)b, (int)r, (int)g);
	return (data->col);
}

int		ft_finnish_x(t_mlx data, int x, int y)
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
		mlx_pixel_put(data.mlx, data.wnd, data.x, (int)(y0), ft_grad(0x842684, dif_x, &data));
		data.x += sign;
		y0 += delta;
	}
	return (0);
}

int		ft_finnish_y(t_mlx data, int x, int y)
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
		mlx_pixel_put(data.mlx, data.wnd, (int)(x0), data.y, ft_grad(0x842684, dif_y, &data));
		data.y += sign;
		x0 += delta;
	}
	return (0);
}

int		ft_start(int button, int x, int y, void *d)
{
	static t_mlx	*data;

	data = ((t_mlx*)d);
	if (button == 1)
	{
		mlx_pixel_put(data->mlx, data->wnd, x, y, 0x597548);
		data->col = 0x597548;
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

int 	main(int ac, char **av)
{
	ac = 0;
	**av = 0;
	t_mlx	data;
	int count;
	//int fd;

	count = 0;
	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, 1000, 1000, "mlx 42");
	// fd = open(av[1], O_RDNLY);
	// ft_parse(fd);
	mlx_mouse_hook(data.wnd, ft_start, &data);
	mlx_loop(data.mlx);
	return (0);
}
