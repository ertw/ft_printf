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
#include "printf.h"
#include <stdio.h>

int	ft_strwjoin(t_print *p, const char *new, int len)
{
	char	*tmp;
	int	old_len;
	int	total_len;

	len = len < 0 ? (int)ft_strlen(new) : len;
	old_len = p->out == NULL
		? 0
		: p->r;
	total_len = p->out == NULL
		? len
		: len + old_len;
	tmp = ft_strnew(total_len);
	if (p->out == NULL)
		ft_memmove(tmp, new, len);
	else
	{
		ft_memmove(tmp, p->out, old_len);
		ft_memmove(tmp + old_len, new, len);
	}
	p->out = tmp;
	return (total_len);
}
