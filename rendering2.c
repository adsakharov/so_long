/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:23:27 by arupert           #+#    #+#             */
/*   Updated: 2022/06/21 21:34:06 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*read_images(char img_code, void *mlx)
{
	void	*img;
	int		pos[2];

	img = NULL;
	pos[0] = TILE_W;
	pos[1] = TILE_H;
	if (img_code == '1')
		img = mlx_xpm_file_to_image(mlx, \
		"./pictures/rock-wall.xpm", &pos[0], &pos[1]);
	else if (img_code == 'P')
		img = mlx_xpm_file_to_image(mlx, \
		"./pictures/dolphin-L.xpm", &pos[0], &pos[1]);
	else if (img_code == '0')
		img = mlx_xpm_file_to_image(mlx, \
		"./pictures/sea-water.xpm", &pos[0], &pos[1]);
	else if (img_code == 'C')
		img = mlx_xpm_file_to_image(mlx, \
		"./pictures/fish.xpm", &pos[0], &pos[1]);
	else if (img_code == 'E')
		img = mlx_xpm_file_to_image(mlx, \
		"./pictures/door.xpm", &pos[0], &pos[1]);
	else if (img_code == 'A')
		img = mlx_xpm_file_to_image(mlx, \
		"./pictures/shark.xpm", &pos[0], &pos[1]);
	return (img);
}

// render a terrain behind the player or the enemy
void	render_backwater(t_map *map, int i, int j)
{
	void	*img;

	img = read_images('0', (*map).mlx);
	mlx_put_image_to_window((*map).mlx, (*map).mlx_win, \
	img, i * TILE_W, j * TILE_H);
}

// render a wall behind the score
void	render_backwall(t_map *map)
{
	void	*img;

	img = read_images('1', (*map).mlx);
	mlx_put_image_to_window((*map).mlx, (*map).mlx_win, img, 0, 0);
}
