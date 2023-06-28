# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnambaji <lnambaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 12:44:25 by lnambaji          #+#    #+#              #
#    Updated: 2023/06/28 10:46:23 by lnambaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1024 -g

MLXFLAGS = -I /usr/local/include

LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SOURCES = test.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

EXECUTABLE = fdf

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

#cc -I /usr/local/include test.c -Lmlx -lmlx -framework OpenGL -framework AppKit