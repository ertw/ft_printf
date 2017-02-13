/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:24:22 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/09 11:49:05 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	char	*optr;
	size_t	len;

	len = 0;
	if (s)
	{
		while (ft_isspace(*s))
			s++;
		if (!*s)
			return (ft_strdup(""));
		len = ft_strlen(s);
		while (ft_isspace(s[len - 1]))
			len--;
		ptr = ft_strnew(len + 1);
		if (ptr)
		{
			optr = ptr;
			while (len--)
				*ptr++ = *s++;
			*ptr = '\0';
			return (optr);
		}
	}
	return (NULL);
}
