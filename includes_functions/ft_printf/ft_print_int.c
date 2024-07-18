/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:14:42 by jsakanov          #+#    #+#             */
/*   Updated: 2023/10/12 14:53:21 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_int(long n, int len)
{
	if (n < 0)
	{
		len += ft_printchar('-');
		n = -n;
	}
	if (n < 10)
		len += ft_printchar(n + '0');
	else
	{
		len += ft_print_int(n / 10, 0);
		len += ft_print_int(n % 10, 0);
	}
	return (len);
}
