# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arupert <arupert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:38:49 by arupert           #+#    #+#              #
#    Updated: 2022/06/21 22:26:10 by arupert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES	= rendering1.c \
			  rendering2.c \
			  rendering3.c \
			  errors.c \
			  check_map.c \
			  parcer.c \
			  libft.c \
			  ft_split.c \
			  player_moves.c \
			  ft_itoa.c \
			  settings.c \
			  game_over.c \
			  enemy.c \
			  hooks.c \
			  so_long.c

BSRC_FILES	= rendering1.c \
			  rendering2.c \
			  rendering3.c \
			  errors.c \
			  check_map.c \
			  parcer.c \
			  libft.c \
			  ft_split.c \
			  player_moves.c \
			  ft_itoa.c \
			  settings.c \
			  game_over.c \
			  enemy.c \
			  hooks.c \
			  so_long_bonus.c

OBJS		= $(SRC_FILES:.c=.o)
BOBJS		= $(BSRC_FILES:.c=.o)

HEADER		= so_long.h

MINILIBX	= -lmlx -framework OpenGL -framework AppKit

NAME		= so_long
BNAME		= so_long_bonus

CC			= cc

CFLAGS		= -Wall -Werror -Wextra -Imlx

RM			= rm -f

.PHONY:		all clean fclean re bonus

%.o:		%.c $(HEADER) Makefile
			$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -o $(NAME)

bonus:		$(BNAME)

$(BNAME):	$(BOBJS)
			$(CC) $(CFLAGS) $(BOBJS) $(MINILIBX) -o $(BNAME)

all:		$(NAME)

clean:
	$(RM) $(OBJS)
	${RM} $(BOBJS)

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(BNAME)
	
re:			fclean all
