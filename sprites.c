/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:55:46 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/05 23:33:49 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static void	swap_sprites(t_all *a, int y, int x, char c)
{
	float tmp;

	if (c == 'x')
	{
		tmp = a->sp->smapx[y];
		a->sp->smapx[y] = a->sp->smapx[x];
		a->sp->smapx[x] = tmp;
	}
	if (c == 'y')
	{
		tmp = a->sp->smapy[y];
		a->sp->smapy[y] = a->sp->smapy[x];
		a->sp->smapy[x] = tmp;
	}
}

static void	sort_sprites(t_all *a)
{
	int		x;
	int		y;
	float	dist1;
	float	dist2;

	y = 0;
	while (y < a->sp->num - 1)
	{
		dist1 = (powf((a->plr->posx - a->sp->smapx[y]), 2) +
			powf((a->plr->posy - a->sp->smapy[y]), 2));
		x = y + 1;
		while (x < a->sp->num)
		{
			dist2 = (powf((a->plr->posx - a->sp->smapx[x]), 2) +
				powf((a->plr->posy - a->sp->smapy[x]), 2));
			if (dist2 > dist1)
			{
				dist1 = dist2;
				swap_sprites(a, y, x, 'x');
				swap_sprites(a, y, x, 'y');
			}
			x++;
		}
		y++;
	}
}

void		print_sprites(t_all *a)
{
	float	sp_x;
	float	sp_y;
	float	invdet;
	int		spscreenx;
	int		i;

	i = 0;
	sort_sprites(a);
	while (i < a->sp->num)
	{
		sp_x = a->sp->smapx[i] - a->plr->posx;
		sp_y = a->sp->smapy[i] - a->plr->posy;
		invdet = 1.0 / (a->plr->planex * a->plr->diry -
			a->plr->dirx * a->plr->planey);
		a->sp->trsformx = invdet * (a->plr->diry * sp_x -
			a->plr->dirx * sp_y);
		a->sp->trsformy = invdet * (-a->plr->planey * sp_x +
			a->plr->planex * sp_y);
		spscreenx = (int)((a->map->res_x / 2) * (1 +
			a->sp->trsformx / a->sp->trsformy));
		draw_sprites(a, spscreenx);
		i++;
	}
}
