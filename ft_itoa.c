/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:24:29 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/15 05:51:55 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num1;
	unsigned int	num2;
	
	if (n < 0)
		num1 = n * (-10);
	else
		num1 = n * 10;
	len = n <= 0 ? 1: 0;
	num2 = num1;
	while ((num1 = num1 / 10) > 0)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	if (n < 0)
		str[0] = '-';
	str[len--] = '\0';
	while ((num2 = num2 / 10) > 0)
		str[len--] = (num2 % 10 + '0');
	return (str);
}
