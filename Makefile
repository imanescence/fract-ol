# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 14:55:11 by iait-ouf          #+#    #+#              #
#    Updated: 2025/05/29 11:33:35 by iait-ouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INCLUDE = library/fractol.h

CFLAGS = -Wall -Wextra -Werror -O3

MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
MINILIBX_INC = -I$(MINILIBX_DIR) -I/usr/include
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

SRCS = srcs/main.c\
       srcs/parsing.c\
       srcs/calculations_tools.c\
       srcs/draw_fractals.c\
       srcs/parsing_utils.c\
       srcs/hooks.c

OBJ = $(SRCS:.c=.o)

all: $(MINILIBX_LIB) $(NAME)

$(MINILIBX_LIB):
	tar -xpf minilibx-linux.tgz
	$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MINILIBX_FLAGS) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) $(MINILIBX_INC) -c $< -o $@

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(MINILIBX_DIR) clean || true

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean || true

re: fclean all

.PHONY: all clean fclean re

