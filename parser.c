/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:53:57 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/14 12:53:52 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static int	parser_arguments(int argc, char **argv, int fd, t_all *a)
{
	if (argc < 2 || argc > 3)
		return (error(4, a));
	if (argc > 1 && (!ft_strrchr(argv[1], '.')))
		return (error(5, a));
	if ((argc > 1 &&
		((ft_strncmp(&argv[1][ft_strlen(argv[1]) -
		4], ".cub", 4)) || fd <= 0)))
		return (error(5, a));
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) != 6 || (ft_strncmp(argv[2], "--save", 6)))
			return (error(6, a));
	}
	return (1);
}

static int	config(char *line, t_all *a, int i)
{
	if (line[0] == 'R' && line[1] == ' ')
	{
		if (!(resolution(a, &line[1], -1)))
			return (error(7, a));
		i++;
	}
	if (line[0] == 'F' && line[1] == ' ')
	{
		i++;
		if (!(get_color_f(a, &line[1])))
			return (error(9, a));
	}
	if (line[0] == 'C' && line[1] == ' ')
	{
		i++;
		if (!(get_color_c(a, &line[1])))
			return (error(9, a));
	}
	return (check_textures(a, line, i));
}

static int	parser_config(t_all *a, int fd, int i)
{
	char *line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		if (line[0] != '\0')
		{
			i = config(line, a, i);
			free(line);
		}
		if (i == 8 && a->color_c != -1 && a->color_f != -1)
			return (1);
	}
	perror("Invalid file or configs");
	return (0);
}

static void	initial_struct(t_all *a)
{
	a->color_c = -1;
	a->color_f = -1;
	a->map->res_x = 0;
	a->map->res_y = 0;
}

int			parser(int argc, char **argv, t_all *a)
{
	int fd;

	a->flag = 0;
	fd = open(argv[1], O_RDONLY);
	if (!(parser_arguments(argc, argv, fd, a)))
		return (0);
	if (argc == 3)
		a->flag = 1;
	initial_struct(a);
	if (!(parser_config(a, fd, 0)))
		return (0);
	if (!(a->sp->zb = malloc(sizeof(float) * a->map->res_x)))
		return (0);
	if (!(parser_map(a, fd)))
		return (0);
	if (!check_empty_space(a, 0, 0))
		return (0);
	if (!(get_texture_img(a, 0)))
		return (0);
	if (!(parse_sprites(a, -1, -1)))
		return (0);
	return (1);
}
