/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:18:24 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/05 19:18:25 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_size_l_d_i_dh(t_printf *param, t_size *size, void *number)
{
	size->l = (long)number;
	if (!size->l)
		param->check_zero = 1;
	if (size->l < 0)
	{
		param->check_num = -1;
		size->l = -size->l;
	}
	if (!ft_strcmp(param->convers, "D"))
		param->convers[0] = 'd';
	free(param->string);
	param->string = ft_itoa_base((size_t)size->l, param->base, 0);
}

void		ft_check_size_l(t_printf *param, t_size *size, void *number)
{
	if (!ft_strcmp(param->convers, "d")
		|| !ft_strcmp(param->convers, "i") || !ft_strcmp(param->convers, "D"))
		ft_check_size_l_d_i_dh(param, size, number);
	else if (!ft_strcmp(param->convers, "o") || !ft_strcmp(param->convers, "O")
		|| !ft_strcmp(param->convers, "u") || !ft_strcmp(param->convers, "U")
		|| !ft_strcmp(param->convers, "x") || !ft_strcmp(param->convers, "X"))
	{
		size->u_l = (unsigned long)number;
		if (!size->u_l)
			param->check_zero = 1;
		free(param->string);
		if (!ft_strcmp(param->convers, "O"))
			param->convers[0] = 'o';
		if (!ft_strcmp(param->convers, "U"))
			param->convers[0] = 'u';
		param->string = ft_itoa_base((size_t)size->u_l,
		param->base, (param->convers[0] == 'X' ? 1 : 0));
	}
}

void		ft_check_size_ll(t_printf *param, t_size *size, void *number)
{
	if (!ft_strcmp(param->convers, "d") || !ft_strcmp(param->convers, "i"))
	{
		size->ll = (long long)number;
		if (!size->ll)
			param->check_zero = 1;
		if (size->ll < 0)
		{
			param->check_num = -1;
			size->ll = -size->ll;
		}
		free(param->string);
		param->string = ft_itoa_base((size_t)size->ll, param->base, 0);
	}
	else if (!ft_strcmp(param->convers, "o") || !ft_strcmp(param->convers, "u")
		|| !ft_strcmp(param->convers, "x") || !ft_strcmp(param->convers, "X"))
	{
		size->u_ll = (unsigned long long)number;
		if (!size->u_ll)
			param->check_zero = 1;
		free(param->string);
		param->string = ft_itoa_base((size_t)size->u_ll,
		param->base, (param->convers[0] == 'X' ? 1 : 0));
	}
}

void		ft_check_size_j(t_printf *param, t_size *size, void *number)
{
	if (!ft_strcmp(param->convers, "d") || !ft_strcmp(param->convers, "i"))
	{
		size->j = (intmax_t)number;
		if (!size->j)
			param->check_zero = 1;
		if (size->j < 0)
		{
			param->check_num = -1;
			size->j = -size->j;
		}
		free(param->string);
		param->string = ft_itoa_base((size_t)size->j, param->base, 0);
	}
	else if (!ft_strcmp(param->convers, "o") || !ft_strcmp(param->convers, "u")
		|| !ft_strcmp(param->convers, "x") || !ft_strcmp(param->convers, "X"))
	{
		size->u_j = (uintmax_t)number;
		if (!size->u_j)
			param->check_zero = 1;
		free(param->string);
		param->string = ft_itoa_base((size_t)size->u_j,
		param->base, (param->convers[0] == 'X' ? 1 : 0));
	}
}

void		ft_check_size_z(t_printf *param, t_size *size, void *number)
{
	if (!ft_strcmp(param->convers, "d") || !ft_strcmp(param->convers, "i"))
	{
		size->z = (ssize_t)number;
		if (!size->z)
			param->check_zero = 1;
		if (size->z < 0)
		{
			param->check_num = -1;
			size->z = -size->z;
		}
		free(param->string);
		param->string = ft_itoa_base((size_t)size->z, param->base, 0);
	}
	else if (!ft_strcmp(param->convers, "o") || !ft_strcmp(param->convers, "u")
		|| !ft_strcmp(param->convers, "x") || !ft_strcmp(param->convers, "X"))
	{
		size->u_z = (size_t)number;
		if (!size->u_z)
			param->check_zero = 1;
		free(param->string);
		param->string = ft_itoa_base((size_t)size->u_z,
		param->base, (param->convers[0] == 'X' ? 1 : 0));
	}
}
