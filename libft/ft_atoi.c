/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:06:25 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/12 08:20:00 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi2(const char *str, int i)
{
	int res;
	int num;

	res = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9' && num < 7)
	{
		res = res * 10 + (str[i] - 48);
		i++;
		num++;
	}
	return (res);
}

int			ft_atoi(const char *str)
{
	int i;
	int n;
	int res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f'
			|| str[i] == '0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	res = ft_atoi2(str, i);
	return (res * n);
}
