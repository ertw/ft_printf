/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streveryi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 16:19:11 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/11 17:22:49 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_streveryi(char *ar, int (*f)(char c, int index))
{
	int i;

	if (!ar || !f)
		return (0);
	i = 0;
	while (ar[i])
	{
		if (!f(ar[i], i))
			return (0);
		i++;
	}
	return (1);
}
