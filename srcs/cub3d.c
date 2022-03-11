/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:18:17 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 13:35:00 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	int 	i;
	t_data	data;

	i = 0;
	if (ac != 2)
		ft_error("usage : ./cub3d (map).cub");
	data.ml = mlx_init();
	init_the_map(av[1], &data);
	// ********* test ********
	if (check_if_all_fill(&data))
		ft_putendl_fd("colors and texters are not finished", STDOUT_FILENO);
	else
		ft_putendl_fd("all colors and texters are finished", STDOUT_FILENO);
	ft_putendl_fd("***************************the map ********************************\n", STDOUT_FILENO);
	while (data.map[i])
	{
		ft_putendl_fd(data.map[i], STDOUT_FILENO);
		i++;
	}
	ft_putendl_fd("\n***************************the map ********************************\n", STDOUT_FILENO);
	// ***********************
	//mlx_loop(data.ml);
	return (EXIT_SUCCESS);
}
