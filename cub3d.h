/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 222/2/1 13:56:27 by hait-moh          #+#    #+#             */
/*   Updated: 222/2/1 15:17:1 by hait-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*blank_img;
	void	*mlx;
	void	*mlx_win;
	int		fired;
	int		fire_index;
	int		gun_reload;
	int		reload_index;
}	t_data;

char    *ft_itoa(int n);

#endif