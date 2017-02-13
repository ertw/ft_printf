/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:02:40 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/17 15:03:00 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*joins strings, and returns the len*/

#include "libft.h"

int	ft_strwjoin(char **old, const char *new, int len)
{
	char	*tmp;
	size_t	old_len;
	size_t	total_len;

	len = len < 0 ? ft_strlen(new) : len;
	old_len = *old == NULL
		? 0
		: ft_strlen(*old);
	total_len = *old == NULL
		? len
		: len + old_len;
	tmp = ft_strnew(total_len);
	if (*old == NULL)
		ft_memmove(tmp, new, len);
	else
	{
		ft_memmove(ft_stpcpy(tmp, *old), new, len);
		ft_strdel(&(*old));
	}
	*old = tmp;
	return (total_len);
}
