/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:43:12 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/28 20:14:54 by dpogrebn         ###   ########.fr       */
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
	//struct_params->z += (struct_params->z > 0 ? 100 : 0);
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

t_params 	*ft_make_coord(char **params, t_params *struct_params, int y, int center)
{
	int 	x;
	int		count;
	char	*find_c;

	x =  -center;
	count = 0;
	while (*params)
	{

		find_c = ft_strchr(*params, ',');
		struct_params[count].x = x;
		struct_params[count].y = y;
		struct_params[count].end = 0;
		if (!find_c)
		{
			struct_params[count].z = ft_atoi_base(*params, 10);
			//struct_params[count].z += (struct_params[count].z > 0 ? 100 : 0);
			struct_params[count].col = 0xFFFFFF;
		}
		else
		{
			ft_make_params(&struct_params[count], *params, find_c);
		}
		// ft_make_central(&struct_params[count]);
		x += 1;
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
	int			y;
	char		*line;
	char		**params;
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
		struct_params[counter] = (t_params *)malloc(sizeof(t_params) * (sizes.x + 1));
		struct_params[counter] = ft_make_coord(params, struct_params[counter], y, sizes.x / 2);
		counter++;
		c--;
		y += 1;
	}
	struct_params[counter] = NULL;
	return (struct_params);
}