/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:43:43 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/05 19:21:34 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	X0		(prev.change.zm * (prev.change.x + prev.x) + prev.change.centre + data->move.x)
#define	Y0 		(prev.change.zm * (prev.change.y + prev.y) + prev.change.centre + data->move.y)
#define	X1 		(params.change.zm * (params.change.x + params.x) + params.change.centre + data->move.x)
#define	Y1 		(params.change.zm * (params.change.y + params.y) + params.change.centre  + data->move.y)
#define	PARAMS 	data->params
#define	MLX 	data->mlx
#define	WND 	data->wnd

#include "fdf.h"

static int		ft_finnish_x(t_params params, t_mlx *data, t_params_prev prev)
{
	double 	delta;
	double 	y0;
	double	x0;
	double	x1;
	double	y1;
	int 	sign;
	int 	dif_x;
	int 	dif_y;
	int		check;

	y0 = Y0;
	x0 = X0;
	y1 = Y1;
	x1 = X1;
	dif_x = fabs(x0 - x1);
	dif_y = fabs(y0 - y1);
	delta = ((double)dif_y) / ((double)dif_x);
	sign = (x1 > x0 ? 1 : -1);
	delta *= (y1 > y0 ? 1 : -1);
	check = 0;
	while (floor(x0) != floor(x1))
	{
		mlx_pixel_put(MLX, WND, x0, (int)(y0), ft_grad(prev.col, dif_x, params, check));
		x0 += sign;
		y0 += delta;
		check = 1;
	}
	return (0);
}

static int		ft_finnish_y(t_params params, t_mlx *data, t_params_prev prev)
{
	double 	delta;
	double 	x0;
	double	y0;
	double	x1;
	double	y1;
	int 	sign;
	int 	dif_x;
	int 	dif_y;
	int		check;

	y0 = Y0;
	x0 = X0;
	y1 = Y1;
	x1 = X1;
	dif_x = fabs(x0 - x1);
	dif_y = fabs(y0 - y1);
	delta = ((double)dif_x) / ((double)dif_y);
	sign = (y1 > y0 ? 1 : -1);
	delta *= (x1 > x0 ? 1 : -1);
	check = 0;
	while (floor(y0) != floor(y1))
	{
		mlx_pixel_put(MLX, WND, (int)(x0), y0, ft_grad(prev.col, dif_y, params, check));
		y0 += sign;
		x0 += delta;
		check = 1;
	}
	return (0);
}

void	ft_print_line(t_params params, t_params_prev prev, t_mlx *data)
{
	// printf("change_x_prev: %f\n", params_prev.change.x + params_prev.x);
	// printf("x_start :%f\n",X0);
	// printf("x_fin :%f\n",X1);
	// printf("y_start :%f\n", Y0);
	// printf("y_fin :%f\n", Y1);
	if (abs((int)(X1 - X0)) >= abs((int)(Y1 - Y0)))
		ft_finnish_x(params, data, prev);
	else
		ft_finnish_y(params, data, prev);
}

int	ft_make_line(int keycode, void *structure)
{
	static int				y_move;
	static int				x_move;
	static t_params_prev	prev;
	t_mlx					*data;
 

	data = (t_mlx *)structure;
	mlx_clear_window(MLX, WND);
	ft_change(data, keycode);
	while (PARAMS[y_move])
	{
		while (!PARAMS[y_move][x_move].end)
		{
			prev.x = PARAMS[y_move][x_move].x;
			prev.y = PARAMS[y_move][x_move].y;
			prev.z = PARAMS[y_move][x_move].z;
			prev.col = PARAMS[y_move][x_move].col;
			prev.change = PARAMS[y_move][x_move].change;
			if (PARAMS[y_move][x_move + 1].end && PARAMS[y_move + 1])
				ft_print_line(PARAMS[y_move + 1][x_move], prev, data);
			x_move++;
			if (PARAMS[y_move][x_move].end)
				break;
			ft_print_line(PARAMS[y_move][x_move], prev, data);
			if (PARAMS[y_move + 1])
				ft_print_line(PARAMS[y_move + 1][x_move - 1], prev, data);
		}
		y_move++;
		if (!PARAMS[y_move])
			break;
		x_move = 0;
	}
	mlx_pixel_put(MLX, WND, X0, Y0, ft_grad(PARAMS[y_move - 1][x_move - 1].col, 1, PARAMS[y_move - 1][x_move - 1], 0));
	y_move = 0;
	x_move = 0;
	return (0);
}
