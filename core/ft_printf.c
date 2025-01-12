/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:00:53 by gletilly          #+#    #+#             */
/*   Updated: 2025/01/12 23:11:18 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_handle_format(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (format == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count = ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count = ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		count = ft_puthex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count = ft_puthex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_format(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
