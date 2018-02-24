/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:36:48 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/22 14:36:50 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"

// typedef struct s_mlx_params
// {
// 	void		*mlx;
// 	void		*wnd;
// 	int 		x;
// 	int 		y;
// }				s_mlx_params;

typedef struct 	s_mlx
{
	void		*mlx;
	void		*wnd;
	int 		x;
	int 		y;
	int			col;
	int			check;
}				t_mlx;

typedef struct 	s_grad
{
	int			r_start;
	int			g_start;
	int			b_start;
	int			r_to;
	int			g_to;
	int			b_to;
	double		r_delta;
	double		g_delta;
	double		b_delta;
}				t_grad;
#endif