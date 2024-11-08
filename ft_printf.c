/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gletilly <gletilly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:00:53 by gletilly          #+#    #+#             */
/*   Updated: 2024/10/27 23:10:26 by gletilly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*
int	main(void)
{
	char			c;
	char			*str;
	void			*ptr;
	int				num;
	unsigned int	u_num;

	c = 'A';
	str = "Hello World!";
	ptr = &c;
	num = -42;
	u_num = 42;
	ft_printf("\n---- Test de chaque conversion ----\n\n");
	ft_printf("Test %%c : %c\n", c);
	ft_printf("Test %%s : %s\n", str);
	ft_printf("Test %%p : %p\n", ptr);
	ft_printf("Test %%d : %d\n", num);
	ft_printf("Test %%i : %i\n", num);
	ft_printf("Test %%u : %u\n", u_num);
	ft_printf("Test %%x : %x\n", u_num);
	ft_printf("Test %%X : %X\n", u_num);
	ft_printf("Test %%%% : %%\n");
	ft_printf("\n---- Test avec NULL ----\n\n");
	ft_printf("Test %%s with NULL: %s\n", NULL);
	ft_printf("Test %%p with NULL: %p\n", NULL);
	ft_printf("\n---- Test avec valeurs limites ----\n\n");
	ft_printf("Test %%d with INT_MIN: %d\n", -2147483648);
	ft_printf("Test %%d with INT_MAX: %d\n", 2147483647);
	return (0);
}
*/
