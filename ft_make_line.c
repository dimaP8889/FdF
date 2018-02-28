/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:43:43 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/28 03:14:24 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_finnish_x(t_params params, t_mlx data, int x, int y, int col)
{
	double 	delta;
	double 	y0;
	int		x0;
	int		x1;
	int		y1;
	int 	sign;
	int 	dif_x;
	int 	dif_y;

	y0 = y;
	x0 = x;
	y1 = params.y;
	x1 = params.x;
	dif_x = abs(x - params.x);
	dif_y = abs(y - params.y);
	delta = ((double)dif_y) / ((double)dif_x);
	sign = (params.x > x ? 1 : -1);
	delta *= (params.y > y ? 1 : -1);
	while (x0 != x1)
	{
		mlx_pixel_put(data.mlx, data.wnd, x0, (int)(y0), ft_grad(col, dif_x, &params));
		x0 += sign;
		y0 += delta;
		dif_x--;
	}
	return (0);
}

static int		ft_finnish_y(t_params params, t_mlx data, int x, int y, int col)
{
	double 	delta;
	double 	x0;
	int		y0;
	int		x1;
	int		y1;
	int 	sign;
	int 	dif_x;
	int 	dif_y;

	y0 = y;
	x0 = x;
	y1 = params.y;
	x1 = params.x;
	dif_x = abs(x - params.x);
	dif_y = abs(y - params.y);
	delta = ((double)dif_x) / ((double)dif_y);
	sign = (params.y > y ? 1 : -1);
	delta *= (params.x > x ? 1 : -1);
	while (y0 != y1)
	{
		mlx_pixel_put(data.mlx, data.wnd, (int)(x0), y0, ft_grad(col, dif_y, &params));
		y0 += sign;
		x0 += delta;
		dif_y--;
	}
	return (0);
}

void	ft_print_line(t_params params, int x, int y, t_mlx data, int col)
{
	if (abs(x - params.x) >= abs(y - params.y))
		ft_finnish_x(params, data, x, y, col);
	else
		ft_finnish_y(params, data, x, y, col);
}

void	ft_make_line(t_params **params, t_mlx data)
{
	int				x;
	int				y;
	int				col;
	static int		y_move;
	static int		x_move;

	y = 0;
	x = 0;
	ft_print_params(params);
	while (params[y_move])
	{
		while (!params[y_move][x_move].end)
		{
			x = params[y_move][x_move].x;
			y = params[y_move][x_move].y;
			col = params[y_move][x_move].col;
			if (params[y_move][x_move + 1].end && params[y_move + 1])
				ft_print_line(params[y_move + 1][x_move], x, y, data, col);
			x_move++;
			if (params[y_move][x_move].end)
				break;
			ft_print_line(params[y_move][x_move], x, y, data, col);
			if (params[y_move + 1])
				ft_print_line(params[y_move + 1][x_move - 1], x, y, data, col);
		}
		y_move++;
		if (!params[y_move])
			break;
		x_move = 0;
	}
	mlx_pixel_put(data.mlx, data.wnd, x, y, ft_grad(params[y_move - 1][x_move - 1].col, 1, &params[y_move - 1][x_move - 1]));
	y_move = 0;
	x_move = 0;
}
