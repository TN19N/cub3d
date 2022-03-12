/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:24:31 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/12 13:38:39 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# define WINDOW_HIEGHT 480
# define WINDOW_WIDTH 640

# define TEXTER_HIEGHT 64
# define TEXTER_WIDTH 64

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char	spawning;
}			t_player;

typedef struct s_data
{
	void		*ml;
	void		*wi;
	void		*no_texture;
	void		*so_texture;
	void		*we_texture;
	void		*ea_texture;
	int			*floor_color;
	int			*ceilling_color;
	t_player	pl;
	char		**map;
}		t_data;

void	init_the_map(char *map_name, t_data *data);
void	get_colors(char *color, int **ptr);
void	get_xpm_files(char *file_path, void **ptr, void *ml);
void	add_to_map(t_data *data, char *line);
void	check_map(t_data *data);
void	strat_ray(t_data *data);

#endif