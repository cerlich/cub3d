/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:40:05 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 20:11:15 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t		reverse(char const *s1, char const *set, size_t n)
{
	size_t		j;

	j = 0;
	while (n--)
	{
		while (s1[n] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			break ;
		j = 0;
	}
	return (n);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		n;
	size_t		j;
	char		*p;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] != '\0')
	{
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			break ;
		j = 0;
		i++;
	}
	n = reverse(s1, set, ft_strlen(s1));
	p = ft_substr(s1, i, n - i + 1);
	return (p);
}
