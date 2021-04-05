/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerlich <cerlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 06:55:26 by cerlich           #+#    #+#             */
/*   Updated: 2021/03/10 16:23:12 by cerlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static int	make_map(t_all *all, t_list *head)
{
	t_list	*tmp;
	int		n;

	n = -1;
	tmp = head;
	while (tmp)
	{
		all->map->map[++n] = tmp->content;
		tmp = tmp->next;
	}
	delete_list(head);
	if (!(check_map(all->map->map, all)))
		return (error(1, all));
	return (1);
}

int			parser_map(t_all *all, int fd)
{
	char	*line;
	t_list	*head;
	int		flag;

	flag = 0;
	line = NULL;
	head = NULL;
	while (get_next_line(fd, &line))
	{
		if (flag == 0 && line[0] == '\0')
		{
			free(line);
			continue;
		}
		ft_lstadd_back(&head, ft_lstnew(line));
		flag = 1;
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	all->map->size = ft_lstsize(head);
	all->map->map = ft_calloc(all->map->size + 1, sizeof(char *));
	if (!(make_map(all, head)))
		return (0);
	return (1);
}
