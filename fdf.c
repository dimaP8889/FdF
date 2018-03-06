/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:13:34 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/05 19:57:10 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// почистить лики сделать доставалку след цвета ./ft_make_line 

#include "fdf.h"

t_sizes 	ft_find_size(int fd, t_sizes sizes)
{
	static 	char	*line;
	static	char	**params;
	int 	check;
	int 	max_z;
	int 	move;

	max_z = 0;
	check = 0;
	move = 0;
	while (get_next_line(fd, &line))
	{
		params = ft_strsplit(line, ' ');
		free(line);
		while (params[move])
		{
			max_z = ft_atoi_base(params[move], 10);
			if (max_z > sizes.z)
				sizes.z = max_z;
			(sizes.x)++;
			free(params[move]);
			move++;
		}
		move = 0;
		if (check != sizes.x && check)
		{
			ft_printf("wrong input");
			exit(1);
		}
		check = sizes.x;
		sizes.y++;
		sizes.x = 0;
		free(params);
	}
	sizes.x = check;
	if (!sizes.x || !sizes.y)
	{
		ft_printf("wrong input");
		exit(1);
	}
	return (sizes);
}

void	free_params(t_params ***params)
{
	int y;

	y = 0;
	while (*params[y])
	{
		free(*params[y]);
		y++;
	}
	free(*params);
}

int 	main(int ac, char **av)
{
	static t_mlx	data;
	static t_sizes	sizes;
	int fd;

	if (ac != 2)
	{
		ft_printf("wrong input");
		exit(1);
		return (0);
	}
	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, 1000, 1000, "mlx 42");
	fd = open(av[1], O_RDONLY);
	data.sizes = ft_find_size(fd, sizes);
	close(fd);
	fd = open(av[1], O_RDONLY);
	data.params = ft_parse(fd, data.sizes);
	close(fd);
	ft_make_line(0, &data);
	mlx_key_hook(data.wnd, ft_make_line, &data);
	mlx_loop(data.mlx);
	return (0);
}
