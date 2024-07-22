/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:54:48 by jsakanov          #+#    #+#             */
/*   Updated: 2023/10/12 16:35:08 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_specifier(const char str, va_list args, int len)
{
	if (args == NULL)
		return (write(1, "-1", 2));
	if (str == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (str == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (str == 'p')
		len += ft_printmem(va_arg(args, void *), len);
	else if (str == 'd' || str == 'i')
		len += ft_print_int(va_arg(args, int), len);
	else if (str == 'u')
		len += ft_print_uint(va_arg(args, unsigned int), len);
	else if (str == 'x')
		len += ft_print_hex(va_arg(args, unsigned int), len);
	else if (str == 'X')
		len += ft_print_uhex(va_arg(args, unsigned int), len);
	else if (str == '%')
		len += ft_printchar(str);
	else
	{
		len += ft_printchar('%');
		len += ft_printchar(str);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, format);
	len = 0;
	i = 0;
	if (format == NULL)
		return (write(1, "", 0));
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			len += ft_specifier(format[i + 1], arg, 0);
			i++;
		}
		else if (format[i] == '%' && (i == 0 || format[i - 1] != '%'))
			len += ft_printchar(format[i]);
		else if (format[i] != '%')
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
