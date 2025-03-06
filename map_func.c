/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:02:04 by aqrafi            #+#    #+#             */
/*   Updated: 2025/03/05 21:09:08 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_map(int fd, t_list	*lst)
{
	char	*map;
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = 0;
	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		chek_len(str_len(line), len, map, line, lst);
		len = str_len(line);
		map = ft_strjoin(map, line);
		if (!map)
			return (free(map), free(line));
		free(line);
		i++;
	}
	chek_chr(map, lst);
	lst->map = ft_split(map, '\n');
}


void	find_P_pos(char **map, t_list *lst)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				lst->x = i;
				lst->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
