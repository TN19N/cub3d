/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:24:31 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/13 08:50:32 by mannouao         ###   ########.fr       */
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

typedef struct s_math
{
	int	**buffer;
	double tex_pos;
	double step;
	int tex_x;
	double	camera_x;
	int side;
	int step_x;
	int step_y;
	int line_height;
	double perp_wall_dist;
	double side_dist_x;
	double side_dist_y;
	double	raydir_x;
	double	raydir_y;
	double delta_dist_x;
	double delta_dist_y;
	int map_x;
	int map_y;
	double	wall_x;
	int		draw_start;
	int		draw_end;
	int 	tex_y;
}				t_math;

typedef	struct s_texture
{
	void	*texture;
	int		bits_per_pixl;
	int		hight;
	int		width;
	char	*info;
}				t_texture;

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
	t_texture	no_t;
	t_texture	so_t;
	t_texture	we_t;
	t_texture	ea_t;
	int			*floor_color;
	int			*ceilling_color;
	t_player	pl;
	t_math      math;
	char		**map;
}		t_data;

void	init_the_map(char *map_name, t_data *data);
void	get_colors(char *color, int **ptr);
void	get_xpm_files(char *file_path, t_texture *t, void *ml);
void	add_to_map(t_data *data, char *line);
void	check_map(t_data *data);
void	strat_ray(t_data *data);
void	draw_walls(t_data *data);
void	draw_buffer(int **buffer, t_data *data);
void	get_delta_dist(t_math *m);
int		**init_buffer(void);

#endif