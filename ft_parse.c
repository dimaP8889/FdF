/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:43:12 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/09 16:24:21 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_make_param(t_p *struct_p, char *str, char *find)
{
	char	*num;
	char	*col;
	int		count;

	count = -1;
	find++;
	col = ft_strdup(find);
	num = ft_strnew(find - str);
	while (str[++count] != ',')
		num[count] = str[count];
	num[count] = 0;
	struct_p->z = ft_atoi_base(num, 10);
	struct_p->col = ft_atoi_base(col, 16);
	free(num);
	free(col);
}

static char	*ft_find_c(char *param, t_p *struct_p, int x, int y)
{
	char *find_c;

	find_c = ft_strchr(param, ',');
	struct_p->x = x;
	struct_p->y = y;
	struct_p->end = 0;
	if (!find_c)
		struct_p->z = ft_atoi_base(param, 10);
	return (find_c);
}

static void	ft_not_find_c(t_p **struct_p, int count, char **find_c, t_sizes sz)
{
	static double	prev;
	static int	check;

	// struct_p->z = ft_atoi_base(param, 10);
	if (struct_p[count]->z == sz.min_z)
		struct_p[count]->col = 0xFFFFFF;
	else if (struct_p[count]->z == sz.max_z)
		struct_p[count]->col = 0xFF0000;
	else if (struct_p[count]->z == sz.mid_z + 1 || struct_p[count]->z == sz.mid_z - 1
	|| struct_p[count]->z == sz.mid_z)
		struct_p[count]->col = 0x0000FF;
	if (check && prev > struct_p[count]->z)
	{
		ft_printf("test\n");
		struct_p[count]->col = 0xFFFF00;
		ft_printf("test1\n");
	}
	else if (check && struct_p[count - 1]->z > struct_p[count]->z)
		struct_p[count - 1]->col = 0xFFFF00;
	check = 1;
	prev = struct_p[count]->z;
	free(*find_c);
}

static t_p	*ft_make_coord(char **param, t_p *struct_p, int y, t_sizes sizes)
{
	int		x;
	int		move;
	int		count;
	char	*find_c;

	move = 0;
	x = -sizes.x / 2;
	count = 0;
	if (!param[move])
		ft_wrong_input();
	while (param[move])
	{
		find_c = ft_find_c(param[move], &struct_p[count], x, y);
		if (!find_c)
			ft_not_find_c(&struct_p, count, &find_c, sizes);
		else
			ft_make_param(&struct_p[count], param[move], find_c);
		x += 1;
		count++;
		move++;
		if (struct_p->col > 16777215)
			ft_wrong_input();
	}
	struct_p[count].end = 1;
	return (struct_p);
}

t_p		**ft_parse(int fd, t_sizes sizes)
{
	int				coun;
	int				y;
	static char		*line;
	static char		**param;
	static t_p		**struct_p;

	coun = 0;
	y = -sizes.y / 2;
	struct_p = (t_p **)malloc(sizeof(t_p *) * (sizes.y + 1));
	while (coun < sizes.y)
	{
		get_next_line(fd, &line);
		param = ft_strsplit(line, ' ');
		free(line);
		struct_p[coun] = (t_p *)malloc(sizeof(t_p) * (sizes.x + 1));
		struct_p[coun] = ft_make_coord(param, struct_p[coun], y, sizes);
		ft_free_struct(param);
		coun++;
		y += 1;
	}
	struct_p[coun] = NULL;
	return (struct_p);
}
