CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = src/
OBJ_DIR = obj/
LIB_DIR = lib/

# Libraries
LIBS = -L$(LIB_DIR) -Lminilibx-linux -lz -lXext -lX11 -lm
MLX	= minilibx-linux/libmlx.a

# Include directory
INC = inc/

# Source files
SRCS = $(SRC_DIR)main.c  # Adicione todos os arquivos .c aqui

# Object files
OBJS = $(OBJ_DIR)main.o  # Adicione todos os arquivos .o correspondentes aqui

# Executable
NAME = so_long

# Rules
all: $(NAME)

$(MLX):
			make -C ./minilibx-linux

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) -I$(INC) -o $@ $^ $(LIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re