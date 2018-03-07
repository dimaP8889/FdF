/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_pic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:16:37 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/03/07 18:16:38 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_lol(void *params)
{
	t_mlx	*data;

	data = params;
	ft_make_line(126, data);
	mlx_clear_window(data->mlx, data->wnd);
	return (0);
}

void	ft_first_pic(t_mlx *data)
{
	static	int		coun;

	if (!coun)
	{
		ft_make_line(126, data);
		ft_make_line(126, data);
		ft_make_line(126, data);
		ft_make_line(126, data);
		coun = 1;
	}
}