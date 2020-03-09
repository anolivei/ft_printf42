/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:35:24 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/08 22:49:12 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		len;
	int		i;
	t_flags	flag;
	va_start(arguments, format);
	i = 0;	
	while (format[i] != '\0')
	{
		while (format[i] == '%')
		{
			flag = ft_clean_flags();
			i++;
			while(format[i] != '\0' && ft_strchr(FLAGS, format[i]) != 0)
			{
				flag = ft_verify_flags(&format[i], arguments, flag);
				i++;	
			}
			if (format[i] == '\0')
				return (0);
			else
				len = ft_verify_type(format[i], arguments, flag);
				i++;			 
		}
		if (format[i] != '\0')
			len = ft_putchar_len(&format[i], len);
		i++;
	}
	return (len);
}

int	ft_verify_type(char c, va_list arguments, t_flags flag)
{
	int len;
	
	len = 0;
	printf("\nc = %c", c);
	if (c == 'c')
		len = ft_print_char(va_arg(arguments, int), flag);
/*	if (c == 'd' || c == 'i')
		len = ft_print_int(va_arg(arguments, int), flag);
	if (c == 's')
		len = ft_print_string(va_arg(arguments, *char), flag);
	if (c == 'x')
		len = ft_print_hexa(va_arg(arguments, unsigned long int), HEXA_LOWER, flag);
	if (c == 'X')
		len = ft_print_hexa(va_arg(arguments, unsigned long int), HEXA_UPPER, flag);
	if (c == 'p')
		len = ft_print_pointer(va_arg(arguments, unsigned long int), flag);
	if (c == 'u')
		len = ft_print_u(va_arg(arguments, int), flag);
	else
		len = ft_print_percent(flag);*/
	return (len);	
}

t_flags	ft_verify_star(va_list arguments, t_flags flag)
{
	if (flag.dot == 0)
		flag.width = va_arg(arguments, int);
	else
		flag.precision = va_arg(arguments, int);
	if (flag.width < 0)
	{
		flag.justify = 1;
		flag.width = flag.width * (-1);
		flag.zero = 0;
	}
	return (flag);
}

t_flags	ft_verify_flags(const char *c, va_list arguments, t_flags flag) 
{
	printf("\nc = %s", c);
	if (*c == '0' && flag.justify == 0 && flag.width == 0)
		flag.zero = 1;
	else if (*c == '*')
		ft_verify_star(arguments, flag);
	else if (*c == '.')
		flag.dot = 1;
	else if (*c == '-')
	{
		flag.justify = 1;
		flag.zero = 0;
	}
	else if (ft_strchr(DECIMAL, *c))
	{
		if (flag.dot == 1)
			flag.precision = (flag.precision * 10) + (*c - '0');
		else
			flag.width = (flag.width * 10) + (*c - '0');
	}
	printf("wi %d\n", flag.width);
	printf("ju %d\n", flag.justify);
	flag.type = c[ft_strlen(c) - 1];
	printf("type %zu\n", ft_strlen(c));
	printf("fl %c", flag.type);
	return (flag);
}

int	ft_putchar_len(const char *c, int len)
{
	write(1, &c, 1);
	len++;
	return (len);
}

t_flags	ft_clean_flags(void)
{
	t_flags flag;

	flag.zero = 0;
	flag.dot = 0;
	flag.width = 0;
	flag.precision = 0;
	flag.justify = 0;
	return (flag);
}
	
