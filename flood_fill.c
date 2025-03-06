/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:57:22 by aqrafi            #+#    #+#             */
/*   Updated: 2025/03/05 20:47:07 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	flood_fill(int x, int y, t_list *lst)
{
	if (x < 0 || y < 0 || !lst->map[x] || !lst->map[x][y])
		return ;
	if (lst->map[x][y] == 'E')
	{
		lst->E_cnt++;
		lst->map[x][y] = 'e';
	}
	if (lst->map[x][y] == 'C')
	{
		lst->C_cnt++;
		lst->map[x][y] = 'c';
	}
	if (lst->map[x][y] == '1' || lst->map[x][y] == 'V' || lst->map[x][y] == 'e'
		|| lst->map[x][y] == 'c')
		return ;
	lst->map[x][y] = 'V';
	flood_fill(x, y - 1, lst);
	flood_fill(x, y + 1, lst);
	flood_fill(x - 1, y, lst);
	flood_fill( x + 1, y, lst);
}
