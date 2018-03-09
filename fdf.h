/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:36:48 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/08 19:24:49 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct	s_sizes
{
	int			x;
	int			y;
	int			max_z;
	int			min_z;
	int			mid_z;
}				t_sizes;

typedef struct	s_change
{
	double		x;
	double		y;
	double		z;
	double		zm;
	int			angle;
	int			way;
	int			centre;
}				t_c;

typedef struct	s_param
{
	double		x;
	double		y;
	double		z;
	int			end;
	int			col;
	t_c			change;
}				t_p;

typedef struct	s_mlx
{
	void		*mlx;
	void		*wnd;
	void		*img;
	t_p			move;
	t_sizes		sizes;
	t_p			**param;
}				t_mlx;

typedef struct	s_grad
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

int				ft_grad(int start_col, int moves, t_p data, int check);
int				ft_draw(int button, int x, int y, void *d);
t_p				**ft_parse(int fd, t_sizes sizes);
int				ft_atoi_base(const char *str1, int base);
int				ft_make_line(int keycode, void *structure);
void			ft_c(t_mlx *data, int keycode);
void			ft_make_central(t_p **param);
void			ft_free_param(char	***param);
void			ft_first_pic(t_mlx *data);
void			ft_wrong_input(void);
void			ft_put_last(t_mlx *data, t_p *prev, int y_mv, int x_mv);
int				ft_set_and_fir(t_p *param, t_c *change, t_p start, t_c *check);
void			ft_rotate_y(t_p *param, t_c *change, t_p start, t_c *check);
void			ft_rotate_x(t_p *param, t_c *change, t_p start, t_c *check);
void			ft_rotate_z(t_p *param, t_c *change, t_p start, t_c *check);
t_p				**ft_last_cut(t_c *chg, int kd, t_mlx *data, t_p **pv);
void			ft_free_struct(char **param);

#endif
