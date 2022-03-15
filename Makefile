# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 07:17:57 by mannouao          #+#    #+#              #
#    Updated: 2022/03/15 07:29:50 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS = cub3d_bonus
NAME = cub3d
CC = gcc
LIBFT = libft/libft.a
SRCS_PATH = Mandatory/
SRCS_PATH_BONUS = Bonus/

SRCS =  $(SRCS_PATH)cub3d.c \
		$(SRCS_PATH)init_the_map.c \
		$(SRCS_PATH)fill_data.c \
		$(SRCS_PATH)check_map.c \
		$(SRCS_PATH)ray-casting/ray_casting.c \
		$(SRCS_PATH)ray-casting/draw_walls.c \
		$(SRCS_PATH)ray-casting/ray_utils.c \
		$(SRCS_PATH)move_player.c \
		$(SRCS_PATH)utils.c

SRCS_BONUS =  $(SRCS_PATH_BONUS)cub3d_bonus.c \
		$(SRCS_PATH_BONUS)init_the_map_bonus.c \
		$(SRCS_PATH_BONUS)fill_data_bonus.c \
		$(SRCS_PATH_BONUS)check_map_bonus.c \
		$(SRCS_PATH_BONUS)ray-casting/ray_casting_bonus.c \
		$(SRCS_PATH_BONUS)ray-casting/draw_walls_bonus.c \
		$(SRCS_PATH_BONUS)ray-casting/ray_utils_bonus.c \
		$(SRCS_PATH_BONUS)move_player_bonus.c \
		$(SRCS_PATH_BONUS)utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
XFLAGS = -lmlx -framework OpenGL -framework Appkit
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $(XFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

./srcs/%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	make -C libft clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all 