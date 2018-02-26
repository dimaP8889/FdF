/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <dpogrebn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 22:37:35 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/26 22:35:31 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		split(char c)
{
	if (c == '\n' || c == ' ' || c == '\t'
		|| c == '\r' || c == '\f'
		|| c == '\v')
		return (1);
	return (0);
}

static	int		ft_correct(int base, int num)
{
	char 	*max_base_low;
	char 	*max_base_high;
	int		coun;

	coun = 0;
	max_base_low = "0123456789abcdef";
	max_base_high = "0123456789ABCDEF";
	if (!num)
		return (0);
	if (!ft_strchr(max_base_low, num) && !ft_strchr(max_base_high, num))
		return (0);
	if (ft_strchr(max_base_low, num))
		coun = ft_strchr(max_base_low, num) - max_base_low;
	else if (ft_strchr(max_base_high, num))
		coun = ft_strchr(max_base_high, num) - max_base_high;
	if (coun < base)
		return (1);
	return (0);
}

static	int		result(unsigned char *str, int is_neg, int base)
{
	unsigned long int		res;
	res = 0;

	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X') && base == 16)
		str += 2;
	while (ft_correct(base, *str) && *str)
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
		&& (*str - '0') > 7)) && is_neg == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
		&& (*str - '0') > 8)) && is_neg == -1)
			return (0);
		if (ft_isdigit(*str))
			res = (*(str++) - '0') + res * base;
		else if (*str >= 'A' && *str <= 'F')
			res = (*(str++) - 55) + res * base;
		else
			res = (*(str++) - 87) + res * base;
	}
	// if (!ft_correct(base, *str) && *str)
	// 	return (0);
	return (is_neg * res);
}

int				ft_atoi_base(const char *str1, int base)
{
	unsigned char					*str;
	int								is_neg;
	int								res;

	res = 0;
	str = (unsigned char *)str1;
	is_neg = 1;

	while (split(*str))
		str++;
	if (*str == '-' && is_neg == 1)
	{
		if (base != 10)
			return (0);
		is_neg = -1;
		str++;
	}
	if (*str == '+' && is_neg == 1)
	{
		if (base != 10)
			return (0);
		str++;
	}
	res = result(str, is_neg, base);
	return (res);
}