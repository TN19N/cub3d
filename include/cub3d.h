/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:24:31 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/11 11:55:44 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct s_data
{
	void	*ml;
	void	*wi;
	void	*no_texture;
	void	*so_texture;
	void	*we_texture;
	void	*ea_texture;
	int		*floor_color;
	int		*ceilling_color;
	char	**map;
}		t_data;

void	init_the_map(char *map_name, t_data *data);
void	get_xpm_files(char *file_path, void **ptr);
void	get_colors(char *color, int **ptr);
void	get_xpm_files(char *file_path, void **ptr, void *ml);

#endif