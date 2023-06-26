# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 12:44:25 by lnambaji          #+#    #+#              #
#    Updated: 2023/06/26 16:12:14 by lnambaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1024
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

MLX_SRCS = test.c
GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c

EXECUTABLES = $(basename $(GNL_SRCS)) $(basename $(MLX_SRCS))

OBJS_GNL = gnl/get_next_line.o gnl/get_next_line_utils.o
OBJS_MLX = $(MLX_SRCS:.c=.o)

all: $(EXECUTABLES)

$(EXECUTABLES): %: %.o $(OBJS_MLX) $(OBJS_GNL)
	$(CC) $(CFLAGS) -I /usr/local/include $< $(OBJS_MLX) $(OBJS_GNL) -Lmlx $(MLXFLAGS) -o $@

$(OBJS_MLX): %.o: %.c
	$(CC) $(CFLAGS) -I /usr/local/include -c $< -o $@

$(OBJS_GNL): %.o: %.c
	$(CC) $(CFLAGS) -I /usr/local/include -c $< -o $@

clean:
	$(RM) $(EXECUTABLES) $(OBJS_GNL) $(OBJS_MLX)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
#cc -I /usr/local/include test.c -Lmlx -lmlx -framework OpenGL -framework AppKit
