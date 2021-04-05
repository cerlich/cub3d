/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:26:44 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/14 12:43:24 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static t_bmp	header(t_all *a)
{
	t_bmp header;

	ft_bzero(&header, sizeof(header));
	header.file_size = (a->map->res_y * a->map->res_x) * 4 + 54;
	header.pixeldataoffset = 54;
	header.header_size = 40;
	header.img_h = a->map->res_y;
	header.img_w = a->map->res_x;
	header.planes = 1;
	header.bpp = a->data->bpp;
	header.img_size = (a->map->res_y * a->map->res_x) * 4;
	return (header);
}

int				save(t_all *a)
{
	int				fd;
	t_bmp			bmp;
	int				i;
	unsigned int	*n;

	i = 0;
	fd = open("./cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	if (fd < 0 || a->map->res_x > 16384 || a->map->res_y > 16384)
	{
		perror("Error\nbmp failed");
		exit(0);
	}
	render(a);
	bmp = header(a);
	write(fd, "BM", 2);
	write(fd, &bmp, sizeof(bmp));
	while (i < a->map->res_y)
	{
		n = (unsigned int *)&a->data->addr[(a->map->res_y - i - 1) *
			a->data->len];
		write(fd, n, a->data->len);
		i++;
	}
	close(fd);
	exit(0);
}
