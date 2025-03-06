/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:58:03 by aqrafi            #+#    #+#             */
/*   Updated: 2025/03/05 21:21:02 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

// # include <mlx.h>
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_tlist
{
	int	x;
	int	y;
	int	C_cnt;
	int	E_cnt;
	char	**map;

}		t_list;

int		str_len(char *s);
void	ft_error(char *str, t_list *lst);
char	**ft_split(char const *s, char c);
void	chek_len(int len, int len2, char *map, char *line , t_list *lst);
void	get_map(int fd, t_list	*list);
void	chek_chr(char *str, t_list *lst);
void	chek_walls(t_list *lst);
void	flood_fill(int x, int y, t_list *lst);
int		C_cnt(char **map);
void	find_P_pos(char **map, t_list *list);
void	chek_acc(t_list *lst);
void	freemap(char **str);
t_list	*init_list(void);

#endif