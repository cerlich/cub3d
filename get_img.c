/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:54:56 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/12 08:40:17 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static void	get_texture_addr(t_all *a)
{
	a->tex->addr[0] = mlx_get_data_addr(a->tex->img[0],
		&a->tex->bpp[0], &a->tex->len[0], &a->tex->end[0]);
	a->tex->addr[1] = mlx_get_data_addr(a->tex->img[1],
		&a->tex->bpp[1], &a->tex->len[1], &a->tex->end[1]);
	a->tex->addr[2] = mlx_get_data_addr(a->tex->img[2],
		&a->tex->bpp[2], &a->tex->len[2], &a->tex->end[2]);
	a->tex->addr[3] = mlx_get_data_addr(a->tex->img[3],
		&a->tex->bpp[3], &a->tex->len[3], &a->tex->end[3]);
	a->tex->addr[4] = mlx_get_data_addr(a->tex->img[4],
		&a->sp->bpp, &a->sp->len, &a->sp->end);
}

int			get_texture_img(t_all *a, int error_flag)
{
	if (!(a->tex->img[0] = mlx_xpm_file_to_image(a->mlx, a->tex->path[0],
		&a->tex->t_w[0], &a->tex->t_h[0])))
		error_flag = 1;
	if (!(a->tex->img[1] = mlx_xpm_file_to_image(a->mlx, a->tex->path[1],
		&a->tex->t_w[1], &a->tex->t_h[1])))
		error_flag = 1;
	if (!(a->tex->img[2] = mlx_xpm_file_to_image(a->mlx, a->tex->path[2],
		&a->tex->t_w[2], &a->tex->t_h[2])))
		error_flag = 1;
	if (!(a->tex->img[3] = mlx_xpm_file_to_image(a->mlx, a->tex->path[3],
		&a->tex->t_w[3], &a->tex->t_h[3])))
		error_flag = 1;
	if (!(a->tex->img[4] = mlx_xpm_file_to_image(a->mlx, a->tex->path[4],
		&a->sp->s_w, &a->sp->s_h)))
		error_flag = 1;
	if (error_flag == 1)
		return (error(8, a));
	get_texture_addr(a);
	return (1);
}
