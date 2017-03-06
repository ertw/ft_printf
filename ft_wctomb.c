/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:56:56 by ewilliam          #+#    #+#             */
/*   Updated: 2017/03/04 15:56:58 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wctomb(char *s, wchar_t wchar)
{
	char	*tmp;

	tmp = s;
	if (wchar <= 0x007F)
	{
		*tmp = wchar;
		return (1);
	}
	else if (wchar <= 0x07FF)
	{
		*tmp++ = (wchar >> 6) + 0xC0;
		*tmp = (wchar & 0x3F) + 0x80;
		return (2);
	}
	else if (wchar <= 0xFFFF)
	{
		*tmp++ = (wchar >> 12) + 0xE0;
		*tmp++ = ((wchar >> 6) & 0x3F) + 0x80;
		*tmp++ = (wchar & 0x3F) + 0x80;
		return (3);
	}
	else if (wchar <= 0x10FFFF)
	{
		*tmp++ = (wchar >> 18) + 0xF0;
		*tmp++ = ((wchar >> 12) + 0xE0) + 0x80;
		*tmp++ = ((wchar >> 6) & 0x3F) + 0x80;
		*tmp++ = (wchar & 0x3F) + 0x80;
		return (4);
	}
	return (-1);
}
