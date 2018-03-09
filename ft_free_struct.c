/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:26:05 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/09 19:26:05 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_struct(char **param)
{
	int count;

	count = 0;
	while (param[count])
	{
		free(param[count]);
		count++;
	}
	free(param);
}
