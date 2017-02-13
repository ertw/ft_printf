/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:44:03 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/08 14:06:11 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		if ((!*s1 && !*s2) || n == 0)
			return (1);
		if (*s1 == *s2 && n)
			return (ft_strnequ(++s1, ++s2, --n));
	}
	return (0);
}
