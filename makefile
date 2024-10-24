# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lede-gui <lede-gui@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 14:16:38 by bruda-si          #+#    #+#              #
#    Updated: 2024/10/24 12:07:35 by lede-gui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	so_long
CC		=	gcc
CFLAGS 	= 	-Wall -Wextra -Werror -g -I
RM		=	rm -f
# Directories
SRC_DIR = src/
OBJ_DIR = obj/

# Libraries
LIBS = -Lminilibx-linux -lz -lXext -lX11 -lm
MLX	= minilibx-linux/libmlx.a

# Include directory
INC = inc/

# Source files
SRCS	=	$(SRC_DIR)main.c \
			$(SRC_DIR)get_next_line.c \
			$(SRC_DIR)validade_map.c

OBJS	=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)


$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBS)

$(MLX):
	@$(MAKE) -C minilibx-linux

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) clean -C ./minilibx-linux

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(MLX)

re: fclean all

.PHONY: all clean fclean re
