/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:21:44 by aqrafi            #+#    #+#             */
/*   Updated: 2025/03/05 21:02:50 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	chek_chr(char *str, t_list *lst)
{
	int	flag;
	int	flag_E;

	flag = 0;
	flag_E = 0;
	if (!str)
		return ;
	while (*str)
	{
		if (*str != '1' && *str != '0' && *str != 'E' && *str != 'P'
			&& *str != 'C' && *str != '\n')
		{
			free(str);
			ft_error("Error\nUndefined component symbol. \n", lst);
		}
		if (*str == 'P')
			flag++;
		str++;
	}
	if (flag != 1)
	{
		free(str);
		ft_error("Error\nThe map contains more or less than one player (P).\n", lst);
	}
}

void	chek_walls(t_list *lst)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	j = 0;
	while (lst->map[len])
		len++;
	len--;
	while (lst->map[0][j] && lst->map[len][j])
	{
		if (lst->map[0][j] != '1' || lst->map[len][j] != '1')
			ft_error("Error\nThe map is disclose", lst);
		j++;
	}
	j = str_len(lst->map[i]) - 1;
	while (lst->map[i])
	{
		if (lst->map[i][0] != '1' || lst->map[i][j] != '1')
			ft_error("Error\nThe map is disclose", lst);
		i++;
	}
}

void	chek_len(int len, int len2, char *map, char *line, t_list *lst)
{
	if (len2 == 0)
		return ;
	else if (len != len2)
	{
		free(line);
		free(map);
		ft_error("Error\nThe map is not rectangular\n",lst);
	}
	return ;
}

void	chek_acc(t_list *lst)
{
	int c_cnt;
	find_P_pos(lst->map, lst);
	c_cnt = C_cnt(lst->map);
	flood_fill(lst->x, lst->y, lst);
	if (lst->C_cnt != c_cnt)
	{
		ft_error("error in the map acc", lst);
	}
	if (lst->E_cnt != 1)
	{
		ft_error("error in the map exit", lst);
	}
	return ;
}