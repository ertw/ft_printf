/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:24:28 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/09 15:14:31 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n && i + 1 < n && (s1[i] || s2[i]) && !ft_chrcmp(s1[i], s2[i]))
		i++;
	return (n
		? ft_chrcmp(s1[i], s2[i])
		: 0);
}
