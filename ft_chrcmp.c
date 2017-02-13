/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:22:43 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/09 17:04:59 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrcmp(const char c1, const char c2)
{
	unsigned char	ch1;
	unsigned char	ch2;

	ch1 = (unsigned char)c1;
	ch2 = (unsigned char)c2;
	return (ch1 - ch2);
}
