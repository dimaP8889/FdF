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

char		*ft_find_c(char *params, t_params *struct_params, int x, int y)
{
	char *find_c;

	find_c = ft_strchr(params, ',');
	struct_params->x = x;
	struct_params->y = y;
	struct_params->end = 0;
	return (find_c);
}

void		ft_not_find_c(t_params *struct_params, char *params, char **find_c)
{
	struct_params->z = ft_atoi_base(params, 10);
	struct_params->col = 0xFFFFFF;
	free(*find_c);
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
		ft_wrong_input();
	while (params[move])
	{
		find_c = ft_find_c(params[move], &struct_params[count], x, y);
		if (!find_c)
			ft_not_find_c(&struct_params[count], params[move], &find_c);
		else
			ft_make_params(&struct_params[count], params[move], find_c);
		x += 1;
		count++;
		move++;
		if (struct_params->col > 16777215)
			ft_wrong_input();
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
	int				counter;
	int				y;
	static char		*line;
	static char		**params;
	static t_params	**struct_params;

	counter = 0;
	y = -sizes.y / 2;
	struct_params = (t_params **)malloc(sizeof(t_params *) * (sizes.y + 1));
	while (counter < sizes.y)
	{
		get_next_line(fd, &line);
		params = ft_strsplit(line, ' ');
		free(line);
		struct_params[counter] = (t_params *)malloc(sizeof(t_params) * (sizes.x + 1));
		struct_params[counter] = ft_make_coord(params, struct_params[counter], y, sizes.x / 2);
		ft_free_struct(params);
		counter++;
		y += 1;
	}
	struct_params[counter] = NULL;
	return (struct_params);
}