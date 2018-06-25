/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_col_z.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:51:12 by dmitriy1          #+#    #+#             */
/*   Updated: 2018/03/10 14:42:41 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

static void		ft_change_col(t_p **struct_p, int x, int y, t_sizes sz)
{
	if (struct_p[y][x].z == sz.max_z && struct_p[y][x].z != sz.min_z)
		struct_p[y][x].col = 0xFF0000;
	else if (struct_p[y][x].z != sz.min_z)
		struct_p[y][x].col = 0x0000FF;
	if (struct_p[y][x].z == 0)
		struct_p[y][x].col = 0xFFFFFF;
	if (x > 0 && struct_p[y][x - 1].z > struct_p[y][x].z)
		struct_p[y][x].col = 0x00FF00;
	if (y > 0 && struct_p[y - 1][x].z > struct_p[y][x].z)
		struct_p[y][x].col = 0x00FF00;
	if (x > 0 && struct_p[y][x - 1].z < struct_p[y][x].z)
		struct_p[y][x - 1].col = 0x00FF00;
	if (y > 0 && struct_p[y - 1][x].z < struct_p[y][x].z)
		struct_p[y - 1][x].col = 0x00FF00;
}

t_p				**ft_make_col_z(t_p **struct_p, t_sizes sz)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (struct_p[y])
	{
		while (!struct_p[y][x].end)
		{
			if (struct_p[y][x].col == 0xFFFFFF)
				ft_change_col(struct_p, x, y, sz);
			x++;
		}
		x = 0;
		y++;
	}
	return (struct_p);
}
