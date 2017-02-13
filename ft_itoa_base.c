/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:55:28 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/09 12:13:56 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, const size_t base)
{
	char			*sym;
	char			*arr;
	char			*head;
	unsigned long	num;

	sym = "0123456789ABCDEF";
	num = n;
	if (!(arr = ft_strnew(ft_countplaces(num, base))))
		return (NULL);
	head = arr;
	while (num)
	{
		*arr++ = *(sym + (num % base));
		num /= base;
	}
	*arr = '\0';
	ft_strrev(head, ft_strlen(head));
	return (head);
}
