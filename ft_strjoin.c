/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:53:08 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/05 21:51:26 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*optr;

	if (s1 && s2)
	{
		ptr = malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 3));
		if (ptr)
		{
			optr = ptr;
			ft_stpcpy((ft_stpcpy(ptr, s1)), s2);
			return (optr);
		}
	}
	return (NULL);
}
