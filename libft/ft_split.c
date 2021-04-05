/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:24:36 by cerlich           #+#    #+#             */
/*   Updated: 2020/11/06 21:41:57 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		count_str(char const *s, char c)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c))
			j++;
		i++;
	}
	return (j);
}

static size_t		len_str(char const *s, char c, size_t n)
{
	size_t	j;

	j = 0;
	while (s[n] != c && s[n] != '\0')
	{
		j++;
		n++;
	}
	return (j);
}

static void			**memory_free(char **buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
		free(buf[i++]);
	free(buf);
	return (0);
}

static char			*splitted(char const *s, char c, size_t n, char **buf)
{
	size_t	len;
	size_t	i;
	char	*res;

	i = 0;
	len = len_str(s, c, n);
	if (!(res = (char *)ft_calloc(len + 1, sizeof(char))))
	{
		memory_free(buf);
		return (0);
	}
	while (s[n] != c && s[n] != '\0')
		res[i++] = s[n++];
	return (res);
}

char				**ft_split(char const *s, char c)
{
	char	**res;
	char	**buf;
	size_t	i;
	size_t	count;

	i = -1;
	buf = NULL;
	count = count_str(s, c);
	if (!(res = (char **)ft_calloc(count + 1, sizeof(char *))))
		return (0);
	if (count == 0)
	{
		*res = (char *)'\0';
		return (res);
	}
	buf = res;
	while (++i < ft_strlen(s) - 1)
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c))
			*res++ = splitted(s, c, ((i == 0 && s[i] != c) ? 0 : i + 1), buf);
	}
	return (buf);
}
