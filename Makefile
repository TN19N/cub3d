# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 07:17:57 by mannouao          #+#    #+#              #
#    Updated: 2022/03/11 07:54:49 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
LIBFT = libft/libft.a
SRCS = srcs/cub3d.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

./srcs/%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	make -C libft clean
	$(RM) $(OBJS)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)

re : fclean all 