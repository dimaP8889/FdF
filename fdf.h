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
# include <fcntl.h>
# include "mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct 	s_params
{
	int 			x;
	int 			y;
	int 			z;
	int				col;
	struct t_params	*next;
}				t_params;

typedef struct 	s_mlx
{
	void			*mlx;
	void			*wnd;
	int				check;
	int 			x;
	int 			y;
	int 			z;
	int				col;
	struct t_params	*params;
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

int 			ft_grad(int fin_col, int moves, t_mlx *data);
int				ft_make_line(int button, int x, int y, void *d);
t_params		*ft_parse(int fd);
int				ft_atoi_base(const char *str1, int base);

#endif