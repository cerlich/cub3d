/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:48:19 by cerlich           #+#    #+#             */
/*   Updated: 2020/11/10 20:59:21 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	n;
	size_t	i;

	i = 0;
	n = count * size;
	if (!(p = malloc(n)))
		return (NULL);
	if (p)
	{
		while (n--)
		{
			*((unsigned char*)p + i) = 0;
			i++;
		}
	}
	return (p);
}
