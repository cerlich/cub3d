/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:54:25 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/10 21:05:13 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static int	check_empty(char **map, int y, int x)
{
	if (map[y - 1][x] == ' ' || map[y - 1][x] == '\0')
		return (0);
	else if (map[y][x - 1] == ' ' || map[y][x - 1] == '\0')
		return (0);
	else if (map[y][x + 1] == ' ' || map[y][x + 1] == '\0')
		return (0);
	else if (map[y + 1][x] == ' ' || map[y + 1][x] == '\0')
		return (0);
	else
		return (1);
}

int			check_empty_space(t_all *a, int y, int x)
{
	int len_new;
	int len_old;

	if (!(check_empty(a->map->map, (int)a->plr->posy, (int)a->plr->posx)))
		return (error(3, a));
	while (a->map->map[++y])
	{
		x = 0;
		while (a->map->map[y][++x])
		{
			if (a->map->map[y][x] == '0' || a->map->map[y][x] == '2')
			{
				len_old = (int)ft_strlen(a->map->map[y - 1]);
				len_new = (int)ft_strlen(a->map->map[y + 1]);
				if (x > len_new || x > len_old)
					return (error(3, a));
				if (!(check_empty(a->map->map, y, x)))
					return (error(3, a));
			}
		}
	}
	return (1);
}
