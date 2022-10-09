/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:43:16 by arupert           #+#    #+#             */
/*   Updated: 2022/06/21 22:03:03 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// render all the map including non-active elements
void	render_full_map(t_map *map, void *mlx, void	*mlx_win)
{
	int		i;
	int		j;
	void	*img;
	int		x;
	int		y;

	x = (*map).left_corner[1];
	y = (*map).left_corner[0];
	j = -1;
	while (++j < (*map).w_height)
	{
		i = -1;
		while (++i < (*map).w_width)
		{
			if (ft_strchr("PCEA", (*map).square[j + y][i + x]))
				render_backwater(map, i, j);
			img = read_images((*map).square[j + y][i + x], mlx);
			mlx_put_image_to_window(mlx, mlx_win, img, i * TILE_W, j * TILE_H);
		}
	}
}

// render only change of a position of the player or enemy
void	render_active_elements(t_map *map, int j2, int i2, char c)
{
	void	*img;
	int		i;
	int		j;
	int		x;
	int		y;

	x = i2 - (*map).left_corner[1];
	y = j2 - (*map).left_corner[0];
	img = read_images(c, (*map).mlx);
	render_backwater(map, x, y);
	mlx_put_image_to_window((*map).mlx, (*map).mlx_win, img, x * TILE_W, \
	y * TILE_H);
	if (c == 'P')
	{
		j = (*map).player[0] - (*map).left_corner[0];
		i = (*map).player[1] - (*map).left_corner[1];
	}
	else
	{
		j = (*map).enemy[0] - (*map).left_corner[0];
		i = (*map).enemy[1] - (*map).left_corner[1];
	}	
	img = read_images('0', (*map).mlx);
	mlx_put_image_to_window((*map).mlx, (*map).mlx_win, img, i * TILE_W, \
	j * TILE_H);
}

// display current number of movements in the shell
// in case of bonus also render number of movements
void	display_num_of_moves(t_map *map, char c)
{
	char	*number_of_moves;

	number_of_moves = ft_itoa((*map).number_of_moves);
	if ((*map).bonus == 1)
		mlx_string_put((*map).mlx, (*map).mlx_win, \
		TILE_W / 2, TILE_H / 2, 0x00FF0000, number_of_moves);
	if (c == 'P')
	{
		ft_putstr_fd(number_of_moves, 1);
		ft_putstr_fd("\n", 1);
	}
	free(number_of_moves);
	number_of_moves = NULL;
}

// root function to choose kind of map (small or large) to render
void	render_map(t_map *map, int j2, int i2)
{
	if ((*map).map_is_too_big == 'y')
		render_large_map(map, j2, i2);
	else
	{
		render_active_elements(map, j2, i2, 'P');
		if ((*map).bonus == 1)
			render_backwall(map);
		display_num_of_moves(map, 'P');
	}
}
