/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fdf.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hait-moh <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/01/31 11:10:17 by hait-moh		  #+#	#+#			 */
/*   Updated: 2022/03/15 09:39:19 by hait-moh         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include <mlx.h>
#include "cub3d.h"
#include <unistd.h>

void    *mlx_png_file_to_image(void *xvar, char *file, int *width, int *height);

int handle_mouse(int x, int y, void *param)
{
	int img_width;
    int img_height;
	void *img;
	t_data *data;

    return (0);
}

void	file_name(char *c, char *path, int filenum)
{
	char	*it;
	char	*extention;
	int		i;

	i = 0;
	extention = ".png";
	it = ft_itoa(filenum);
	while(*path)
		*(c++) = *(path++);
	while(it[i])
		*(c++) = it[i++];
	while(*extention)
		*(c++) = *(extention++);
	free(it);
	*c = 0;
}

void	fire_gun(t_data *data)
{
	if (data->fired == 0)
	{
		data->fired = 1;
		data->fire_index = 50;
	}
}

void	reload_gun(t_data *data)
{
	if (data->gun_reload == 0)
	{
		data->gun_reload = 1;
		data->reload_index = 50;
	}
}

void	cursor(t_data *data)
{
	int height;
	int width;
	void *img;

	img = mlx_png_file_to_image(data->mlx, "./cursor.png", &width, &height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, 500, 320);
	mlx_destroy_image(data->mlx, img);
}

void idle(t_data *data)
{
	int height;
	int width;
	void *img;

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->blank_img, 0, 0);
	//cursor(data);
	img = mlx_png_file_to_image(data->mlx, "./idle.png", &height, &width);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, 0, 0);
	mlx_destroy_image(data->mlx, img);
}

void	reload_animation(t_data *data)
{
	char c[17];
	void	*img;
	int height;
	int width;

	if (data->gun_reload == 1)
	{
		//cursor(data);
		file_name(c, "./reload/", (data->reload_index / 50));
		img = mlx_png_file_to_image(data->mlx, c, &height, &width);
		mlx_put_image_to_window(data->mlx, data->mlx_win, img, 0, 0);
		mlx_destroy_image(data->mlx, img);
		data->reload_index++;
	}
	if (data->reload_index == 6351)
	{
		data->reload_index = 50;
		data->gun_reload = 0;
	}
}

void	fire_animation(t_data *data)
{
	char c[17];
	void	*img;
	int height;
	int width;

	//ft_strcpy("./fire/a.xpm", c);
	if (data->fired == 1)
	{
		file_name(c, "./fire/", (data->fire_index / 50));
		//cursor(data);
		//fire_smoke(data);
		img = mlx_png_file_to_image(data->mlx, c, &height, &width);
		mlx_put_image_to_window(data ->mlx, data->mlx_win, img, 0, 0);
		mlx_destroy_image(data->mlx, img);
		data->fire_index++;
	}
	if (data->fire_index == 601)
	{
		data->fire_index = 50;
		data->fired = 0;
	}
}

int handle_mouse_button(int button, int x, int y, void *param)
{
	t_data *data;

	data = param;
	if (button == 1 && !data->gun_reload)
		fire_gun(param);
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == 53)
	{
        mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
    }
	if (keysym == 15 && !data->fired)
        reload_gun(data);
	return (0);
}

int	the_game(void *param)
{
	t_data *data;


	data = param;
	if (data->fired && !data->gun_reload && data->fire_index % 50 == 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->blank_img, 0, 0);
		fire_animation(data);
	}
	else if (data->fired && !data->gun_reload && data->fire_index % 50 != 0)
		data->fire_index++;
	if (data->gun_reload && !data->fired && data->reload_index % 50 == 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->blank_img, 0, 0);
		reload_animation(data);
	}
	else if (data->gun_reload && !data->fired && data->reload_index % 50 != 0)
		data->reload_index++;
	if (!data->fired && !data->gun_reload)
		idle(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int img_width;
    int img_height;

	data.fire_index = 50;
	data.fired = 0;
	data.reload_index = 50;
	data.gun_reload = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1000, 640, "Hello world!");
    data.blank_img = mlx_new_image(data.mlx, 1000, 640);
	mlx_key_hook(data.mlx_win, handle_input, &data);
	mlx_mouse_hook(data.mlx_win, handle_mouse_button, &data);
    //mlx_hook(data.mlx_win, 6 , 0, handle_mouse, &data);
	mlx_loop_hook(data.mlx, the_game, &data);
	mlx_loop(data.mlx);
}
