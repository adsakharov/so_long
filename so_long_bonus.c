/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:45:00 by arupert           #+#    #+#             */
/*   Updated: 2022/06/23 15:15:25 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (error_message('a'));
	if (check_file_name(argv[1]) == 'n')
		return (error_message('b'));
	map.bonus = 1;
	map.mlx = mlx_init();
	set_basic_features(&map);
	if (init_map(argv, &map) < 0)
		return (-1);
	set_basic_features2(&map);
	map.mlx_win = mlx_new_window(map.mlx, map.w_width * TILE_W, \
	map.w_height * TILE_H, "so_long");
	if (map.free_space_tiles > 0 && map.bonus == 1)
		add_enemy(&map);
	render_full_map(&map, map.mlx, map.mlx_win);
	display_num_of_moves(&map, 'P');
	mlx_hook(map.mlx_win, 02, 1L << 0, key_press, &map);
	mlx_hook(map.mlx_win, 3, 1L << 1, key_release, &map);
	mlx_hook(map.mlx_win, 17, 1L << 17, destroy_hook, &map);
	mlx_loop(map.mlx);
}
