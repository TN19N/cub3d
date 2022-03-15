/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:24:31 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/15 11:04:24 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "libft.h"
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define WINDOW_HIEGHT 640
# define WINDOW_WIDTH 1280

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

# define MOVE_FORWARD 13
# define MOVE_BOCKWARD 1
# define MOVE_LEFT 0
# define MOVE_WRIGHT 2 

# define ROT_LEFT 123
# define ROT_WRIGHT 124

# define ESC 53

# define COLLISION 0.2

# define KEYPRESS 2
# define KEYRELEASE 3
# define DESTROYNOTIFY 17

# define NOEVENTMASK 0L
# define KEYPRESSMASK 1L
# define KEYRELEASEMASK 2L

typedef struct s_math
{
	double	tex_pos;
	double	step;
	int		tex_x;
	double	camera_x;
	int		side;
	int		step_x;
	int		step_y;
	double	floor_step_x;
	double	floor_step_y;
	int		line_height;
	double	perp_wall_dist;
	double	side_dist_x;
	double	side_dist_y;
	double	raydir_x;
	double	raydir_y;
	double	floor_x;
	double	floor_y;
	int		cell_x;
	int		cell_y;
	double	raydir_x1;
	double	raydir_y1;
	double	raydir_x2;
	double	raydir_y2;
	double	delta_dist_x;
	double	delta_dist_y;
	int		map_x;
	int		map_y;
	double	wall_x;
	int		draw_start;
	int		draw_end;
	int		tex_y;
	double	row_distance;
	double	old_side_y;
	double	old_side_x;
}			t_math;

typedef struct s_texture
{
	void	*texture;
	int		bits;
	int		hight;
	int		line_len;
	int		width;
	char	*info;
}			t_texture;

typedef struct s_player
{
	double		col_x;
	double		col_y;
	double		b_col_x;
	double		b_col_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		spawning;
}				t_player;

typedef struct s_data
{
	void		*ml;
	void		*wi;
	t_texture	no_t;
	t_texture	so_t;
	t_texture	we_t;
	t_texture	ea_t;
	t_texture	fl_t;
	t_texture	ce_t;
	t_texture	*tar;
	t_player	pl;
	t_math		math;
	char		**map;
	int			*key_bord;
	t_texture	b_img;
}				t_data;

void	init_the_map(char *map_name, t_data *data);
void	get_colors(char *color, int **ptr);
void	get_xpm_files(char *file_path, t_texture *t, void *ml);
void	add_to_map(t_data *data, char *line);
void	check_map(t_data *data);
void	strat_ray(t_data *data);
void	draw_walls(t_data *data, t_math *math);
void	get_delta_dist(t_math *m);
int		**init_buffer(void);
void	move_player(t_player *p, char **map, double x, double y);
void	rotate_player(t_player *p, double i, double buf);
void	check_col(char **map, double *tmp_y, double *tmp_x);
int		releas_key(int key, t_data *data);
int		press_key(int key, t_data *data);
void	put_in_image(t_data *data, int i, int j, int color);
void	move_side_way(t_player *p, char **map, double i);
void	get_right_one(t_data *data, t_math *m);
void	check_format(char *map_name, char *format);
void	draw_up_down(t_data *data, t_math *math);

#endif