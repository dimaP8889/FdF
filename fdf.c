/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:13:34 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/21 16:18:29 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	ft_find_size(int fd)
{
	char 	line[1000];
	char	*find;
	char	*find_copy;
	int 	size;

	size = 0;
	while (read(fd, line, 1000))
	{
		find = ft_strchr(line, '\n');
		find_copy = line;
		while (find)
		{
			find += find - find_copy;
			find_copy = find;
			size++;
			find = ft_strchr(find, '\n');
		}
	}
	return (size);
}

//надо фришить структуры

int 	main(int ac, char **av)
{
	ac = 0;
	t_mlx		data;
	int size;
	int y;
	int x;
	int fd;

	x = 0;
	y = 0;
	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, 1000, 1000, "mlx 42");
	fd = open(av[1], O_RDONLY);
	size = ft_find_size(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	data.params = ft_parse(fd, size);
	while (data.params[y])
	{
		while (!data.params[y][x].end)
		{
			printf("%#x\n", data.params[y][x].col);
			x++;
		}
		x = 0;
		y++;
	}
	close(fd);
	ft_make_line(data.params, data);
	//mlx_mouse_hook(data.wnd, ft_make_line, &data);
	mlx_loop(data.mlx);
	return (0);
}
