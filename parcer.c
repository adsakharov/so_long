/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:42:03 by arupert           #+#    #+#             */
/*   Updated: 2022/06/23 15:15:23 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// supporting function for the next function 
static char	*read_cycle(int fd, char **buf)
{
	char	*line;
	ssize_t	ret;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	ret = read(fd, *buf, BUF_SIZE);
	while (ret > 0)
	{
		(*buf)[ret] = '\0';
		line = ft_strjoin(line, *buf);
		ret = read(fd, *buf, BUF_SIZE);
	}
	if (ret < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// parce info from a map file to a string
static char	*read_map_to_string(char **argv)
{
	char	*buf;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = malloc(BUF_SIZE + 1);
	if (!buf)
		return (NULL);
	line = read_cycle(fd, &buf);
	free(buf);
	return (line);
}

static void	check_map_size(t_map *map)
{
	if (SCREEN_W / TILE_W - 1 < (*map).width || \
	SCREEN_H / TILE_H - 1 < (*map).height)
		(*map).map_is_too_big = 'y';
}

static t_map	*get_width_heigth(t_map *map)
{
	int	j;

	(*map).width = ft_strlen((*map).square[0]);
	j = 0;
	while ((*map).square[j])
	{
		j++;
	}
	(*map).height = j;
	check_map_size(map);
	return (map);
}

int	init_map(char **argv, t_map *map)
{
	char	*line;

	line = read_map_to_string(argv);
	if (!line)
		return (error_message('m'));
	if (check_map_quadrature(line) != 'y')
		return (error_message('1'));
	if (check_syntax(line, map) != 'y')
		return (error_message('2'));
	(*map).square = ft_split(line, '\n');
	free(line);
	if (!(*map).square)
		return (error_message('0'));
	map = get_width_heigth(map);
	if (check_map_borders_player_position(map) != 'y')
	{
		(*map).square = free_char_array((*map).square);
		return (error_message('3'));
	}
	return (0);
}
