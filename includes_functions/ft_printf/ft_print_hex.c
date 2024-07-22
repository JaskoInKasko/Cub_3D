/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:50:37 by jsakanov          #+#    #+#             */
/*   Updated: 2023/10/12 15:01:25 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_print_hex(unsigned int n, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		len += ft_print_hex(n / 16, 0);
		len += ft_print_hex(n % 16, 0);
	}
	else if (n <= 16)
		len += ft_printchar(base[n]);
	return (len);
}
