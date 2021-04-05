/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:45:33 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/14 13:06:18 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static int	check_numbers(char *line)
{
	int n;
	int i;

	n = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			i++;
		if (ft_isdigit1(line[i]))
		{
			n++;
			while (ft_isdigit1(line[i]))
				i++;
		}
	}
	if (n > 2 || n < 2)
		return (0);
	return (1);
}

static void	check_max_res(t_all *a)
{
	int w;
	int h;

	if (a->flag == 0)
	{
		mlx_get_screen_size(&w, &h);
		if (a->map->res_x > w)
			a->map->res_x = w;
		if (a->map->res_y > h)
			a->map->res_y = h;
	}
	if (a->flag == 1)
	{
		if (a->map->res_x > 16384 || a->map->res_y > 16384)
		{
			perror("Error\nBmp failed, too hight resolution");
			exit(0);
		}
	}
}

int			resolution(t_all *a, char *line, int i)
{
	while (line[++i])
	{
		if (line[i] != ' ' && (!ft_isdigit1(line[i])))
			return (0);
		if (ft_isdigit1(line[i]) && a->map->res_x == 0)
		{
			a->map->res_x = ft_atoi(&line[i]);
			while (ft_isdigit1(line[i]))
				i++;
		}
		if (a->map->res_x != 0)
			if (ft_isdigit1(line[i]))
			{
				a->map->res_y = ft_atoi(&line[i]);
				while (ft_isdigit1(line[i]))
					i++;
			}
		if (line[i] == '\0')
			break ;
	}
	check_max_res(a);
	if (a->map->res_x == 0 || a->map->res_y == 0 || !(check_numbers(line)))
		return (0);
	return (1);
}

static int	texture_path(t_all *a, char *line, int i, int index)
{
	static t_tex	tex;

	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		index = 0;
	if (line[0] == 'N' && line[2] == ' ')
		index = 1;
	if (line[0] == 'W' && line[2] == ' ')
		index = 2;
	if (line[0] == 'E' && line[2] == ' ')
		index = 3;
	i = 2;
	if (line[0] == 'S' && line[1] == ' ')
	{
		i = 1;
		index = 4;
	}
	if (line[i] == '\0' || index == -1)
		return (0);
	if (!(tex.path[index] = ft_strtrim(&line[i], " ")))
		return (0);
	if (ft_strncmp(&tex.path[index][ft_strlen(tex.path[index]) -
		4], ".xpm", 4))
		return (0);
	a->tex = &tex;
	return (1);
}

int			check_textures(t_all *a, char *line, int i)
{
	if (((line[0] == 'S' || line[0] == 'N') ||
		(line[0] == 'W' && line[1] == 'E') ||
		(line[0] == 'E' && line[1] == 'A')))
	{
		if (!(texture_path(a, line, 0, -1)))
			return (error(8, a));
		i++;
	}
	if (line[0] != 'S' && line[0] != 'N' &&
		line[0] != 'W' && line[0] != 'E' && line[0] != 'R'
		&& line[0] != 'F' && line[0] != 'C')
	{
		perror("Invalid map or configs");
		exit(0);
	}
	return (i);
}
