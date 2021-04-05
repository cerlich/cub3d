/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:07:43 by cerlich           #+#    #+#             */
/*   Updated: 2020/11/07 14:31:59 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;

	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	i = 0;
	if (src1 < dst1)
	{
		while (i++ < len)
			dst1[len - i] = src1[len - i];
	}
	i = 0;
	if (src1 > dst1)
	{
		while (len-- > 0)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dst);
}
