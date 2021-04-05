/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:08:40 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/08 14:13:47 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_error(int flag, t_all *a)
{
	if (flag == 1 || flag == 3)
	{
		if (flag == 1)
			perror("Error\nInvalid map or configs");
		if (flag == 3)
			perror("Error\nEmpty space in map");
		free_all(a);
	}
	if (flag == 2)
		perror("Error\nWrong number of players");
}

static void	arguments_error(int flag)
{
	if (flag == 4)
		perror("Error\nWrong number of arguments");
	if (flag == 5)
		perror("Error\nInvalid file");
	if (flag == 6)
		perror("Error\nInvalid 'save' argument");
}

static void	config_error(int flag)
{
	if (flag == 7)
		perror("Error\nInvalid resolution");
	if (flag == 8)
		perror("Error\nInvalid textures or sprite config");
	if (flag == 9)
		perror("Error\nInvalid color config");
}

int			error(int flag, t_all *a)
{
	if (flag > 0 && flag < 4)
		map_error(flag, a);
	if (flag > 3 && flag < 7)
		arguments_error(flag);
	if (flag > 6 && flag < 10)
		config_error(flag);
	if (flag == 10)
		perror("Error\nImage failed");
	exit(0);
}
