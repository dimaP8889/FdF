/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_grad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:40:06 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/24 17:40:06 by dpogrebn         ###   ########.fr       */
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

static t_grad	*ft_find_delta(t_params *data, int moves, int fin_col)
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
	return (grad);
}

int 	ft_grad(int fin_col, int moves, t_params *data)
{
	t_grad 	*grad;
	static 	double 		r;
	static 	double		g;
	static 	double		b;
	static int i;

	grad = (t_grad*)malloc(sizeof(t_grad));	
	if (!i)
	{
		grad = ft_find_delta(data, moves, fin_col);
		r = grad->r_start;
		g = grad->g_start;
		b = grad->b_start;
		i++;
	}
	// printf("r: %#x\n", data->col);
	b -= grad->b_delta;
	r -= grad->r_delta;
	g -= grad->g_delta;

	data->col = ft_make_col((int)b, (int)r, (int)g);
	return (data->col);
}