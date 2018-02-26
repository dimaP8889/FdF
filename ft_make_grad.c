/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_grad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:40:06 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/26 23:15:58 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int 	ft_make_col(int b_start, int r_start, int g_start)
{
	int ret;
	
	g_start <<= 8;
	r_start <<= 16;
	ret = r_start | g_start | b_start;
	return (ret);
}

static t_grad	*ft_find_delta(t_params *data, int moves, int start_col)
{
	static t_grad *grad;

	grad = (t_grad *)malloc(sizeof(t_grad));
	grad->b_to = (data->col) & 255;
	grad->g_to = (data->col) >> 8;
	grad->g_to &= 255;
	grad->r_to = (data->col) >> 16;
	grad->b_start = start_col & 255;
	grad->g_start = start_col >> 8;
	grad->g_start = grad->g_start & 255;
	grad->r_start = start_col >> 16;
	grad->r_delta = (((double)grad->r_to) - ((double)grad->r_start)) / (double)moves;
	grad->g_delta = (((double)grad->g_to) - ((double)grad->g_start)) / (double)moves;
	grad->b_delta = (((double)grad->b_to) - ((double)grad->b_start)) / (double)moves;
	return (grad);
}

int 	ft_grad(int start_col, int moves, t_params *data)
{
	static t_grad 		*grad;
	static double 		r;
	static double		g;
	static double		b;
	static int 			i;

	if (!i)
	{
		// if (data->col != 0xffffff)
		// {
		// 	printf("num :%i\n", data->y);
		// 	printf("col :%#x\n", data->col);
		// 	printf("\n");
		// }
		grad = ft_find_delta(data, moves, start_col);
		r = grad->r_start;
		g = grad->g_start;
		b = grad->b_start;
		i++;
	}
	b += grad->b_delta;
	r += grad->r_delta;
	g += grad->g_delta;
	
	if (moves == 1)
		i = 0;
	data->col = ft_make_col((int)b, (int)r, (int)g);
	return (data->col);
}