# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 14:16:38 by bruda-si          #+#    #+#              #
#    Updated: 2024/10/29 13:44:26 by bruda-si         ###   ########.fr        #
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
MLX	=	minilibx-linux/libmlx.a
LIBFT_DIR	=	libft/
LIBFT	=	$(LIBFT_DIR)libft.a

# Include directory
INC = inc/

# Source files
SRCS	=	$(SRC_DIR)main.c \
			$(SRC_DIR)get_next_line.c \
			$(SRC_DIR)validade_map.c \
			$(SRC_DIR)key_handling.c \
			$(SRC_DIR)map_construct.c

OBJS	=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)


$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBS)

$(MLX):
	@$(MAKE) -C minilibx-linux

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) clean -C ./minilibx-linux
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(MLX)
		@$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
