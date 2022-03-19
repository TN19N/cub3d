/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:04:33 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/19 15:40:20 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	sound(int i)
{
	if (i == 1)
		system("afplay sounds/door_open.mp3 &> /dev/null &");
	else if (i == 2)
		system("afplay sounds/door_close.mp3 &> /dev/null &");
	else if (i == 3)
		system("afplay sounds/gun_shoot.mp3 &> /dev/null &");
	else if (i == 4)
		system("afplay sounds/relaod_sound.mp3 &> /dev/null &");
}
