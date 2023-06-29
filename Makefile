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

MLXFLAGS = -I /usr/local/include

LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SOURCES = main.c gnl/get_next_line.c gnl/get_next_line_utils.c \
	event_handlers.c draw_.c read_map.c libft/ft_split.c libft/ft_strjoin.c

OBJECTS = $(SOURCES:.c=.o)

EXECUTABLE = fdf

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

fclean: clean

re: fclean all
#cc -I /usr/local/include test.c -Lmlx -lmlx -framework OpenGL -framework AppKit