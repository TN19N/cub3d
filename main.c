/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:34:56 by mannouao          #+#    #+#             */
/*   Updated: 2022/03/12 21:20:32 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>

int main()
{
	int i, j;
	int tmp;
	void *imag;
	char *info;
	void *ml;
	void *wi;
	int color;
	
	ml = mlx_init();
	wi = mlx_new_window(ml, 64, 64, "Test");
	imag = mlx_xpm_file_to_image(ml, "texture/redbrick.xpm", &tmp, &tmp);
	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			info = mlx_get_data_addr(imag, &tmp, &tmp, &tmp);
			color = (int)info[64 * i + j];
			printf("color = %d\n", color);
			mlx_pixel_put(ml, wi, j, i, color);
			j++;
		}
		i++;
	}
	mlx_loop(ml);
}