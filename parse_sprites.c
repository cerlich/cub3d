/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:55:36 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/10 14:53:54 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static void	player_position(t_all *a)
{
	if (a->pl == 'N' || a->pl == 'S')
	{
		a->plr->dirx = 0;
		a->plr->diry = 1.0;
		a->plr->planex = -0.66;
		a->plr->planey = 0;
		if (a->pl == 'N')
		{
			a->plr->diry = -1.0;
			a->plr->planex = 0.66;
		}
	}
	else if (a->pl == 'W' || a->pl == 'E')
	{
		a->plr->dirx = -1.0;
		a->plr->diry = 0;
		a->plr->planex = 0;
		a->plr->planey = -0.66;
		if (a->pl == 'E')
		{
			a->plr->dirx = 1.0;
			a->plr->planey = 0.66;
		}
	}
}

static int	number_sprites(t_all *a, int x, int y)
{
	a->sp->num = 0;
	while (a->map->map[++y])
	{
		x = -1;
		while (a->map->map[y][++x])
		{
			if (a->map->map[y][x] == '2')
				a->sp->num++;
		}
	}
	if (!(a->sp->smapx = malloc(sizeof(float) * a->sp->num)))
		return (0);
	if (!(a->sp->smapy = malloc(sizeof(float) * a->sp->num)))
		return (0);
	player_position(a);
	return (1);
}

int			parse_sprites(t_all *a, int y, int x)
{
	if (!(number_sprites(a, -1, -1)))
	{
		perror("Invalid sprites");
		return (0);
	}
	a->sp->num = 0;
	while (a->map->map[++y])
	{
		x = -1;
		while (a->map->map[y][++x])
		{
			if (a->map->map[y][x] == '2')
			{
				a->sp->smapx[a->sp->num] = (float)x + 0.5;
				a->sp->smapy[a->sp->num] = (float)y + 0.5;
				a->sp->num++;
			}
		}
	}
	a->map->map[(int)a->plr->posy][(int)a->plr->posx] = '0';
	return (1);
}
