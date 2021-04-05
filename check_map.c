/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:09:18 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/08 14:24:48 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static int	check_first_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_player(t_all *a, char pl, int y, int x)
{
	static t_plr plr;

	if (pl != 'N' && pl != 'E' && pl != 'W' && pl != 'S')
		return (0);
	if (pl == 'N' || pl == 'E' || pl == 'W' || pl == 'S')
	{
		a->num++;
		a->pl = pl;
		plr.posy = y + 0.5;
		plr.posx = x + 0.5;
	}
	a->plr = &plr;
	return (1);
}

static int	check_line(char *line, t_all *a, int i)
{
	int n;

	n = 1;
	if (line[0] != '1' && line[0] != ' ')
		return (0);
	while (line[n] != '\0')
	{
		if (ft_isalpha1(line[n]))
		{
			if (!(check_player(a, line[n], i, n)))
				return (0);
		}
		else if (line[n] != '0' && line[n] != '2' &&
			line[n] != '1' && line[n] != ' ')
			return (0);
		n++;
	}
	if (line[n - 1] == '0')
		return (0);
	return (1);
}

int			check_map(char **map, t_all *a)
{
	int i;

	i = 0;
	a->num = 0;
	if (!(check_first_line(map[0])))
		return (0);
	while (map[++i])
	{
		if (!(check_line(map[i], a, i)))
			return (0);
		if (i < a->map->size - 1 && map[i][0] != '\0' &&
			(map[i - 1][0] == '\0' || map[i + 1][0] == '\0'))
		{
			if (!(check_first_line(map[i])))
				return (0);
		}
	}
	if (!map || !*map || i < 2)
		return (0);
	if (map[i - 1][0] != '\0')
		if (!(check_first_line(map[i - 1])))
			return (0);
	if (i > 1 && (a->num != 1 || !a->pl))
		return (error(2, a));
	return (1);
}
