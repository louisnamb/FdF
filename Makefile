# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 12:44:25 by lnambaji          #+#    #+#              #
#    Updated: 2023/06/29 15:25:05 by lnambaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1024 -g
MLXDIR = mlx
MLXFLAGS = -I$(MLXDIR) -I/usr/local/include
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SOURCES = srcs
OBJECTS = objs
INCLUDES = includes

SRCS = $(wildcard $(SOURCES)/*.c)
OBJS = $(patsubst $(SOURCES)/%.c, $(OBJECTS)/%.o, $(SRCS))

EXECUTABLE = fdf
BINDIR = bin
BIN = $(BINDIR)/main

RED = \033[0;31m
DEFAULT = \033[0m
GREEN = \033[0;32m
CYAN = \033[0;36m

all: $(BIN)
	@echo "$(GREEN)Successfully built fdf!$(DEFAULT)"

$(BIN): $(OBJS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LDFLAGS) -o $(EXECUTABLE)

$(OBJECTS)/%.o: $(SOURCES)/%.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(MLXDIR) -c $< -o $@

clean:
	@echo "$(RED)Cleaned$(DEFAULT)"
	@rm -f $(OBJECTS)/* $(BIN)

fclean: clean

re: fclean all

#cc -I /usr/local/include test.c -Lmlx -lmlx -frmework OpenGL -framework AppKit
