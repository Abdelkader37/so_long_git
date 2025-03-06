/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqrafi <aqrafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:59:27 by aqrafi            #+#    #+#             */
/*   Updated: 2025/03/05 21:09:33 by aqrafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char *av[])
{
	void	*mlx;
	t_list	*lst;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_error("Error\nCould not open file.", NULL);
		lst = init_list();
		get_map(fd, lst);
		chek_walls(lst);
		chek_acc(lst);
	}
}
