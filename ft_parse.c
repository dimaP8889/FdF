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

void		ft_make_params(t_params *struct_params, char *str, char *find)
{
	char	*num;
	char	*col;
	int		count;

	count = -1;
	find++;
	col = find;
	num = ft_strnew(find - str);
	while (str[++count] != ',')
		num[count] = str[count];
	num[count] = 0;
	struct_params->z = ft_atoi_base(num, 10);
	struct_params->col = ft_atoi_base(col, 16);
	free(num);
	//col--;
	//free(col);
	// printf("%i\n", struct_params->y);
}

t_params 	*ft_make_coord(char **params, t_params *struct_params, int z)
{
	int 	x;
	int		count;
	char	*find_c;

	x = 0;
	count = 0;
	while (*params)
	{

		find_c = ft_strchr(*params, ',');
		struct_params[count].x = x;
		struct_params[count].y = z;
		struct_params[count].end = 0;
		if (!find_c)
		{
			struct_params[count].z = ft_atoi_base(*params, 10);
			struct_params[count].col = 0xFFFFFF;
		}
		else
		{
			ft_make_params(&struct_params[count], *params, find_c);
			// printf("%i\n", struct_params[count].y);
			// printf("%#x\n", struct_params[count].col);
		}
		//ft_check_valid()
		x += 30;
		count++;
		(params)++;
	}
	struct_params[count].end = 1;
	//free(find_c);
	return (struct_params);
}

int			ft_length(char	**params)
{
	int	length;

	length = 0;
	while (params[length])
		length++;
	length++;
	return (length);
}

//надо пофришить строки

t_params	**ft_parse(int fd, int size)
{
	int			z;
	int			counter;
	char		*line;
	char		**params;
	static t_params	**struct_params;

	z = 0;
	counter = 0;
	struct_params = (t_params **)malloc(sizeof(t_params *) * (size + 1));
	while (size > 0)
	{
		get_next_line(fd, &line);
		params = ft_strsplit(line, ' ');
		struct_params[counter] = (t_params *)malloc(sizeof(t_params) * ft_length(params));
		struct_params[counter] = ft_make_coord(params, struct_params[counter], z);
		z += 30;
		counter++;
		size--;
	}
	struct_params[counter] = NULL;
	return (struct_params);
}