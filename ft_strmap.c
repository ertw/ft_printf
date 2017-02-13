/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:26:37 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/09 16:17:06 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s1, char (*f)(char))
{
	char	*s2;
	char	*s2_head;

	if (s1 && f)
	{
		s2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
		if (s2)
		{
			s2_head = s2;
			while (*s1)
				*(s2++) = f(*(s1++));
			*s2 = '\0';
			return (s2_head);
		}
	}
	return (NULL);
}
