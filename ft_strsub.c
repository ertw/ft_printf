/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:18:19 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/07 14:24:19 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*optr;

	if (s)
	{
		ptr = malloc(sizeof(char) * len + 1);
		if (ptr)
		{
			optr = ptr;
			while (len--)
				*(ptr++) = s[start++];
			*ptr = '\0';
			return (optr);
		}
	}
	return (NULL);
}
