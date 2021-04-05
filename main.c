/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:53:33 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/12 14:49:41 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

int		key_pres(int key, t_all *all)
{
	float ms;

	ms = all->map->res_x / (float)(all->map->res_x * 4);
	if (key == 53)
		exit(0);
	if (key == 13)
		move_up(all, ms);
	if (key == 1)
		move_down(all, ms);
	if (key == 2)
		move_left(all, ms);
	if (key == 0)
		move_right(all, ms);
	if (key == 124 || key == 123)
		rot(all, key, 0.09);
	render(all);
	return (0);
}

int		close_win(void)
{
	exit(0);
}

int		main(int argc, char **argv)
{
	t_data		img;
	t_map		map;
	t_sprite	sp;
	t_all		all;

	all.data = &img;
	all.map = &map;
	all.sp = &sp;
	all.mlx = mlx_init();
	if (!(parser(argc, argv, &all)))
		return (0);
	all.win = mlx_new_window(all.mlx, map.res_x, map.res_y, "Cub");
	if (!(img.img = mlx_new_image(all.mlx, map.res_x, map.res_y)))
		return (error(10, &all));
	img.img = mlx_new_image(all.mlx, map.res_x, map.res_y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.end);
	if (argc == 3)
		save(&all);
	render(&all);
	mlx_hook(all.win, 2, 1L << 0, &key_pres, &all);
	mlx_hook(all.win, 17, 1L << 2, &close_win, &all);
	mlx_loop(all.mlx);
	return (0);
}
