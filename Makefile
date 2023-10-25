# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 12:44:25 by lnambaji          #+#    #+#              #
#    Updated: 2023/10/25 14:24:09 by lnambaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=		cc
CFLAGS			=		-Wall -Werror -Wextra -D BUFFER_SIZE=1024 -g -fsanitize=address
MLXDIR			=		mlx
MLXFLAGS		=		-I$(MLXDIR) -I/usr/local/include
LDFLAGS			=		-Lmlx -lmlx -framework OpenGL -framework AppKit

SOURCES			=		srcs
OBJECTS			=		objs
INCLUDES		=		include

SRCS			=		srcs/bresenham.c srcs/event_handlers.c srcs/ft_isdigit.c \
						srcs/ft_putnbr_fd.c srcs/ft_strchr.c srcs/ft_strlcpy.c srcs/get_next_line.c \
						srcs/matrix.c srcs/colors.c srcs/ft_atoi.c srcs/ft_printf.c srcs/ft_putstr_fd.c \
						srcs/ft_strdup.c srcs/ft_strlen.c srcs/hexchars.c srcs/read_map.c srcs/draw_.c \
						srcs/ft_bzero.c srcs/ft_putchar_fd.c srcs/ft_split.c srcs/ft_strjoin.c \
						srcs/ft_substr.c srcs/main.c

OBJS			=		$(SRCS:.c=.o)
EXECUTABLE		=		fdf
BINDIR			=		bin
BIN				=		$(BINDIR)/main

RED				=		\033[0;31m
DEFAULT			=		\033[0m
GREEN			=		\033[0;32m
CYAN			=		\033[0;36m

all: $(BIN)
	@echo "$(GREEN)Successfully built fdf!$(DEFAULT)"

$(BIN): $(OBJS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LDFLAGS) -o $(EXECUTABLE)

$(OBJECTS)/%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(MLXDIR) -c $< -o $@

clean:
	@echo "$(RED)Cleaned$(DEFAULT)"
	@rm -f $(OBJECTS)/* $(BIN)

fclean: clean

re: fclean all
