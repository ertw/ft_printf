/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:23:48 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/09 08:09:34 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char delim)
{
	int		len;
	char	**strptr;
	char	**ostrptr;
	int		words;

	words = ft_wordcount(s, delim, 0);
	strptr = malloc(sizeof(*strptr) * (words + 1));
	if (!strptr || !s)
		return (NULL);
	ostrptr = strptr;
	while (*s && ostrptr)
	{
		len = 0;
		while (*s && *s == delim)
			s++;
		while (*s && *s != delim)
		{
			len++;
			s++;
		}
		if (len)
			*strptr++ = ft_strsub(s - len, 0, len);
	}
	*strptr = 0;
	return (ostrptr);
}
