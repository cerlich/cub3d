/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:43:28 by cerlich           #+#    #+#             */
/*   Updated: 2020/11/04 17:14:15 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(long long n)
{
	int			i;
	long long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb / 10 == 0)
		return (i + 1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char		*reverse(char *s)
{
	int i;
	int j;
	int c;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
	return (s);
}

char			*ft_itoa(long long int n)
{
	int				i;
	int				j;
	long long		s;
	char			*p;

	j = 0;
	s = n;
	i = len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(p = (char *)ft_calloc(i + 1, 1)))
		return (0);
	if (n < 0)
		n *= -1;
	while (i--)
	{
		p[j++] = n % 10 + '0';
		n = n / 10;
		if (s < 0 && i == 1)
		{
			p[j] = '-';
			break ;
		}
	}
	return (reverse(p));
}
