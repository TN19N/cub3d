# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 07:17:57 by mannouao          #+#    #+#              #
#    Updated: 2022/03/13 09:17:07 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
LIBFT = libft/libft.a
SRCS_PATH = srcs/

SRCS =  $(SRCS_PATH)cub3d.c \
		$(SRCS_PATH)init_the_map.c \
		$(SRCS_PATH)fill_data.c \
		$(SRCS_PATH)check_map.c \
		$(SRCS_PATH)/ray-casting/ray-casting.c \
		$(SRCS_PATH)/ray-casting/draw_walls.c \
		$(SRCS_PATH)/ray-casting/draw_buffer.c \
		$(SRCS_PATH)move_player.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
XFLAGS = -lmlx -framework OpenGL -framework Appkit
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

./srcs/%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	make -C libft clean
	$(RM) $(OBJS)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)

re : fclean all 