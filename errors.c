/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arupert <arupert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:41:06 by arupert           #+#    #+#             */
/*   Updated: 2022/06/21 21:49:53 by arupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_message(char error_type)
{
	if (error_type == 'a')
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
	if (error_type == 'm')
		ft_putstr_fd("Error\nMap can't be read\n", 2);
	if (error_type == 'b')
		ft_putstr_fd("Error\nMap extension has to be *.ber\n", 2);
	if (error_type == '0')
		ft_putstr_fd("Error\nMemmory can't be allocated\n", 2);
	if (error_type == '1')
		ft_putstr_fd("Error\nMap is not square\n", 2);
	if (error_type == '2')
		ft_putstr_fd("Error\nMap contains invalid symbols\n", 2);
	if (error_type == '3')
		ft_putstr_fd("Error\nMap border is broken\n", 2);
	return (-1);
}
