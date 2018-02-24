/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:10:28 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/20 21:10:30 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_find_flag(const char **string, t_printf *params)
{
	if (**string == ' ')
	{
		params->flag = ft_addletter(params->flag, **string);
		(*string)++;
	}
	while (**string == ' ')
		(*string)++;
	while (ft_strchr(FLAGS, **string) && **string)
	{
		if (!ft_strchr(params->flag, **string))
			params->flag = ft_addletter(params->flag, **string);
		(*string)++;
	}
}

static void	ft_find_width(const char **string, t_printf *params)
{
	while (**string == ' ')
		(*string)++;
	while (ft_isdigit(**string))
	{
		params->width_char = ft_addletter(params->width_char, **string);
		(*string)++;
	}
	params->width = ft_atoi(params->width_char);
}

static void	ft_find_precision(const char **st, t_printf *params)
{
	while (**st == ' ')
		(*st)++;
	if (**st == '.')
	{
		(*st)++;
		ft_strcpy(params->precision_char, ".");
		while (ft_isdigit(**st))
		{
			params->precision_char = ft_addletter(params->precision_char, **st);
			(*st)++;
		}
	}
	params->precision_char++;
	params->precision = ft_atoi(params->precision_char);
	params->precision_char--;
}

static void	ft_find_size(const char **string, t_printf *params)
{
	int		max;
	int		base;

	max = -1;
	while (**string == ' ')
		(*string)++;
	while (ft_strchr(SIZES, **string) && **string)
	{
		base = check_size_base(*string);
		if (base > max)
			max = base;
		(*string)++;
	}
	ft_choose_size(max, params);
}

void		ft_pars(const char **string, t_printf *params)
{
	while (!ft_strchr(CONVERS, **string) && **string)
	{
		if (ft_strchr(FLAGS, **string))
			ft_find_flag(string, params);
		else if (**string == '.')
			ft_find_precision(string, params);
		else if (ft_strchr(SIZES, **string))
			ft_find_size(string, params);
		else if (ft_isdigit((**string - 0)))
			ft_find_width(string, params);
		else
			break ;
	}
	ft_find_convers(string, params);
}
