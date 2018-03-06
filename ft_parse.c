/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:43:12 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/05 20:10:16 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_make_params(t_params *struct_params, char *str, char *find)
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
	struct_params->z = ft_atoi_base(num, 10);
	struct_params->col = ft_atoi_base(col, 16);
	free(num);
	free(col);
}

t_params 	*ft_make_coord(char **params, t_params *struct_params, int y, int center)
{
	int 	x;
	int		move;
	int		count;
	char	*find_c;

	move = 0;
	x =  -center;
	count = 0;
	if (!params[move])
	{
		ft_printf("wrong input");
		exit(1);
	}
	while (params[move])
	{
		find_c = ft_strchr(params[move], ',');
		struct_params[count].x = x;
		struct_params[count].y = y;
		struct_params[count].end = 0;
		if (!find_c)
		{
			struct_params[count].z = ft_atoi_base(params[move], 10);
			struct_params[count].col = 0xFFFFFF;
			free(find_c);
		}
		else
		{
			ft_make_params(&struct_params[count], params[move], find_c);
		}
		x += 1;
		count++;
		move++;
		if (struct_params->col > 16777215)
		{
			ft_printf("wrong input");
			exit(1);
		}
	}
	struct_params[count].end = 1;
	return (struct_params);
}

void	ft_free_struct(char **params)
{
	int count;

	count = 0;
	while (params[count])
	{
		free(params[count]);
		count++;
	}
	free(params);
}


t_params	**ft_parse(int fd, t_sizes sizes)
{
	int			counter;
	int			y;
	static char		*line;
	static char		**params;
	int			c;
	static t_params	**struct_params;

	counter = 0;
	y = -sizes.y / 2;
	c = sizes.y;
	struct_params = (t_params **)malloc(sizeof(t_params *) * (sizes.y + 1));
	while (c > 0)
	{
		get_next_line(fd, &line);
		params = ft_strsplit(line, ' ');
		free(line);
		struct_params[counter] = (t_params *)malloc(sizeof(t_params) * (sizes.x + 1));
		struct_params[counter] = ft_make_coord(params, struct_params[counter], y, sizes.x / 2);
		ft_free_struct(params);
		counter++;
		c--;
		y += 1;
	}
	struct_params[counter] = NULL;
	return (struct_params);
}