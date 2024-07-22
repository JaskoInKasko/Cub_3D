/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:54:48 by jsakanov          #+#    #+#             */
/*   Updated: 2023/10/12 16:38:42 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printmem(void *ptr, int len)
{
	char	*base;
	char	hexn[22];
	size_t	address;
	int		offset;
	int		digit;

	base = "0123456789abcdef";
	address = (size_t)ptr;
	offset = 0;
	if (ptr == 0)
		return (len += write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	while (address > 0)
	{
		digit = address % 16;
		hexn[offset++] = base[digit];
		address /= 16;
	}
	offset -= 1;
	while (offset >= 0)
		len += ft_printchar(hexn[offset--]);
	return (len);
}
