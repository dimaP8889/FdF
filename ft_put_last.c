/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:21:51 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/09 18:21:51 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define X0_AC	(int)(X0 + 0.0000001)
#define Y0_AC	(int)(Y0 + 0.0000001)
#define COOR_L	PARAMS[y_mv - 1][x_mv - 1]
#define GRAD_L	ft_grad(COOR_L.col, 1, COOR_L, 0)
#define MV_Y	prev->change.centre + data->move.y
#define MV_X	prev->change.centre + data->move.x
#define X0		(prev->change.zm * (prev->change.x + prev->x) + MV_X)
#define Y0 		(prev->change.zm * (prev->change.y + prev->y) + MV_Y)
#define MLX 	data->mlx
#define WND 	data->wnd
#define PARAMS 	data->param

#include "fdf.h"

void	ft_put_last(t_mlx *data, t_p *prev, int y_mv, int x_mv)
{
	mlx_pixel_put(MLX, WND, X0_AC, Y0_AC, GRAD_L);
}
