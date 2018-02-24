/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:00:01 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/24 18:00:02 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void	ft_make_coord(char **params, t_params *struct_params, int z)
{
	int 	x;

	x = 0;
	while (params)
	{
		struct_params->x = x;
		struct_params->z = z;
		// struct_params->y = ft_make_coord(params*);
		// struct_params->col = ft_make_col(params*);
	}
}

t_params	*ft_parse(int fd)
{
	int 		gnl_ret;
	int			z;
	char		*line;
	char		**params;
	t_params	*struct_params;

	gnl_ret = 1;
	z = 0;
	struct_params = (t_params *)malloc(sizeof(t_params));
	while (gnl_ret)
	{
		gnl_ret = get_next_line(fd, &line);
		params = ft_strsplit(line, ' ');
		ft_make_coord(params, struct_params, z);
		z += 20;
	}
	return (NULL);
}