/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:26:36 by ewilliam          #+#    #+#             */
/*   Updated: 2016/11/29 21:08:53 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	if (len > n)
		len = n;
	s2 = malloc(sizeof(char) * len + 1);
	if (s2)
	{
		ft_memcpy(s2, s1, len);
		s2[len] = '\0';
		return (s2);
	}
	return (NULL);
}
