/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_pic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:16:37 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/09 01:00:51 by dmitriy1         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_first_pic(t_mlx *data)
{
	static	int		coun;

	if (!coun)
	{
		ft_make_line(0, data);
		coun = 1;
	}
}
