/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsakanov <jsakanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:54:57 by jsakanov          #+#    #+#             */
/*   Updated: 2023/09/19 14:50:56 by jsakanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;
	t_list	*new1;

	if (!lst || !del)
		return ;
	new = *lst;
	new1 = *lst;
	while (new)
	{
		new1 = new1->next;
		del(new->content);
		free(new);
		new = new1;
	}
	*lst = NULL;
}
