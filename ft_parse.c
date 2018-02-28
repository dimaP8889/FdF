/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:43:12 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/28 12:14:45 by dmitriy1         ###   ########.fr       */
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
	struct_params->z += (struct_params->z > 0 ? 100 : 0);
	struct_params->col = ft_atoi_base(col, 16);
	// if (ft_atoi_base(num, 10) == 9)
	// {
	// 	printf("%i\n", struct_params->y);
	// 	printf("%#x\n", struct_params->col);
	// }
	free(num);
	// printf("%i\n", struct_params->y);
	//col--;
	//free(col);
	// printf("%i\n", struct_params->y);
}

// void	ft_make_central()

t_params 	*ft_make_coord(char **params, t_params *struct_params, int z)
{
	int 	x;
	int		count;
	char	*find_c;

	x = 300;
	count = 0;
	// printf("x: %i\n", x);
	//printf("y: %i\n", y);
	// printf("z: %i\n", z);
	while (*params)
	{

		find_c = ft_strchr(*params, ',');
		struct_params[count].x = x;
		struct_params[count].y = z;
		struct_params[count].end = 0;
		if (!find_c)
		{
			struct_params[count].z = ft_atoi_base(*params, 10);
			struct_params[count].z += (struct_params[count].z > 0 ? 100 : 0);
			struct_params[count].col = 0xFFFFFF;
		}
		else
		{
			ft_make_params(&struct_params[count], *params, find_c);
		}
		// ft_make_central(&struct_params[count]);
		x += 30;
		count++;
		(params)++;
	}
	struct_params[count].end = 1;
	//free(find_c);
	return (struct_params);
}

//надо пофришить строки

t_params	**ft_parse(int fd, t_sizes sizes)
{
	int			counter;
	int			z;
	char		*line;
	char		**params;
	int			c;
	static t_params	**struct_params;

	counter = 0;
	z = 300;
	c = sizes.z;
	struct_params = (t_params **)malloc(sizeof(t_params *) * (sizes.y + 1));
	while (c > 0)
	{
		get_next_line(fd, &line);
		params = ft_strsplit(line, ' ');
		struct_params[counter] = (t_params *)malloc(sizeof(t_params) * (sizes.x + 1));
		struct_params[counter] = ft_make_coord(params, struct_params[counter], z);
		counter++;
		c--;
		z += 30;
	}
	struct_params[counter] = NULL;
	return (struct_params);
}