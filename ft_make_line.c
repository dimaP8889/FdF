/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:43:43 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/09 01:16:48 by dmitriy1         ###   ########.fr       */
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

static int		ft_finnish_x(t_params params, t_mlx *data, t_params prev)
{
	double 	delta;
	double 	y0;
	double	x0;
	int 	sign;
	int		check;

	y0 = Y0;
	x0 = X0;
	delta = ((double)fabs(y0 - Y1)) / ((double)fabs(x0 - X1));
	sign = (X1 > x0 ? 1 : -1);
	delta *= (Y1 > y0 ? 1 : -1);
	check = 0;
	while ((int)(x0 + 0.0000001) != (int)(X1 + 0.0000001))
	{
		mlx_pixel_put(MLX, WND, (int)(x0 + 0.0000001), (int)(y0 + 0.0000001), ft_grad(prev.col, fabs(x0 - X1), params, check));
		x0 += sign;
		y0 += delta;
		check = 1;
	}
	return (0);
}

static int		ft_finnish_y(t_params params, t_mlx *data, t_params prev)
{
	double 	delta;
	double 	x0;
	double	y0;
	int 	sign;
	int		check;

	y0 = Y0;
	x0 = X0;
	delta = ((double)fabs(x0 - X1)) / ((double)fabs(y0 - Y1));
	sign = (Y1 > y0 ? 1 : -1);
	delta *= (X1 > x0 ? 1 : -1);
	check = 0;
	while ((int)(y0 + 0.0000001) != (int)(Y1 + 0.0000001))
	{
		mlx_pixel_put(MLX, WND, (int)(x0 + 0.0000001), (int)(y0 + 0.0000001), ft_grad(prev.col, fabs(y0 - Y1), params, check));
		y0 += sign;
		x0 += delta;
		check = 1;
	}
	return (0);
}

void	free_data(t_mlx *data)
{
	int		y;

	y = 0;
	while (PARAMS[y])
	{
		free(PARAMS[y]);
		y++;
	}
	free(PARAMS);
}

void	ft_print_line(t_params params, t_params prev, t_mlx *data)
{
	if (abs((int)(X1 - X0)) >= abs((int)(Y1 - Y0)))
		ft_finnish_x(params, data, prev);
	else
		ft_finnish_y(params, data, prev);
}

int	ft_make_line(int keycode, void *structure)
{
	static int				y_move;
	static int				x_move;
	static t_params			prev;
	t_mlx					*data;
	int							y;
 

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
	mlx_pixel_put(MLX, WND, (int)(X0 + 0.0000001), (int)(Y0 + 0.0000001), ft_grad(PARAMS[y_move - 1][x_move - 1].col, 1, PARAMS[y_move - 1][x_move - 1], 0));
	y = 0;
	y_move = 0;
	x_move = 0;
	return (0);
}
