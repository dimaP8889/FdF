/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:13:34 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/28 02:30:52 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// почистить лики сделать доставалку след цвета ./ft_make_line 

#include "fdf.h"

void 	ft_find_size(int fd, t_sizes *sizes)
{
	char	*line;
	char	**params;
	int 	check;
	int 	max_y;

	max_y = 0;
	while (get_next_line(fd, &line))
	{
		params = ft_strsplit(line, ' ');
		while (*params)
		{
			max_y = ft_atoi_base(*params, 10);
			if (max_y > sizes->y)
				sizes->y = max_y;
			(sizes->x)++;
			params++;
		}

		if (sizes->z && sizes->x != check)
		{
			ft_printf("wrong input\n");
			exit(1);
		}
		check = sizes->x;
		sizes->z++;
		sizes->x = 0;
	}
	sizes->x = check;
}

void	ft_print_params(t_params **params)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (params[y])
	{
		while (!params[y][x].end)
		{
			printf("x :%i\n", params[y][x].x);
			printf("y :%i\n", params[y][x].y);
			printf("z :%i\n", params[y][x].z);
			x++;
		}
		x = 0;
		y++;
	}
}

//надо фришить структуры

// x = (1000 - (sizes.x - 1) * 30) / 2;
// y = (1000 - sizes.y) / 2;


// int lol(int keycode, void *params)
// {
// 	t_mlx *data;

// 	data = (t_mlx *)params;
// 	if (keycode == 125 || keycode == 126)
// 		printf("lol1\n");
// 	return (0);
// }

// int lol1(void *params)
// {
// 	t_mlx *data;

// 	data = (t_mlx *)params;

// 	mlx_key_hook(data->wnd, ft_rotate, data);
// 	return 0;
// }

int 	main(int ac, char **av)
{
	ac = 0;
	static t_mlx	data;
	static t_sizes	sizes;
	int fd;

	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, 1000, 1000, "mlx 42");
	fd = open(av[1], O_RDONLY);
	ft_find_size(fd, &sizes);
	close(fd);
	fd = open(av[1], O_RDONLY);
	data.params = ft_parse(fd, sizes);
	close(fd);

	//ft_make_central(&data.params);
	ft_make_line(data.params, data);
	//mlx_clear_window(data.mlx, data.wnd);
	// mlx_expose_hook(data.wnd, lol1, &data);
	mlx_key_hook(data.wnd, ft_rotate, &data);
	//mlx_clear_window(data.mlx, data.wnd);
	// ft_make_line(data.params, data);
	//free_struct(&data);
	//mlx_mouse_hook(data.wnd, ft_make_line, &data);
	mlx_loop(data.mlx);
	return (0);
}
