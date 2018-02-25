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

static int		ft_finnish_x(t_params params, t_mlx data, int x, int y)
{
	double 	delta;
	double 	y0;
	int 	sign;
	int 	dif_x;
	int 	dif_y;

	
	y0 = params.y;
	dif_x = abs(x - params.x);
	dif_y = abs(y - params.y);
	delta = ((double)dif_y) / ((double)dif_x);
	sign = (x > params.x ? 1 : -1);
	delta *= (y > params.y ? 1 : -1);
	
	while (params.x != x)
	{
		// printf("%i\n", params.y);
		// printf("%#x\n", params.col);
		mlx_pixel_put(data.mlx, data.wnd, params.x, (int)(y0), ft_grad(params.col, dif_x, &params));
		params.x += sign;
		y0 += delta;
	}
	return (0);
}

static int		ft_finnish_y(t_params params, t_mlx data, int x, int y)
{
	double 	delta;
	double 	x0;
	int 	sign;
	int 	dif_x;
	int 	dif_y;

	
	x0 = params.x;
	dif_x = abs(x - params.x);
	dif_y = abs(y - params.y);
	delta = ((double)dif_x) / ((double)dif_y);
	sign = (y > params.y ? 1 : -1);
	delta *= (x > params.x ? 1 : -1);
	while (params.y != y)
	{
		// printf("%i\n", params.y);
		// printf("%#x\n", params.col);
		mlx_pixel_put(data.mlx, data.wnd, (int)(x0), params.y, ft_grad(params.col, dif_y, &params));
		params.y += sign;
		x0 += delta;
	}
	return (0);
}

void	ft_print_line(t_params params, int x, int y, t_mlx data)
{
	
	if (abs(x - params.x) >= abs(y - params.y))
		ft_finnish_x(params, data, x, y);
	else
		ft_finnish_y(params, data, x, y);
}

void	ft_make_line(t_params **params, t_mlx data)
{
	int				x;
	int				y;
	static int		y_move;
	static int		x_move;

	mlx_pixel_put(data.mlx, data.wnd, params[y_move][x_move].x, params[y_move][x_move].y, 
	ft_grad(params[y_move][x_move].col, 1, &params[y_move][x_move]));
	while (params[y_move])
	{
		while (!params[y_move][x_move].end)
		{
			x = params[y_move][x_move].x;
			y = params[y_move][x_move].y;
			// printf("%i\n", params[y_move][x_move].y);
			// printf("%#x\n", params[y_move][x_move].col);
			if (params[y_move][x_move + 1].end && params[y_move + 1])
				ft_print_line(params[y_move + 1][x_move], x, y, data);
			x_move++;
			if (params[y_move][x_move].end)
				break;
			ft_print_line(params[y_move][x_move], x, y, data);
			if (params[y_move + 1] && !params[y_move + 1][x_move - 1].end)
				ft_print_line(params[y_move + 1][x_move - 1], x, y, data);
		}
		x_move = 0;
		y_move++;
	}
	y_move = 0;	
}
