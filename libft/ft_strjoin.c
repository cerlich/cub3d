/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:35:35 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/10 17:47:52 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!(p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (*s1 != '\0')
	{
		*(p + i) = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		*(p + i) = *s2++;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
