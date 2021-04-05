/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:32:02 by cerlich           #+#    #+#             */
/*   Updated: 2020/11/07 14:32:59 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			l;
	unsigned int	i;

	if (!s)
		return (0);
	i = start;
	while (s[i] != '\0' && len--)
		i++;
	l = i - start + 1;
	if (start >= ft_strlen(s))
		l = 1;
	if (!(sub = (char *)malloc(l)))
		return (0);
	i = 0;
	while (l > 1)
	{
		sub[i++] = s[start++];
		l--;
	}
	sub[i] = '\0';
	return (sub);
}
