/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:40:59 by arupert           #+#    #+#             */
/*   Updated: 2022/07/03 15:42:22 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_basic_features(t_map *map)
{
	(*map).fish_tiles = 0;
	(*map).free_space_tiles = 0;
	(*map).player_tiles = 0;
	(*map).left_corner[0] = 0;
	(*map).left_corner[1] = 0;
	(*map).number_of_moves = 0;
	(*map).map_is_too_big = 'n';
}

// set upper left corner of a map to render due to starting position of player
static void	set_left_corner(t_map *map, int j2, int i2)
{
	if ((*map).w_width / 2 < i2)
	{
		(*map).left_corner[1] = i2 - (*map).w_width / 2;
		if ((*map).left_corner[1] > (*map).width - (*map).w_width)
			(*map).left_corner[1] = (*map).width - (*map).w_width;
	}
	else
		(*map).left_corner[1] = 0;
	if ((*map).w_height / 2 < j2)
	{
		(*map).left_corner[0] = j2 - (*map).w_height / 2;
		if ((*map).left_corner[0] > (*map).height - (*map).w_height)
			(*map).left_corner[0] = (*map).height - (*map).w_height;
	}
	else
		(*map).left_corner[0] = 0;
}

void	set_basic_features2(t_map *map)
{
	if ((*map).width > SCREEN_W / TILE_W - 1)
		(*map).w_width = SCREEN_W / TILE_W - 1;
	else
		(*map).w_width = (*map).width;
	if ((*map).height > SCREEN_H / TILE_H - 1)
		(*map).w_height = SCREEN_H / TILE_H - 1;
	else
		(*map).w_height = (*map).height;
	if ((*map).map_is_too_big == 'y')
		set_left_corner(map, (*map).player[0], (*map).player[1]);
}
