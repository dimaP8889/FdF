/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:51:21 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/02/28 17:54:57 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_count_coord(t_params* params, double matrix[3][3])
{
	double	y;
	double	x;
	double	z;

	// printf("0 0 :%i\n", matrix[0][0]);
	// printf("0 1 :%i\n", matrix[0][1]);
	// printf("0 2 :%i\n", matrix[0][2]);
	// printf("1 0 :%i\n", matrix[1][0]);
	// printf("1 1 :%i\n", matrix[1][1]);
	// printf("1 2 :%i\n", matrix[1][2]);
	// printf("2 0 :%i\n", matrix[2][0]);
	// printf("2 1 :%i\n", matrix[2][1]);
	// printf("2 2 :%i\n", matrix[2][2]);
	y = params->y;
	x = params->x;
	z = params->z;
	// printf("%f\n", x);
	// printf("%f\n", y);
	// printf("%f\n", z);
	params->x = (x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2]);
	params->y = (x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2]);
	params->z = (x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2]);
}

t_params	**ft_rotate_y(t_params** params, int way)
{
	int 			x;
	int				y;
	double			matrix[3][3];

	matrix[0][0] = cos((double)(10 * way / (double)(180 / M_PI)));
	matrix[0][1] = 0;
	matrix[0][2] = -sin((double)(10 * way / (double)(180 / M_PI)));// * way;
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0; //* way;
	matrix[2][0] = sin((double)(10 * way / (double)(180 / M_PI))); //* way;
	matrix[2][1] = 0; //* way;
	matrix[2][2] = cos((double)(10 * way / (double)(180 / M_PI)));
	x = 0;
	y = 0;
	
	while (params[y])
	{
		while (!params[y][x].end)
		{
			ft_count_coord(&params[y][x], matrix);
			x++;
		}
		x = 0;
		y++;
	}
	// ft_print_params(params);
	// printf("\n");
	return (params);
}

t_params	**ft_rotate_x(t_params** params, int way)
{
	int 			x;
	int				y;
	double			matrix[3][3];

	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos((double)(10 * way / (double)(180 / M_PI)));
	matrix[1][2] = sin((double)(10 * way / (double)(180 / M_PI))); //* way;
	matrix[2][0] = 0;
	matrix[2][1] = -sin((double)(10 * way / (double)(180 / M_PI))); //* way;
	matrix[2][2] = cos((double)(10 * way / (double)(180 / M_PI)));
	x = 0;
	y = 0;
	
	while (params[y])
	{
		while (!params[y][x].end)
		{
			ft_count_coord(&params[y][x], matrix);
			x++;
		}
		x = 0;
		y++;
	}
	// ft_print_params(params);
	// printf("\n");
	return (params);
}


int		ft_rotate(int keycode, void *params)
{
	t_mlx 		*data;

	data = (t_mlx *)params;
	if (keycode == 126 || keycode == 125)
		data->params = ft_rotate_x(data->params, keycode == 126 ? -1 : 1);
	if (keycode == 123 || keycode == 124)
		data->params = ft_rotate_y(data->params, keycode == 124 ? -1 : 1);
	//ft_make_central(data->params);
	mlx_clear_window(data->mlx, data->wnd);
	ft_make_line(data->params, *data);
	return (0);
}
