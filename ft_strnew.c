/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:47:53 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/09 12:02:41 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * size + 1);
	if (ptr)
	{
		ft_bzero(ptr, size + 1);
		return (ptr);
	}
	return (NULL);
}
