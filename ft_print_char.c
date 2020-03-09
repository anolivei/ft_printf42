/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 21:43:53 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/08 22:31:40 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, t_flags flag)
{
	int len;
	char letra;
	
	letra = c + 48;
	len = 0;
	if (flag.justify == 0 && flag.width == 0)
	{
		write(1, "a", 1);
		write(1, &letra, 1);
		len = 1;
		return (len);
	}
	else if (flag.justify == 0 && flag.width > 0)
	{
		len = flag.width;
		while (len > 1)
		{
			write(1, "B", 1);
			write(1, " ", 1);
			len --;
		}
		write(1, &letra, 1);
		len = flag.width;
		return (len);
	}
	else if (flag.justify == 1 && flag.width > 0)
	{
		write(1, "c", 1);
		write(1, &letra, 1);
		while (len > 1)
		{
			write(1, " ", 1);
			len--;
		}
		len = flag.width;
		return (len);
	}
	return (0);

}