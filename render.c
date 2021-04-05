/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:55:41 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/12 09:25:33 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static void	calculate_height(t_all *a, int side)
{
	if (side == 0)
		a->scr->perpwdist = (a->map->mapx - a->plr->posx +
			(1 - a->scr->stepx) / 2) / a->scr->rdirx;
	else
		a->scr->perpwdist = (a->map->mapy - a->plr->posy +
			(1 - a->scr->stepy) / 2) / a->scr->rdiry;
	a->scr->perpwdist = (a->scr->perpwdist == 0) ? 0.1 :
		a->scr->perpwdist;
	a->coef_res = (a->map->res_y / (float)a->map->res_x);
	a->coef_res = 0.75 / a->coef_res;
	a->scr->line_h = (int)(a->map->res_y / a->scr->perpwdist * a->coef_res);
	a->scr->dstart = a->map->res_y / 2 - a->scr->line_h / 2;
	a->scr->dstart = (a->scr->dstart < 0) ? 0 : a->scr->dstart;
	a->scr->dend = a->map->res_y / 2 + a->scr->line_h / 2;
	a->scr->dend = (a->scr->dend >= a->map->res_y) ? a->map->res_y -
		1 : a->scr->dend;
}

static int	dda(t_all *a)
{
	int hit;
	int side;

	hit = 0;
	while (hit == 0)
	{
		if (a->scr->sidedistx < a->scr->sidedisty)
		{
			a->scr->sidedistx += a->scr->deldistx;
			a->map->mapx += a->scr->stepx;
			side = 0;
		}
		else
		{
			a->scr->sidedisty += a->scr->deldisty;
			a->map->mapy += a->scr->stepy;
			side = 1;
		}
		if (a->map->map[a->map->mapy][a->map->mapx] == '1')
			hit = 1;
	}
	return (side);
}

static void	step(t_all *a)
{
	if (a->scr->rdirx < 0)
	{
		a->scr->stepx = -1;
		a->scr->sidedistx = (a->plr->posx -
			a->map->mapx) * a->scr->deldistx;
	}
	else
	{
		a->scr->stepx = 1;
		a->scr->sidedistx = (a->map->mapx + 1.0 -
			a->plr->posx) * a->scr->deldistx;
	}
	if (a->scr->rdiry < 0)
	{
		a->scr->stepy = -1;
		a->scr->sidedisty = (a->plr->posy -
			a->map->mapy) * a->scr->deldisty;
	}
	else
	{
		a->scr->stepy = 1;
		a->scr->sidedisty = (a->map->mapy + 1.0 -
			a->plr->posy) * a->scr->deldisty;
	}
}

static void	init_camera(t_all *a, int x)
{
	float	camerax;

	camerax = 2 * x / (float)a->map->res_x - 1;
	a->scr->rdirx = a->plr->dirx + a->plr->planex * camerax;
	a->scr->rdiry = a->plr->diry + a->plr->planey * camerax;
	a->map->mapx = (int)a->plr->posx;
	a->map->mapy = (int)a->plr->posy;
	a->scr->deldistx = fabsf(1 / a->scr->rdirx);
	a->scr->deldisty = fabsf(1 / a->scr->rdiry);
}

void		render(t_all *a)
{
	int			x;
	int			side;
	t_screen	scr;

	a->scr = &scr;
	x = -1;
	while (++x < a->map->res_x)
	{
		init_camera(a, x);
		step(a);
		side = dda(a);
		calculate_height(a, side);
		draw_walls(a, side, x);
	}
	print_sprites(a);
	mlx_put_image_to_window(a->mlx, a->win, a->data->img, 0, 0);
}
