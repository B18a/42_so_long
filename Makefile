# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 15:31:09 by ajehle            #+#    #+#              #
#    Updated: 2024/03/22 11:40:37 by ajehle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME2		= so_long2
CC			= cc
REMOVE		= rm -rf
OBJ_DIR		= ./obj
SRC_DIR		= src
INC_DIR		= include
MLX42_DIR	= ./MLX42
CFLAGS		= -Wall -Werror -Wextra -I $(INC_DIR)
LIBXFLAGS	=  -framework Cocoa -framework OpenGL -framework IOKit
MLX_INCLUDE	= MLX42/build/libmlx42.a -Iinclude -lglfw
#MLX_LINUX	= MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

# looking for files in subdirectories
vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

# INTERNAL FUNCTIONS
FUNCTIONS	=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/parsing.c \
				$(SRC_DIR)/ft_exit.c \
				$(SRC_DIR)/ft_initialize.c \
				$(SRC_DIR)/ft_hook.c \
				$(SRC_DIR)/load_textures.c \
				$(SRC_DIR)/ft_check.c \
				$(SRC_DIR)/map_string_check.c \
				$(SRC_DIR)/map_arr_check.c \
				$(SRC_DIR)/load_assets.c \
				$(SRC_DIR)/unused_at_end.c \
				$(SRC_DIR)/unique.c \

# INTERNAL OBJECT
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(notdir $(FUNCTIONS:.c=.o)))

# EXTERNAL LIBRARYS START
# FT_PRINTF Resources
FT_PRINTF_DIR	:= libs/ft_printf
FT_PRINTF		:= $(FT_PRINTF_DIR)/libftprintf.a

# FT_LIBFT Resources
FT_LIBFT_DIR	:= libs/libft
FT_LIBFT		:= $(FT_LIBFT_DIR)/libft.a

# GET_NEXT_LINE Resources
GET_NEXT_LINE_DIR	:= libs/get_next_line
GET_NEXT_LINE		:= $(GET_NEXT_LINE_DIR)/libget_next_line.a

# EXTERNAL LIBRARY
LIB_FT_PRINTF		:= -L$(FT_PRINTF_DIR) -lftprintf
LIB_FT_LIBFT		:= -L$(FT_LIBFT_DIR) -lft
LIB_GET_NEXT_LINE	:= -L$(GET_NEXT_LINE_DIR) -lget_next_line

# ALL LIBS
LIBS			:= $(LIB_FT_PRINTF) $(LIB_FT_LIBFT) $(LIB_GET_NEXT_LINE)
LIBS_NAME		:= $(FT_PRINTF) $(FT_LIBFT) $(GET_NEXT_LINE)
LIBS_DIR		:= $(FT_PRINTF_DIR) $(FT_LIBFT_DIR) $(GET_NEXT_LINE_DIR)
# EXTERNAL LIBRARYS END

all : mlx_clone $(NAME)

#linux : mlx_clone $(NAME2)

# LINUX RULE
#$(NAME2) : $(OBJECTS)
#	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LINUX) -o $(NAME)

# INTERNAL RULE
$(NAME) : $(LIBS_NAME) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) $(MLX_INCLUDE) $(LIBXFLAGS) -o $(NAME)

# EXTERNAL LIBRARYS RULE (1 for each lib)
$(FT_PRINTF) :
	$(MAKE) -C $(FT_PRINTF_DIR)
$(FT_LIBFT) :
	$(MAKE) bonus -C $(FT_LIBFT_DIR)
$(GET_NEXT_LINE) :
	$(MAKE) -C $(GET_NEXT_LINE_DIR)
	$(MAKE) bonus -C $(GET_NEXT_LINE_DIR)

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
#	$(MAKE) -C $(FT_LIBFT_DIR) clean
#	$(MAKE) -C $(FT_PRINTF_DIR) clean
#	$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJ_DIR)
#	$(REMOVE) $(MLX42_DIR)

fclean : clean
#	$(MAKE) -C $(FT_LIBFT_DIR) fclean
#	$(MAKE) -C $(FT_PRINTF_DIR) fclean
#	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	$(REMOVE) $(NAME)

re : fclean all

.PHONY : all mlx_clone linux clean fclean re