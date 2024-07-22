/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:28:58 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/14 17:37:51 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*void    ft_changestr(unsigned int d, char *s)
{
    if(s[d] == 'u')
        s[d] = 'z';
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
