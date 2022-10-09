/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:08:02 by arupert           #+#    #+#             */
/*   Updated: 2022/06/21 20:01:39 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_was_lost(int score)
{
	char	*number_of_moves;

	ft_putstr_fd("You lost the game\n", 1);
	ft_putstr_fd("Your final score is ", 1);
	number_of_moves = ft_itoa(score);
	ft_putstr_fd(number_of_moves, 1);
	free(number_of_moves);
	ft_putstr_fd("\n", 1);
	exit(0);
}

void	game_was_won(int score)
{
	char	*number_of_moves;

	ft_putstr_fd("You won the game\n", 1);
	ft_putstr_fd("Your final score is ", 1);
	number_of_moves = ft_itoa(score);
	ft_putstr_fd(number_of_moves, 1);
	free(number_of_moves);
	ft_putstr_fd("\n", 1);
	exit(0);
}
