# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 15:31:09 by ajehle            #+#    #+#              #
#    Updated: 2024/03/08 12:29:56 by ajehle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
REMOVE		= rm -rf
OBJ_DIR		= ./obj
SRC_DIR		= src
INC_DIR		= include
MLX42_DIR	= ./MLX42
CFLAGS		= -Wall -Werror -Wextra -I $(INC_DIR)
LIBXFLAGS	=  -framework Cocoa -framework OpenGL -framework IOKit
MLX_INCLUDE	= MLX42/build/libmlx42.a -Iinclude -lglfw

# looking for files in subdirectories
vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

# INTERNAL FUNCTIONS
FUNCTIONS	=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/ft_exit.c \
				$(SRC_DIR)/ft_initialize.c \
				$(SRC_DIR)/ft_hook.c \
				$(SRC_DIR)/load_images.c \
				$(SRC_DIR)/ft_bzero.c \
				$(SRC_DIR)/ft_calloc.c \
				$(SRC_DIR)/ft_memset.c \
				$(SRC_DIR)/ft_atoi.c \
				$(SRC_DIR)/ft_isdigit.c \
				$(SRC_DIR)/ft_itoa.c \

# INTERNAL OBJECT
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(notdir $(FUNCTIONS:.c=.o)))

all : mlx_clone $(NAME)

# INTERNAL RULE
$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_INCLUDE) $(LIBXFLAGS) -o $(NAME)

# DIRECTORY
$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

mlx_clone :
	@if [ -d "MLX42" ]; then \
		echo "MLX42 directory already exists. Skipping cloning."; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cd MLX42 && cmake -B build && cd build && make && cd ../..;\
	fi

clean :
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJ_DIR)
	$(REMOVE) $(MLX42_DIR)

fclean : clean
	$(REMOVE) $(NAME)

re : fclean all

.PHONY : all mlx_clone clean fclean re