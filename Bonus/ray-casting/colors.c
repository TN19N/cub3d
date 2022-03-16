/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:42:58 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/16 17:32:17 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d_bonus.h"

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

int	add_darck(int color, float x)
{
	int	r;
	int	b;
	int	g;
	float	per;

	if (x > 10.0)
		return (0);
	per = x / DARCK;
	r = get_r(color);
	b = get_b(color);
	g = get_g(color);
	r -= (r * per);
	b -= (b * per);
	g -= (g * per);
	if (r < 0)
		r = 0;
	if (b < 0)
		b = 0;
	if (g < 0)
		g = 0;
	return (0x0 << 24 | r << 16 | g << 8 | b);
}
