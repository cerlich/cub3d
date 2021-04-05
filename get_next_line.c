/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:33:39 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/10 17:47:47 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	n;
	size_t	i;

	i = 0;
	n = count * size;
	if (!(p = malloc(n)))
		return (NULL);
	if (p)
	{
		while (n--)
		{
			*((unsigned char*)p + i) = 0;
			i++;
		}
	}
	return (p);
}

static char		*ft_join(char *line, char *buf)
{
	char	*new;
	int		i;

	i = 0;
	while (line[i] != '\0')
		i++;
	if (!(new = ft_calloc(i + 2, sizeof(char))))
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = buf[0];
	free(line);
	return (new);
}

int				get_next_line(int fd, char **line)
{
	char	buf[2];
	int		bytes;

	if (!line || fd < 0)
		return (-1);
	*line = ft_calloc(1, 1);
	while ((bytes = read(fd, buf, 1)) > 0)
	{
		if (buf[0] == '\0' || buf[0] == '\n')
			break ;
		buf[1] = '\0';
		*line = ft_join(*line, buf);
	}
	if (bytes < 0)
		return (-1);
	if (bytes == 0)
		return (0);
	return (1);
}
