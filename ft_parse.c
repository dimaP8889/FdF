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



t_params 	*ft_make_coord(char **params, t_params *struct_params, int z)
{
	int 	x;
	int		count;

	x = 0;
	count = 0;
	while (*params)
	{
		//struct_params[count] = (t_params *)malloc(sizeof(t_params));
		struct_params[count].x = x;
		struct_params[count].z = z;
		struct_params[count].end = 0;
		if (!ft_strchr(*params, ','))
		{
			struct_params[count].y = ft_atoi_base(*params, 10);
			struct_params[count].col = 0xFFFFFF;
		}
		x += 20;
		count++;
		(params)++;
	}
	struct_params[count].end = 1;
	//struct_params[count] = (t_params *)malloc(sizeof(t_params));
	//(void)struct_params[count] = 0;
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

t_params	**ft_parse(int fd, int size)
{
	int			z;
	int			counter;
	// int			count = 0;
	char		*line;
	char		**params;
	t_params	**struct_params;

	z = 0;
	counter = 0;
	struct_params = (t_params **)malloc(sizeof(t_params *) * (size + 1));
	while (size > 0)
	{
		get_next_line(fd, &line);
		// printf("%s\n", line);
		params = ft_strsplit(line, ' ');
		struct_params[counter] = (t_params *)malloc(sizeof(t_params) * ft_length(params));
		struct_params[counter] = ft_make_coord(params, struct_params[counter], z);
		z += 20;
		counter++;
		size--;
	}
	// printf("%i\n", counter);
	struct_params[counter] = NULL;

	// counter = 0;
	// while (struct_params[count])
	// {
	// 	while (struct_params[count][counter].x != 200)
	// 	{
	// 		printf("x: %i\n", struct_params[count][counter].x);
	// 		printf("y: %i\n", struct_params[count][counter].y);
	// 		printf("z: %i\n", struct_params[count][counter].z);
	// 		printf("col :%i\n", struct_params[count][counter].col);
	// 		counter++;
	// 	}
	// 	counter = 0;
	// 	count++;
	// }
	return (struct_params);
}