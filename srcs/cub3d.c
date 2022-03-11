/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:18:17 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 07:52:31 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		ft_putendl_fd("invalid arguments : usage : ./cub3d (map).cub", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}