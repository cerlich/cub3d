/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:55:31 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/14 12:33:34 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot(t_all *all, int key, float rs)
{
	float olddir;
	float oldplane;

	olddir = all->plr->dirx;
	oldplane = all->plr->planex;
	if (key == 123)
	{
		all->plr->dirx = all->plr->dirx *
			cos(-rs) - all->plr->diry * sin(-rs);
		all->plr->diry = olddir * sin(-rs) + all->plr->diry * cos(-rs);
		all->plr->planex = all->plr->planex *
			cos(-rs) - all->plr->planey * sin(-rs);
		all->plr->planey = oldplane * sin(-rs) +
			all->plr->planey * cos(-rs);
	}
	if (key == 124)
	{
		all->plr->dirx = all->plr->dirx * cos(rs)
			- all->plr->diry * sin(rs);
		all->plr->diry = olddir * sin(rs) + all->plr->diry * cos(rs);
		all->plr->planex = all->plr->planex *
			cos(rs) - all->plr->planey * sin(rs);
		all->plr->planey = oldplane * sin(rs) + all->plr->planey * cos(rs);
	}
}

void	move_left(t_all *all, float ms)
{
	if (all->map->map[(int)(all->plr->posy +
		all->plr->dirx * ms)][(int)(all->plr->posx)] != '1')
		all->plr->posy += all->plr->dirx * ms;
	if (all->map->map[(int)(all->plr->posy)][(int)(all->plr->posx -
		all->plr->diry * ms)] != '1')
		all->plr->posx -= all->plr->diry * ms;
}

void	move_right(t_all *all, float ms)
{
	if (all->map->map[(int)(all->plr->posy -
		all->plr->dirx * ms)][(int)(all->plr->posx)] != '1')
		all->plr->posy -= all->plr->dirx * ms;
	if (all->map->map[(int)(all->plr->posy)][(int)(all->plr->posx +
		all->plr->diry * ms)] != '1')
		all->plr->posx += all->plr->diry * ms;
}

void	move_up(t_all *all, float ms)
{
	if (all->map->map[(int)(all->plr->posy)][(int)(all->plr->posx +
		all->plr->dirx * ms)] != '1' &&
		all->map->map[(int)(all->plr->posy)][(int)(all->plr->posx +
		all->plr->dirx * ms)] != '2')
		all->plr->posx += all->plr->dirx * ms;
	if (all->map->map[(int)(all->plr->posy +
		all->plr->diry * ms)][(int)(all->plr->posx)] != '1'
		&& all->map->map[(int)(all->plr->posy +
		all->plr->diry * ms)][(int)(all->plr->posx)] != '2')
		all->plr->posy += all->plr->diry * ms;
}

void	move_down(t_all *all, float ms)
{
	if (all->map->map[(int)(all->plr->posy)][(int)(all->plr->posx -
		all->plr->dirx * ms)] != '1' &&
		all->map->map[(int)(all->plr->posy)][(int)(all->plr->posx -
		all->plr->dirx * ms)] != '2')
		all->plr->posx -= all->plr->dirx * ms;
	if (all->map->map[(int)(all->plr->posy -
		all->plr->diry * ms)][(int)(all->plr->posx)] != '1' &&
		all->map->map[(int)(all->plr->posy -
		all->plr->diry * ms)][(int)(all->plr->posx)] != '2')
		all->plr->posy -= all->plr->diry * ms;
}
