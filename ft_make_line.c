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

#define MV_Y	prev->change.centre + data->move.y
#define MV_X	prev->change.centre + data->move.x
#define X0		(prev->change.zm * (prev->change.x + prev->x) + MV_X)
#define Y0 		(prev->change.zm * (prev->change.y + prev->y) + MV_Y)
#define X1 		(param.change.zm * (param.change.x + param.x) + MV_X)
#define Y1 		(param.change.zm * (param.change.y + param.y) + MV_Y)
#define X0_AC	(int)(X0 + 0.0000001)
#define Y0_AC	(int)(Y0 + 0.0000001)
#define X1_AC	(int)(X1 + 0.0000001)
#define Y1_AC	(int)(Y1 + 0.0000001)
#define S_X0_AC	(int)(x0 + 0.0000001)
#define S_Y0_AC	(int)(y0 + 0.0000001)
#define S_X1_AC	(int)(x1 + 0.0000001)
#define S_Y1_AC	(int)(y1 + 0.0000001)
#define COOR_L	PARAMS[y_move - 1][x_move - 1]
#define GRAD_L	ft_grad(COOR_L.col, 1, COOR_L, 0)
#define GRAD_X	ft_grad(prev->col, fabs(x0 - X1), param, check)
#define GRAD_Y	ft_grad(prev->col, fabs(y0 - Y1), param, check)
#define PARAMS 	data->param
#define MLX 	data->mlx
#define WND 	data->wnd

#include "fdf.h"

static int		ft_finnish_x(t_p param, t_mlx *data, t_p *prev)
{
	double	delta;
	double	y0;
	double	x0;
	int		sign;
	int		check;

	y0 = Y0;
	x0 = X0;
	delta = ((double)fabs(y0 - Y1)) / ((double)fabs(x0 - X1));
	sign = (X1 > x0 ? 1 : -1);
	delta *= (Y1 > y0 ? 1 : -1);
	check = 0;
	while (S_X0_AC != X1_AC)
	{
		mlx_pixel_put(MLX, WND, S_X0_AC, S_Y0_AC, GRAD_X);
		x0 += sign;
		y0 += delta;
		check = 1;
	}
	return (0);
}

static int		ft_finnish_y(t_p param, t_mlx *data, t_p *prev)
{
	double	delta;
	double	x0;
	double	y0;
	int		sign;
	int		check;

	y0 = Y0;
	x0 = X0;
	delta = ((double)fabs(x0 - X1)) / ((double)fabs(y0 - Y1));
	sign = (Y1 > y0 ? 1 : -1);
	delta *= (X1 > x0 ? 1 : -1);
	check = 0;
	while (S_Y0_AC != Y1_AC)
	{
		mlx_pixel_put(MLX, WND, S_X0_AC, S_Y0_AC, GRAD_Y);
		y0 += sign;
		x0 += delta;
		check = 1;
	}
	return (0);
}

void			ft_print_line(t_p param, t_p *prev, t_mlx *data)
{
	if (abs((int)(X1 - X0)) >= abs((int)(Y1 - Y0)))
		ft_finnish_x(param, data, prev);
	else
		ft_finnish_y(param, data, prev);
}

int				ft_print(t_p *prev, t_mlx *data, int *x_move, int y_move)
{
	prev->x = PARAMS[y_move][*x_move].x;
	prev->y = PARAMS[y_move][*x_move].y;
	prev->z = PARAMS[y_move][*x_move].z;
	prev->col = PARAMS[y_move][*x_move].col;
	prev->change = PARAMS[y_move][*x_move].change;
	if (PARAMS[y_move][*x_move + 1].end && PARAMS[y_move + 1])
		ft_print_line(PARAMS[y_move + 1][*x_move], prev, data);
	(*x_move)++;
	if (PARAMS[y_move][*x_move].end)
		return (0);
	ft_print_line(PARAMS[y_move][*x_move], prev, data);
	if (PARAMS[y_move + 1])
		ft_print_line(PARAMS[y_move + 1][*x_move - 1], prev, data);
	return (1);
}

int				ft_make_line(int keycode, void *structure)
{
	static int				y_move;
	static int				x_move;
	static t_p				prev;
	t_mlx					*data;
	int						y;

	data = (t_mlx *)structure;
	mlx_clear_window(MLX, WND);
	ft_c(data, keycode);
	while (PARAMS[y_move])
	{
		while (!PARAMS[y_move][x_move].end)
			if (!ft_print(&prev, data, &x_move, y_move))
				break ;
		y_move++;
		if (!PARAMS[y_move])
			break ;
		x_move = 0;
	}
	ft_put_last(data, &prev, y_move, x_move);
	y = 0;
	y_move = 0;
	x_move = 0;
	return (0);
}
