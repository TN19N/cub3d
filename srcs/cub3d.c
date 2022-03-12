/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:18:17 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/12 18:08:15 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
# include <stdio.h>

void	mega_init(t_data *data)
{
	data->pl.dir_x = -1.0;
	data->pl.dir_y = 0.0;
	data->pl.plane_x = 0.0;
	data->pl.plane_y = 0.66;
}

int move_player(int key, void *v_data)
{
	t_data *data = (t_data *)v_data;

	(void)data;
	printf(" --[%d]\n", key);
	return (0);
}

int	main(int ac, char **av)
{
	int 	i;
	t_data	data;

	i = 0;
	if (ac != 2)
		ft_error("usage : ./cub3d (map).cub");
	mega_init(&data);
	data.ml = mlx_init();
	init_the_map(av[1], &data);
	// ********* test ********
	// if (check_if_all_fill(&data))
	// 	ft_putendl_fd("colors and texters are not finished", STDOUT_FILENO);
	// else
	// 	ft_putendl_fd("all colors and texters are finished", STDOUT_FILENO);
	data.wi = mlx_new_window(data.ml, WINDOW_WIDTH, WINDOW_HIEGHT, "cub3d");
	strat_ray(&data);
	// ft_putendl_fd("***************************the map ********************************\n", STDOUT_FILENO);
	// while (data.map[i])
	// {
	// 	ft_putendl_fd(data.map[i], STDOUT_FILENO);
	// 	i++;
	// }
	// ft_putendl_fd("\n***************************the map ********************************\n", STDOUT_FILENO);
	//system("leaks cub3d");
	// ***********************
	//mlx_key_hook(data.ml, &move_player, &data);
	mlx_loop(data.ml);
	return (EXIT_SUCCESS);
}
