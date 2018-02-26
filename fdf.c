/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:13:34 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/26 23:30:28 by dpogrebn         ###   ########.fr       */
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

//надо фришить структуры

int 	main(int ac, char **av)
{
	ac = 0;
	static t_mlx	data;
	static t_sizes	sizes;
	int fd;

	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, 2000, 1000, "mlx 42");
	fd = open(av[1], O_RDONLY);
	ft_find_size(fd, &sizes);
	close(fd);
	fd = open(av[1], O_RDONLY);
	data.params = ft_parse(fd, sizes);
	close(fd);
	ft_make_line(data.params, data);
	//ft_rotate(data);
	//free_struct(&data);
	//mlx_mouse_hook(data.wnd, ft_make_line, &data);
	mlx_loop(data.mlx);
	return (0);
}
