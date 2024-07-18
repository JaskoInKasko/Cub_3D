/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:49:25 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/18 19:18:26 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (!lst || !new)
		return ;
	if (lst && *lst)
	{
		begin = ft_lstlast(*lst);
		begin->next = new;
	}
	else if (lst)
		*lst = new;
}
