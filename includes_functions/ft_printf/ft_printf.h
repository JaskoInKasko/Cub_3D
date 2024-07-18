/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:15:13 by jsakanov          #+#    #+#             */
/*   Updated: 2023/10/12 14:55:49 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_printchar(const char c);
int				ft_printstr(const char *s);
int				ft_print_int(long n, int len);
unsigned int	ft_print_uint(long n, int len);
unsigned int	ft_print_hex(unsigned int n, int len);
unsigned int	ft_print_uhex(unsigned int n, int len);
int				ft_printmem(void *ptr, int len);

#endif
