/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:56:12 by arupert           #+#    #+#             */
/*   Updated: 2022/06/21 21:58:07 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(0);
	if ((*map).bonus == 1)
	{
		if (keycode == 0)
			player_turns('l', map);
		else if (keycode == 1)
			player_turns('d', map);
		else if (keycode == 2)
			player_turns('r', map);
		else if (keycode == 13)
			player_turns('u', map);
	}
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	if (keycode == 0)
		player_moves(map, (*map).player[0], (*map).player[1] - 1);
	else if (keycode == 1)
		player_moves(map, (*map).player[0] + 1, (*map).player[1]);
	else if (keycode == 2)
		player_moves(map, (*map).player[0], (*map).player[1] + 1);
	else if (keycode == 13)
		player_moves(map, (*map).player[0] - 1, (*map).player[1]);
	return (0);
}

int	destroy_hook(int keycode, t_map *map)
{
	(void)keycode;
	(void)(*map);
	exit(0);
	return (0);
}
