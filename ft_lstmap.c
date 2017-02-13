/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:27:06 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/08 13:40:25 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*head_curr;

	if (!lst || !f)
		return (NULL);
	head_curr = f(lst);
	head = head_curr;
	lst = lst->next;
	while (lst)
	{
		head_curr->next = f(lst);
		head_curr = head_curr->next;
		lst = lst->next;
	}
	return (head);
}
