/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:42:58 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/16 16:45:17 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

# include <stdio.h>

int	add_darck(int color, t_math *math)
{
	int	r;
	int	b;
	int	g;

	(void)math;
	r = get_r(color);
	b = get_b(color);
	g = get_g(color);
	r = r / 2;
	b = b / 2;
	g = g / 2;
	return (0x0 << 24 | r << 16 | g << 8 | b);
}
