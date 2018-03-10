/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:13:34 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/10 15:06:47 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void			ft_wrong_input(void)
{
	ft_printf("wrong input");
	exit(1);
}

static void		ft_check_param(char *str, t_sizes *sizes)
{
	int		max_z;
	int		min_z;

	max_z = 0;
	min_z = 0;
	max_z = ft_atoi_base(str, 10);
	min_z = max_z;
	if (max_z > sizes->max_z)
		sizes->max_z = max_z;
	if (min_z < sizes->min_z)
		sizes->min_z = min_z;
	(sizes->x)++;
}

static int		ft_read(char **str, t_sizes *sizes, int check)
{
	static char		**param;
	int				move;
	char			*line;

	move = 0;
	line = *str;
	param = ft_strsplit(line, ' ');
	free(line);
	while (param[move])
	{
		ft_check_param(param[move], sizes);
		free(param[move]);
		move++;
	}
	if ((check != sizes->x && check))
		ft_wrong_input();
	check = sizes->x;
	sizes->y++;
	sizes->x = 0;
	free(param);
	return (check);
}

static t_sizes	ft_find_size(int fd, t_sizes sizes)
{
	static	char	*line;
	int				check;

	check = 0;
	while (get_next_line(fd, &line))
		check = ft_read(&line, &sizes, check);
	if (!check || !sizes.y)
		ft_wrong_input();
	sizes.x = check;
	sizes.dif_z = sizes.max_z - sizes.min_z;
	return (sizes);
}

int				main(int ac, char **av)
{
	static t_mlx	data;
	static t_sizes	sizes;
	int				fd;

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
	data.param = ft_parse(fd, data.sizes);
	close(fd);
	ft_first_pic(&data);
	mlx_hook (data.wnd, 2, 5, ft_make_line,  &data);
	mlx_loop(data.mlx);
	return (0);
}
