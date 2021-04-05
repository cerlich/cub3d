/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 07:48:36 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/12 12:32:14 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	tex_put(t_all *a, int x, int y, int num)
{
	char			*dst;
	int				t_x;
	int				t_y;
	unsigned int	color;

	a->tex->texy = (int)a->tex->textpos;
	a->tex->texy = (a->tex->texy > (a->tex->t_h[num] - 1)) ?
		a->tex->t_h[num] - 1 : a->tex->texy;
	a->tex->textpos += a->tex->step;
	t_x = a->tex->texx;
	t_y = a->tex->texy;
	dst = a->data->addr + (y * a->data->len + x * (a->data->bpp / 8));
	color = *(unsigned int*)(a->tex->addr[num] +
		(t_y * a->tex->len[num] + t_x * (a->tex->bpp[num] / 8)));
	if (color == 0xff000000)
		return ;
	*(unsigned int*)dst = color;
}

static void	my_pixel_put(t_data *data, int x, int y, int c)
{
	char *dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int*)dst = (unsigned int)c;
}

static void	diff_walls(t_all *a, int x, int side, int y)
{
	while (++y < a->map->res_y)
	{
		if (y < a->map->res_y / 2)
			my_pixel_put(a->data, x, y, a->color_c);
		else
			my_pixel_put(a->data, x, y, a->color_f);
		if (y >= a->scr->dstart && y <= a->scr->dend)
		{
			if (side == 0 && a->scr->stepx > 0)
				tex_put(a, x, y, 3);
			if (side == 0 && a->scr->stepx < 0)
				tex_put(a, x, y, 2);
			if (side == 1 && a->scr->stepy > 0)
				tex_put(a, x, y, 0);
			if (side == 1 && a->scr->stepy < 0)
				tex_put(a, x, y, 1);
		}
	}
}

static void	calculate_tex_coor(int num, t_all *a, int side)
{
	a->tex->step = (float)a->tex->t_h[num] / a->scr->line_h;
	a->tex->textpos = (a->scr->dstart - a->map->res_y / 2 +
		a->scr->line_h / 2) * a->tex->step;
	a->tex->texx = (int)(a->tex->wallx * (float)(a->tex->t_w[num]));
	if (side == 0 && a->scr->rdirx > 0)
		a->tex->texx = a->tex->t_w[num] - a->tex->texx - 1;
	if (side == 1 && a->scr->rdiry < 0)
		a->tex->texx = a->tex->t_w[num] - a->tex->texx - 1;
}

void		draw_walls(t_all *a, int side, int x)
{
	a->sp->zb[x] = a->scr->perpwdist;
	if (side == 0)
		a->tex->wallx = a->plr->posy +
			a->scr->perpwdist * a->scr->rdiry;
	else
		a->tex->wallx = a->plr->posx +
			a->scr->perpwdist * a->scr->rdirx;
	a->tex->wallx -= floor(a->tex->wallx);
	if (side == 0 && a->scr->stepx > 0)
		calculate_tex_coor(3, a, side);
	if (side == 0 && a->scr->stepx < 0)
		calculate_tex_coor(2, a, side);
	if (side == 1 && a->scr->stepy > 0)
		calculate_tex_coor(0, a, side);
	if (side == 1 && a->scr->stepy < 0)
		calculate_tex_coor(1, a, side);
	diff_walls(a, x, side, -1);
}
