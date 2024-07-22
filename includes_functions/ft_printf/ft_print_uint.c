/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:54:48 by jsakanov          #+#    #+#             */
/*   Updated: 2023/10/12 14:49:48 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_print_uint(long n, int len)
{
	if (n >= 0 && n < 10)
		len += ft_printchar(n + '0');
	else
	{
		len += ft_print_uint(n / 10, 0);
		len += ft_print_uint(n % 10, 0);
	}
	return (len);
}
