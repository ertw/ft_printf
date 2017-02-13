/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:42:52 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/05 21:43:18 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s1, char (*f)(unsigned int, char))
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
			{
				*s2 = f((unsigned int)(s2 - s2_head), *s1);
				s1++;
				s2++;
			}
			*s2 = '\0';
			return (s2_head);
		}
	}
	return (NULL);
}
