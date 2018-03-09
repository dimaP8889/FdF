/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:13:34 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/08 13:18:00 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	ft_wrong_input(void)
{
	ft_printf("wrong input");
	exit(1);
}

void	ft_check_params(char *str, t_sizes *sizes)
{
	int 	max_z;

	max_z = 0;
	max_z = ft_atoi_base(str, 10);
	if (max_z > sizes->z)
		sizes->z = max_z;
	(sizes->x)++;
}

int	ft_read(char **str, t_sizes *sizes)
{
	static	char	**params;
	int 		move;
	int 	check;
	char	*line;

	check = 0;
	move = 0;
	line = *str;
	params = ft_strsplit(line, ' ');
	free(line);
	while (params[move])
	{
		ft_check_params(params[move], sizes);
		free(params[move]);
		move++;
	}
	if ((check != sizes->x && check))
		ft_wrong_input();
	check = sizes->x;
	sizes->y++;
	sizes->x = 0;
	free(params);
	return (check);
}


t_sizes 	ft_find_size(int fd, t_sizes sizes)
{
	static 	char	*line;
	int 			check;

	while (get_next_line(fd, &line))
		check = ft_read(&line, &sizes);
	if (!check || !sizes.y)
		ft_wrong_input();
	sizes.x = check;
	return (sizes);
}

int 	main(int ac, char **av)
{
	static t_mlx	data;
	static t_sizes	sizes;
	int fd;

	if (ac != 2)
	{
		ft_wrong_input();
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
	ft_first_pic(&data);
	mlx_key_hook(data.wnd, ft_make_line, &data);
	mlx_loop(data.mlx);
	return (0);
}
