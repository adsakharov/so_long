/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:56:20 by arupert           #+#    #+#             */
/*   Updated: 2022/06/21 22:02:11 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	go_to_water(t_map *map, int j2, int i2)
{
	(*map).square[(*map).player[0]][(*map).player[1]] = '0';
	(*map).square[j2][i2] = 'P';
	(*map).number_of_moves++;
	render_map(map, j2, i2);
	(*map).player[0] = j2;
	(*map).player[1] = i2;
	if ((*map).bonus == 1)
		enemy_chooses_move(map);
}

static void	go_to_fish(t_map *map, int j2, int i2)
{
	(*map).square[(*map).player[0]][(*map).player[1]] = '0';
	(*map).square[j2][i2] = 'P';
	(*map).number_of_moves++;
	render_map(map, j2, i2);
	(*map).player[0] = j2;
	(*map).player[1] = i2;
	(*map).fish_tiles--;
	if ((*map).bonus == 1)
		enemy_chooses_move(map);
}

static void	go_to_exit(t_map *map)
{
	if ((*map).fish_tiles == 0)
	{
		(*map).number_of_moves++;
		display_num_of_moves(map, 'P');
		game_was_won((*map).number_of_moves);
		mlx_destroy_window((*map).mlx, (*map).mlx_win);
	}
}

void	enemy_meet_player(t_map *map)
{
	game_was_lost((*map).number_of_moves);
	mlx_destroy_window((*map).mlx, (*map).mlx_win);
}

void	player_moves(t_map *map, int j2, int i2)
{
	if ((*map).square[j2][i2] == '1')
		return ;
	else if ((*map).square[j2][i2] == '0')
		go_to_water(map, j2, i2);
	else if ((*map).square[j2][i2] == 'C')
		go_to_fish(map, j2, i2);
	else if ((*map).square[j2][i2] == 'E')
		go_to_exit(map);
	else if ((*map).square[j2][i2] == 'A')
	{
		(*map).number_of_moves++;
		display_num_of_moves(map, 'P');
		enemy_meet_player(map);
	}
}
