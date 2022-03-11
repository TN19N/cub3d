/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:18:17 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 08:37:32 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		ft_putendl_fd("usage : ./cub3d (map).cub", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	check_the_map(av[1], &data);
	return (EXIT_SUCCESS);
}
