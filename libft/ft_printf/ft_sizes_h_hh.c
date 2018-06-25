/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizes_h_hh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:11:34 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/20 21:11:34 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_size_hh_d_i(t_printf *param, t_size *size, void *number)
{
	size->hh = (signed char)number;
	if (!size->hh)
		param->check_zero = 1;
	if (size->hh == -128)
	{
		param->check_num = -1;
		param->string = ft_strjoin_free(&param->string, "128");
	}
	else
	{
		if (size->hh < 0)
		{
			param->check_num = -1;
			size->hh = -size->hh;
		}
		free(param->string);
		param->string = ft_itoa_base((size_t)size->hh, param->base, 0);
	}
}

void		ft_check_size_hh(t_printf *param, t_size *size, void *number)
{
	if (!ft_strcmp(param->convers, "d") || !ft_strcmp(param->convers, "i"))
		ft_check_size_hh_d_i(param, size, number);
	else if (!ft_strcmp(param->convers, "o")
	|| !ft_strcmp(param->convers, "u") || !ft_strcmp(param->convers, "x")
	|| !ft_strcmp(param->convers, "X"))
	{
		size->u_hh = (unsigned char)number;
		if (!size->u_hh)
			param->check_zero = 1;
		if (size->u_hh < 0)
		{
			param->check_num = -1;
			size->u_hh = -size->u_hh;
		}
		free(param->string);
		param->string = ft_itoa_base((size_t)size->u_hh,
		param->base, (param->convers[0] == 'X' ? 1 : 0));
	}
}

static void	ft_check_size_h_d_i(t_printf *param, t_size *size, void *number)
{
	size->h = (short)number;
	if (!size->h)
		param->check_zero = 1;
	if (size->h == -32768)
	{
		param->check_num = -1;
		param->string = ft_strjoin_free(&param->string, "32768");
	}
	else
	{
		if (size->h < 0)
		{
			param->check_num = -1;
			size->h = -size->h;
		}
		free(param->string);
		param->string = ft_itoa_base((size_t)size->h, param->base, 0);
	}
}

void		ft_check_size_h(t_printf *param, t_size *size, void *number)
{
	if (!ft_strcmp(param->convers, "d") || !ft_strcmp(param->convers, "i"))
		ft_check_size_h_d_i(param, size, number);
	else if (!ft_strcmp(param->convers, "o")
	|| !ft_strcmp(param->convers, "u") || !ft_strcmp(param->convers, "x")
	|| !ft_strcmp(param->convers, "X"))
	{
		size->u_h = (unsigned short)number;
		if (!size->u_h)
			param->check_zero = 1;
		if (size->u_h < 0)
		{
			param->check_num = -1;
			size->u_h = -size->u_h;
		}
		free(param->string);
		param->string = ft_itoa_base((size_t)size->u_h,
		param->base, (param->convers[0] == 'X' ? 1 : 0));
	}
}
