/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:07:25 by arupert           #+#    #+#             */
/*   Updated: 2022/07/03 15:43:00 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	check_file_name(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '.' && name[i] != '\0')
		i++;
	if (name[i] != '\0' && i != 0)
		if (ft_strcmp(".ber", name + i) == 0)
			return ('y');
	return ('n');
}

static int	get_length(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' || line[i] != '\n')
	{
		if (line[i] == '\n')
			return (i);
		if (line[i] == '\0')
			return (-1);
		i++;
	}
	return (-1);
}

char	check_map_quadrature(char *line)
{
	int		length;
	size_t	i;

	i = -1;
	length = get_length(line);
	if (length < 0)
		return ('n');
	while (line[++i] != '\0')
	{
		if (line[i] == '\n')
			if ((i + 1) % (length + 1) != 0)
				return ('n');
	}
	if (line[i] == '\0')
	{
		if ((i + 1) % (length + 1) != 0)
			return ('n');
		else
			return ('y');
	}
	return ('y');
}

// check there is no unknown symbols, at least 1 'P' and at least 1 'E'
// also change excessive 'P' to '0'
char	check_syntax(char *line, t_map *map)
{
	int		exit_tiles;
	ssize_t	i;

	exit_tiles = 0;
	i = -1;
	while (line[++i] != '\0')
	{
		if (ft_strchr("01CEP\n", line[i]) == NULL)
			return ('n');
		if (line[i] == '0')
			(*map).free_space_tiles++;
		else if (line[i] == 'C')
			(*map).fish_tiles++;
		else if (line[i] == 'E')
			exit_tiles++;
		else if (line[i] == 'P')
		{
			(*map).player_tiles++;
			if ((*map).player_tiles > 1)
				line[i] = '0';
		}
	}
	if (exit_tiles < 1 || (*map).player_tiles < 1)
		return ('n');
	return ('y');
}

char	check_map_borders_player_position(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < (*map).height)
	{
		i = -1;
		while (++i < (*map).width)
		{
			if ((j == 0 || i == 0 || j == (*map).height - 1 || \
			i == (*map).width - 1) && (*map).square[j][i] != '1')
				return ('n');
			if ((*map).square[j][i] == 'P')
			{
				(*map).player[0] = j;
				(*map).player[1] = i;
			}
		}
	}
	return ('y');
}
