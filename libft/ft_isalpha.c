/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:24:18 by cerlich           #+#    #+#             */
/*   Updated: 2020/12/10 20:03:58 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha1(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int		ft_isalpha(const char *fmt, int i)
{
	if (fmt[i] == 'd' || fmt[i] == 'i' || fmt[i] == 'c' ||
		fmt[i] == 's' || fmt[i] == 'u' || fmt[i] == 'p' ||
		fmt[i] == 'x' || fmt[i] == 'X')
		return (1);
	return (0);
}
