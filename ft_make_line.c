/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:43:43 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/28 20:21:52 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_finnish_x(t_params params, t_mlx data, t_params_prev params_prev)
{
	double 	delta;
	double 	y0;
	double	x0;
	double	x1;
	double	y1;
	int 	sign;
	int 	dif_x;
	int 	dif_y;

	y0 = params_prev.y;
	x0 = params_prev.x;
	y1 = 30 * params.y + 500;
	x1 = 30 * params.x + 500;
	
	dif_x = fabs(x0 - x1);
	dif_y = fabs(y0 - y1);
	// printf("%i\n", dif_y);
	// printf("%i\n", dif_x);
	delta = ((double)dif_y) / ((double)dif_x);
	sign = (x1 > params_prev.x ? 1 : -1);
	delta *= (y1 > params_prev.y ? 1 : -1);
	while (floor(x0) != floor(x1))
	{
		mlx_pixel_put(data.mlx, data.wnd, x0, (int)(y0), ft_grad(params_prev.col, dif_x, &params));
		x0 += sign;
		y0 += delta;
		dif_x--;
	}
	return (0);
}

static int		ft_finnish_y(t_params params, t_mlx data, t_params_prev params_prev)
{
	double 	delta;
	double 	x0;
	double	y0;
	double	x1;
	double	y1;
	int 	sign;
	int 	dif_x;
	int 	dif_y;

	y0 = params_prev.y;
	x0 = params_prev.x;
	y1 = 30 * params.y + 500;
	x1 = 30 * params.x + 500;
	
	dif_x = fabs(x0 - x1);
	dif_y = fabs(y0 - y1);
	// printf("%i\n", dif_y);
	// printf("%i\n", dif_x);
	delta = ((double)dif_x) / ((double)dif_y);
	sign = (y1 > params_prev.y ? 1 : -1);
	delta *= (x1 > params_prev.x ? 1 : -1);
	while (floor(y0) != floor(y1))
	{
		mlx_pixel_put(data.mlx, data.wnd, (int)(x0), y0, ft_grad(params_prev.col, dif_y, &params));
		y0 += sign;
		x0 += delta;
		dif_y--;
	}
	return (0);
}

void	ft_print_line(t_params params, t_params_prev params_prev, t_mlx data)
{
	if (fabs(params_prev.x - (30 * params.x + 500)) >= fabs(params_prev.y - (30 * params.y + 500)))
		ft_finnish_x(params, data, params_prev);
	else
		ft_finnish_y(params, data, params_prev);
}

void	ft_make_line(t_params **params, t_mlx data)
{
	static int				y_move;
	static int				x_move;
	static t_params_prev	params_prev;

	//ft_print_params(params);
	while (params[y_move])
	{
		while (!params[y_move][x_move].end)
		{
			params_prev.x = 30 * params[y_move][x_move].x + 500;
			params_prev.y = 30 * params[y_move][x_move].y + 500;
			params_prev.col = params[y_move][x_move].col;
			if (params[y_move][x_move + 1].end && params[y_move + 1])
				ft_print_line(params[y_move + 1][x_move], params_prev, data);
			x_move++;
			if (params[y_move][x_move].end)
				break;
			ft_print_line(params[y_move][x_move], params_prev, data);
			if (params[y_move + 1])
				ft_print_line(params[y_move + 1][x_move - 1], params_prev, data);
		}
		y_move++;
		if (!params[y_move])
			break;
		x_move = 0;
	}
	mlx_pixel_put(data.mlx, data.wnd, params_prev.x, params_prev.y, ft_grad(params[y_move - 1][x_move - 1].col, 1, &params[y_move - 1][x_move - 1]));
	y_move = 0;
	x_move = 0;
}
