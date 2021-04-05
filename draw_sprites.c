/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 07:52:27 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/10 14:50:49 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	my_mlx_sprite_put(t_all *all, int y, int x, t_vec sp)
{
	char			*dst;
	unsigned int	color;

	dst = all->data->addr + (y * all->data->len + x *
		(all->data->bpp / 8));
	color = *(unsigned int*)(all->tex->addr[4] +
		(sp.y * all->sp->len + sp.x * (all->sp->bpp / 8)));
	if (color == 0xff000000)
		return ;
	*(unsigned int*)dst = color;
}

static void	sprite_vert_line(t_all *a, int sph, int sp_x, int step)
{
	t_vec	sp;
	int		y;
	int		d;

	sp.x = sp_x;
	y = a->sp->drawsy;
	while (y <= a->sp->drawey)
	{
		d = y * a->sp->s_h * 4 - a->map->res_y *
			a->sp->s_h * 2 + sph * a->sp->s_h * 2;
		sp.y = ((d * a->sp->s_h) / sph) / (a->sp->s_h * 4 + 1);
		if (sp.y >= a->sp->s_h)
			break ;
		my_mlx_sprite_put(a, y, step, sp);
		y++;
	}
}

static void	put_sprites(t_all *a, int sph, int spw, int spscreenx)
{
	int		step;
	int		sp_x;

	step = a->sp->drawsx;
	while (step < a->sp->drawex)
	{
		sp_x = (int)((step - (spscreenx - spw / 2)) * a->sp->s_h / spw);
		if (a->sp->trsformy > 0 && step > 0 && step < a->map->res_x &&
			a->sp->trsformy < a->sp->zb[step] && sp_x < a->sp->s_w)
			sprite_vert_line(a, sph, sp_x, step);
		step++;
	}
}

void		draw_sprites(t_all *a, int spscreenx)
{
	int		sph;
	int		spw;

	sph = (int)fabs((float)a->map->res_y / a->sp->trsformy * a->coef_res);
	a->sp->drawsy = a->map->res_y / 2 - sph / 2;
	a->sp->drawsy = (a->sp->drawsy < 0) ? 0 : a->sp->drawsy;
	a->sp->drawey = a->map->res_y / 2 + sph / 2;
	a->sp->drawey = (a->sp->drawey >= a->map->res_y) ?
		a->map->res_y - 1 : a->sp->drawey;
	spw = (int)fabs((float)a->map->res_y / a->sp->trsformy * a->coef_res);
	a->sp->drawsx = spscreenx - spw / 2;
	a->sp->drawsx = (a->sp->drawsx < 0) ? 0 : a->sp->drawsx;
	a->sp->drawex = spscreenx + spw / 2;
	a->sp->drawex = (a->sp->drawex >= a->map->res_x) ?
		a->map->res_x - 1 : a->sp->drawex;
	put_sprites(a, sph, spw, spscreenx);
}
