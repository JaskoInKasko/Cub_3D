/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:47:02 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/19 11:27:25 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*v1;

	v1 = (t_list *)malloc(sizeof(t_list));
	if (!v1)
		return (NULL);
	v1 -> content = content;
	v1 -> next = NULL;
	return (v1);
}
