/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:54:50 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/05 23:47:34 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static void	free_map(t_all *a)
{
	int i;

	i = 0;
	while (a->map->map[i])
	{
		free(a->map->map[i]);
		a->map->map[i] = NULL;
		i++;
	}
}

static void	free_settings(t_all *a)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (a->tex->path[i])
		{
			free(a->tex->path[i]);
			a->tex->path[i] = NULL;
		}
		i++;
	}
}

void		free_all(t_all *a)
{
	free_map(a);
	free_settings(a);
}
