/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:21:28 by arupert           #+#    #+#             */
/*   Updated: 2022/06/21 21:41:04 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_enemy(t_map *map)
{
	int	i;
	int	j;
	int	counter;

	counter = rand() % (*map).free_space_tiles;
	j = -1;
	while (++j < (*map).height)
	{
		i = -1;
		while (++i < (*map).width)
		{
			if ((*map).square[j][i] == '0')
			{
				if (counter == 0)
				{
					(*map).square[j][i] = 'A';
					(*map).enemy[0] = j;
					(*map).enemy[1] = i;
					return ;
				}
				else
					counter--;
			}
		}
	}
}

static void	enemy_goes_to_water(t_map *map, int j2, int i2)
{
	(*map).square[(*map).enemy[0]][(*map).enemy[1]] = '0';
	(*map).square[j2][i2] = 'A';
	render_enemy_move(map, j2, i2);
	(*map).enemy[0] = j2;
	(*map).enemy[1] = i2;
}

static void	enemy_moves(t_map *map, int j2, int i2)
{
	if (ft_strchr("1EC", (*map).square[j2][i2]))
		return ;
	else if ((*map).square[j2][i2] == '0')
		enemy_goes_to_water(map, j2, i2);
	else if ((*map).square[j2][i2] == 'P')
		enemy_meet_player(map);
	return ;
}

void	enemy_chooses_move(t_map *map)
{
	int	random;

	random = rand() % 4;
	if (random == 0)
		enemy_moves(map, (*map).enemy[0], (*map).enemy[1] - 1);
	else if (random == 1)
		enemy_moves(map, (*map).enemy[0] + 1, (*map).enemy[1]);
	else if (random == 2)
		enemy_moves(map, (*map).enemy[0], (*map).enemy[1] + 1);
	else if (random == 3)
		enemy_moves(map, (*map).enemy[0] - 1, (*map).enemy[1]);
	return ;
}
