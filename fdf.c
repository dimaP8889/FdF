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

int 	main(int ac, char **av)
{
	ac = 0;
	t_mlx		data;
	//t_params	*params;
	int count;
	int fd;
	char *str;

	str = "0XAA";
	count = 0;
	data.mlx = mlx_init();
	data.wnd = mlx_new_window(data.mlx, 1000, 1000, "mlx 42");
	fd = open(av[1], O_RDONLY);
	printf("%i\n", ft_atoi_base(str, 16)); 
	//ft_parse(fd);
	//mlx_mouse_hook(data.wnd, ft_make_line, &data);
	//mlx_loop(data.mlx);
	return (0);
}
