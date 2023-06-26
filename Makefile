# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 12:44:25 by lnambaji          #+#    #+#              #
#    Updated: 2023/06/26 14:43:48 by lnambaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1024
MLXFLAGS = -lMLX -framework OpenGL -framework AppKit#-lmlx -lXext -lX11
RM = rm -f

MLX_SRCS = test.c
GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c

EXECUTABLES = $(basename $(GNL_SRCS)) $(basename $(MLX_SRCS))

OBJS_GNL = $(GNL_SRCS:.c=.o)
OBJS_MLX = $(MLX_SRCS:.c=.o)

all: $(EXECUTABLES)

$(EXECUTABLES): %: %.o
	$(CC) $(CFLAGS) -I /usr/local/include -L /usr/local/bin $< $(MLXFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I /usr/local/include -L /usr/local/bin -c $< -o $@

clean:
	$(RM) $(EXECUTABLES) $(OBJS_GNL) $(OBJS_MLX)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
#cc -I /usr/local/include test.c -L /usr/local/bin -lMLX -framework OpenGL -framework AppKit