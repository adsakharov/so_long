/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:09:16 by arupert           #+#    #+#             */
/*   Updated: 2022/07/03 15:41:52 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUF_SIZE
#  define BUF_SIZE 1024
# endif
# ifndef TILE_W
#  define TILE_W 64
# endif
# ifndef TILE_H
#  define TILE_H 64
# endif
# ifndef SCREEN_W
#  define SCREEN_W 2560
# endif
# ifndef SCREEN_H
#  define SCREEN_H 1418
# endif

typedef struct s_map
{
	char	**square;
	int		width;
	int		height;
	char	map_is_too_big;
	int		w_width;
	int		w_height;
	int		left_corner[2];
	int		fish_tiles;
	int		free_space_tiles;
	int		player_tiles;
	int		player[2];
	char	enable_enemies;
	int		enemy[2];
	void	*mlx;
	void	*mlx_win;
	int		number_of_moves;
	int		bonus;
}	t_map;

//check_map.c
char	check_file_name(char *name);
char	check_map_quadrature(char *line);
char	check_syntax(char *line, t_map *map);
char	check_map_borders_player_position(t_map *map);

//enemy.c
void	add_enemy(t_map *map);
void	enemy_chooses_move(t_map *map);

//errors.c
int		error_message(char error_type);

//ft_itoa.c
char	*ft_itoa(int n);

//ft_split.c
char	**free_char_array(char **char_array);
char	**ft_split(char const *s, char c);

//game_over.c
void	game_was_lost(int score);
void	game_was_won(int score);

//hooks.c
int		key_press(int keycode, t_map *map);
int		key_release(int keycode, t_map *map);
int		destroy_hook(int keycode, t_map *map);

//libft.c
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

//parcer.c
int		init_map(char **argv, t_map *map);

//player_moves.c
void	enemy_meet_player(t_map *map);
void	player_moves(t_map *map, int j2, int i2);

//random.c
int		get_random_4(void);
int		get_random_to_locate(t_map *map);

//rendering1.c
void	render_full_map(t_map *map, void *mlx, void	*mlx_win);
void	render_active_elements(t_map *map, int j2, int i2, char c);
void	display_num_of_moves(t_map *map, char c);
void	render_map(t_map *map, int j2, int i2);

//rendering2.c
void	*read_images(char img_code, void *mlx);
void	render_backwater(t_map *map, int i, int j);
void	render_backwall(t_map *map);

//rendering3.c
void	render_large_map(t_map *map, int j2, int i2);
void	render_enemy_move(t_map *map, int j2, int i2);
void	player_turns(char img_code, t_map *map);

// settings.c
void	set_basic_features(t_map *map);
void	set_basic_features2(t_map *map);
void	player_turns(char img_code, t_map *map);

#endif
