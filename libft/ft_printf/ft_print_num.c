/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:17:23 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/05 19:17:24 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(t_printf *param)
{
	int	count;

	count = 0;
	param->out = ft_strjoin_free(&param->out, param->out_num);
	if (!param->precision && param->check_zero
	&& !param->this_is_funny_o_sharp && ft_strcmp(param->convers, "p"))
	{
		while (param->out[count] != '0')
			count++;
		if (param->out[count - 1] == '+')
			param->out[count] = '+';
		else
			param->out[count] = ' ';
		if (param->width < 1)
		{
			param->out++;
			param->tihs = 1;
		}
	}
	ft_putstr(param->out);
	param->return_val = ft_strlen(param->out) + ft_strlen(param->print);
}
