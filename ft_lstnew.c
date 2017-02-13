/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:00:56 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/04 20:15:17 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		if (!content)
		{
			content_size = 0;
			node->content = NULL;
		}
		else
		{
			node->content = malloc(sizeof(size_t) * content_size);
			ft_memcpy(node->content, content, content_size);
		}
		node->content_size = content_size;
		node->next = NULL;
	}
	return (node);
}
