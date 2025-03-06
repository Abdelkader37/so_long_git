/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:09:47 by aqrafi            #+#    #+#             */
/*   Updated: 2025/03/05 20:59:39 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
int	C_cnt(char **map)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}
void	freemap(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
t_list	*init_list(void)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	list->C_cnt = 0;
	list->E_cnt = 0;
	list->x = 0;
	list->y = 0;
	list->map = NULL;
	return (list);
}

void	ft_error(char *str, t_list *lst)
{
	if (lst)
	{
		freemap(lst->map);
		free(lst);
	}
	perror(str);
	exit(1);
}