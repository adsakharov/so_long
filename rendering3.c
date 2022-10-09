/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:23:47 by arupert           #+#    #+#             */
/*   Updated: 2022/06/21 22:02:38 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// correct upper left corner of a map to render
// due to current position of the player
static char	correct_left_corner(t_map *map, int j2, int i2)
{
	int		x;
	int		y;

	x = (*map).left_corner[1];
	y = (*map).left_corner[0];
	if (j2 - 2 < y || j2 + 1 >= (*map).w_height + y)
	{
		(*map).left_corner[0] = j2 - (*map).w_height / 2;
		if ((*map).left_corner[0] > (*map).height - (*map).w_height)
			(*map).left_corner[0] = (*map).height - (*map).w_height;
		else if ((*map).left_corner[0] < 0)
			(*map).left_corner[0] = 0;
	}
	if (i2 - 2 < x || i2 + 1 >= (*map).w_width + x)
	{
		(*map).left_corner[1] = i2 - (*map).w_width / 2;
		if ((*map).left_corner[1] > (*map).width - (*map).w_width)
			(*map).left_corner[1] = (*map).width - (*map).w_width;
		else if ((*map).left_corner[1] < 0)
			(*map).left_corner[1] = 0;
	}
	if (x != (*map).left_corner[1] || y != (*map).left_corner[0])
		return ('y');
	return ('n');
}

// render the tile behind the score in case of large map
static void	render_left_corner(t_map *map)
{
	char	c;
	void	*img;

	c = (*map).square[(*map).left_corner[0]][(*map).left_corner[1]];
	if (ft_strchr("CPEA", c))
		render_backwater(map, 0, 0);
	img = read_images(c, (*map).mlx);
	mlx_put_image_to_window((*map).mlx, (*map).mlx_win, img, 0, 0);
}

// process a map larger than a window
void	render_large_map(t_map *map, int j2, int i2)
{
	if (correct_left_corner(map, j2, i2) == 'n')
	{
		if ((*map).bonus == 1)
			render_left_corner(map);
		render_active_elements(map, j2, i2, 'P');
		display_num_of_moves(map, 'P');
	}
	else
	{
		render_full_map(map, (*map).mlx, (*map).mlx_win);
		display_num_of_moves(map, 'P');
	}
}

void	render_enemy_move(t_map *map, int j2, int i2)
{
	render_active_elements(map, j2, i2, 'A');
	render_left_corner(map);
	display_num_of_moves(map, 'A');
}

// some animation of a player
void	player_turns(char img_code, t_map *map)
{
	void	*img;
	int		pos[2];
	int		x;
	int		y;

	x = (*map).player[1] - (*map).left_corner[1];
	y = (*map).player[0] - (*map).left_corner[0];
	render_backwater(map, x, y);
	if (img_code == 'd')
		img = mlx_xpm_file_to_image((*map).mlx, \
		"./pictures/dolphin-D.xpm", &pos[0], &pos[1]);
	else if (img_code == 'r')
		img = mlx_xpm_file_to_image((*map).mlx, \
		"./pictures/dolphin-R.xpm", &pos[0], &pos[1]);
	else if (img_code == 'u')
		img = mlx_xpm_file_to_image((*map).mlx, \
		"./pictures/dolphin-U.xpm", &pos[0], &pos[1]);
	else
		img = mlx_xpm_file_to_image((*map).mlx, \
		"./pictures/dolphin-L.xpm", &pos[0], &pos[1]);
	mlx_put_image_to_window((*map).mlx, (*map).mlx_win, img, x * TILE_W, \
	y * TILE_H);
	return ;
}
