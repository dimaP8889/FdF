/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addletter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:13:20 by dpogrebn          #+#    #+#             */
/*   Updated: 2018/02/20 21:13:21 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_addletter(char *string, char letter)
{
	char	*str;
	char	*str_copy;

	str_copy = string;
	if (!(str = (char *)malloc(sizeof(char) + 1)))
		return (0);
	str[0] = letter;
	str[1] = '\0';
	string = ft_strjoin(str_copy, str);
	free(str_copy);
	free(str);
	return (string);
}
