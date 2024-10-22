# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 14:16:38 by bruda-si          #+#    #+#              #
#    Updated: 2024/10/22 15:00:55 by bruda-si         ###   ########.fr        #
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
			$(SRC_DIR)get_next_line.c
			
OBJS	=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
					
all: $(NAME)


$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBS)

$(MLX):
	@make -C minilibx-linux

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./minilibx-linux

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(MLX)
	
re: fclean all

.PHONY: all clean fclean re