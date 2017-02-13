/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:43:28 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/09 08:17:08 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_wordcount(const char *s, const char c, unsigned int count)
{
	if (!s)
		return (0);
	if (!*s)
		return (count);
	if (*s != c && (s[1] == c || !s[1]))
		return (ft_wordcount(++s, c, ++count));
	if (*s)
		return (ft_wordcount(++s, c, count));
	return (0);
}
