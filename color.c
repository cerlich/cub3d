/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:54:32 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/05 23:25:09 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static int	check_color(char *line)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			break ;
		if (!(ft_isdigit(line, i)))
			return (0);
		while (ft_isdigit(line, i))
			i++;
		num++;
		if (num < 3 && line[i] != ',')
			return (0);
		if (num < 3 && line[i] == ',')
			i++;
	}
	if (num != 3)
		return (0);
	return (1);
}

int			get_color_f(t_all *a, char *line)
{
	int i;

	i = 0;
	if (ft_atoi(&line[i + 1]) > 255 || ft_atoi(&line[i + 1]) < 0)
		return (0);
	a->color_f = (ft_atoi(&line[i]) << 16);
	while (ft_isdigit(line, i) || line[i] == ' ')
		i++;
	if (line[i] != ',' || ft_atoi(&line[i + 1]) > 255 ||
		ft_atoi(&line[i + 1]) < 0)
		return (0);
	a->color_f += (ft_atoi(&line[i + 1]) << 8);
	i++;
	while (ft_isdigit(line, i) || line[i] == ' ')
		i++;
	if (line[i] != ',' || ft_atoi(&line[i + 1]) > 255 ||
		ft_atoi(&line[i + 1]) < 0)
		return (0);
	a->color_f += ft_atoi(&line[i + 1]);
	i++;
	while (ft_isdigit(line, i) || line[i] == ' ')
		i++;
	return (check_color(line));
}

int			get_color_c(t_all *a, char *line)
{
	int i;

	i = 0;
	if (ft_atoi(&line[i + 1]) > 255 || ft_atoi(&line[i + 1]) < 0)
		return (0);
	a->color_c = (ft_atoi(&line[i]) << 16);
	while (ft_isdigit(line, i) || line[i] == ' ')
		i++;
	if (line[i] != ',' || ft_atoi(&line[i + 1]) > 255 ||
		ft_atoi(&line[i + 1]) < 0)
		return (0);
	a->color_c += (ft_atoi(&line[i + 1]) << 8);
	i++;
	while (ft_isdigit(line, i) || line[i] == ' ')
		i++;
	if (line[i] != ',' || ft_atoi(&line[i + 1]) > 255 ||
		ft_atoi(&line[i + 1]) < 0)
		return (0);
	a->color_c += ft_atoi(&line[i + 1]);
	i++;
	while (ft_isdigit(line, i) || line[i] == ' ')
		i++;
	return (check_color(line));
}
