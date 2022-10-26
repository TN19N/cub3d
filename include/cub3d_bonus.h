/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:24:31 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/27 13:20:31 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "libft.h"
# include <unistd.h>
# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define WINDOW_HIEGHT 640
# define WINDOW_WIDTH 1000

# define MOVE_SPEED 0.1
# define MOVE_ENEMY 0.15
# define ROT_SPEED 0.05

# define MOVE_FORWARD 13
# define MOVE_BOCKWARD 1
# define MOVE_LEFT 0
# define MOVE_WRIGHT 2 

# define ROT_LEFT 123
# define ROT_WRIGHT 124

# define RELOAD_GUN 15

# define MOUSE_ON_OFF 12
# define ESC 53

# define COLLISION 0.2

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define MOTIONNOTIFY 6
# define DESTROYNOTIFY 17

# define NOEVENTMASK 0L
# define KEYPRESSMASK 1L
# define KEYRELEASEMASK 2L
# define POINTERMOTIONMASK 6L

# define DARCK 7

# define CLOSED 0
# define OPENED 1

# define PATH_DOOR "textures/door/door.png"
# define PATH_ENEMY "../untitled.png"

typedef struct s_data	t_data;

typedef struct s_texture
{
	void	*texture;
	int		bits;
	int		endian;
	int		hight;
	int		line_len;
	int		width;
	char	*info;
}			t_texture;

typedef struct s_axis
{
	int	x;
	int	y;
}	t_axis;

typedef struct s_map
{
	char		**map_content;
	int			map_width;
	t_texture	full_map;
	t_axis		player;
	void		*icon;
	int			endian;
	int			map_height;
}				t_map;

typedef struct s_math_2
{
	float	sprite_x;
	float	sprite_y;
	float	inv_det;
	float	transform_x;
	float	transform_y;
	int		sprite_screen_x;
	int		sprite_height;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		tex_x;
	int		tex_y;
}			t_math_2;

typedef struct s_math
{
	float	tex_pos;
	float	step;
	int		tex_x;
	float	camera_x;
	int		side;
	int		step_x;
	int		step_y;
	int		line_height;
	float	perp_wall_dist;
	float	side_dist_x;
	float	side_dist_y;
	float	raydir_x;
	float	raydir_y;
	float	dist_wall;
	float	dist_player;
	float	current_dist;
	float	floor_x_wall;
	float	floor_y_wall;
	float	current_floor_x;
	float	current_floor_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		map_x;
	int		map_y;
	float	wall_x;
	int		draw_start;
	int		draw_end;
	int		tex_y;
}			t_math;

typedef struct s_player
{
	float		col_x;
	float		col_y;
	float		b_col_x;
	float		b_col_y;
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	char		spawning;
	t_data		*data;
}				t_player;

typedef struct s_gun
{
	void	*blank_img;
	int		fired;
	void	**fire_frames;
	void	**reload_frames;
	void	*idle_frame;
	void	*cursor;
	void	**bullets_frames;
	int		bullets;
	int		frame;
	int		gun_reload;
}	t_gun;

typedef struct s_enemy
{
	float		x;
	float		y;
	float		dest;
	int			frame_index;
	int			zombie_dead;
	int			attacking;
}				t_enemy;

typedef struct s_door
{
	t_texture	do_t;
	int			x;
	int			y;
	int			stat;
}		t_door;

typedef struct s_zombie
{
	t_texture	*walk_frames;
	t_texture	*death_frames;
	t_texture	*attack_frames;
}				t_zombie;

typedef struct s_data
{
	int			mouse_1;
	int			mouse_2;
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
	t_zombie	zombie;
	char		**map;
	t_map		mini_map;
	int			*key_bord;
	t_texture	b_img;
	t_gun		gun;
	int			change;
	int			number_d;
	t_door		*d;
	int			number_e;
	t_enemy		*enemys;
	int			is_enemy[2];
	float		*z_buffer;
	int			mouse_on;
}				t_data;

void	init_the_map(char *map_name, t_data *data);
int		in_range(t_data *data, int i);
void	my_mlx_pixel_put(t_texture *data, int x, int y, int color);
void	get_colors(char *color, int **ptr);
int		pixel_color(t_texture *data, int x, int y);
void	get_png_files(char *file_path, t_texture *t, void *ml);
void	add_to_map(t_data *data, char *line);
void	check_map(t_data *data);
void	strat_ray(t_data *data, int count);
int		hit_enemy(t_data *data, float x, float y, int i);
void	draw_walls(t_data *data, t_math *math);
void	get_delta_dist(t_math *m);
int		**init_buffer(void);
void	move_player(t_player *p, char **map, float x, float y);
void	rotate_player(t_player *p, float i);
void	check_col(char **map, float *tmp_y, float *tmp_x, float collision);
int		releas_key(int key, t_data *data);
int		press_key(int key, t_data *data);
void	put_in_image(t_data *data, int i, int j, int color);
void	move_side_way(t_player *p, char **map, float i);
void	get_right_one(t_data *data, t_math *m);
void	check_format(char *map_name, char *format);
void	draw_up_down(t_data *data, t_math *math, int i);
int		add_darck(int color, float x);
int		mouse(int x, int y, t_data *data);
int		handle_mouse_button(int button, int x, int y, t_data *data);
void	reload_gun(t_gun *gun);
void	gun_inamation(t_gun *gun, t_data *data, int count, int i);
void	fire_gun(t_gun *gun);
void	file_name(char *c, char *path, int filenum);
void	put_evry_thene(t_data *data);
void	init_1(t_data *data);
void	get_door_info(t_data *data, int i, int j);
int		if_closed(t_data *data, int y, int x);
void	open_door(t_data *data, int y, int x);
void	close_door(t_data *data, int y, int x);
int		check_door(t_data *data, int y, int x);
void	sound(int i);
void	zombie_manager(t_data *data, int count);
void	init_doors_and_enemys(t_data *data);
void	save_enemy_info(t_data *data, t_math *m, int y, int x);
void	init_enemy(t_data *data, t_math *m);
void	draw_enemy(t_data *data, int i);
void	get_enemy_info(t_data *data, int y, int x);
void	con_draw(t_data *data, t_math_2 *m, int i, t_enemy *e);
void	gun_frames(t_data *data, int count);
void	load_frames(t_data *data);
void	more_keys(t_data *data);
int		ft_clean(t_data	*data);
void	draw_map(t_map *map, t_data *data);
void	draw_part_of_map(t_data *data);
int		check_if_door(t_data *data, int i, float d_x, float d_y);
int		wich_one(t_data *data, int y, int x);
void	check_if_enemy(t_player *p, float *tmp_y, float *tmp_x, int x);

#endif