/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:58:34 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/17 14:59:35 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_pow2ciel(const char *str, size_t len)
{
	--len;
	len |= len >> 1;
	len |= len >> 2;
	len |= len >> 4;
	len |= len >> 8;
	len |= len >> 16;
	++len;
	return (len);
}
