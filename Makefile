# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 15:31:09 by ajehle            #+#    #+#              #
#    Updated: 2024/09/14 11:09:55 by ajehle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
REMOVE		= rm -rf
SRC_DIR		= src
OBJ_DIR		= ./obj
B_SRC_DIR	= bonus
B_OBJ_DIR	= ./obj_bonus
INC_DIR		= include
MLX42_DIR	= ./MLX42
CFLAGS		= -Wall -Werror -Wextra -I $(INC_DIR)
LIBXFLAGS	=  -framework Cocoa -framework OpenGL -framework IOKit
MLX_INCLUDE	= MLX42/build/libmlx42.a -Iinclude -lglfw

# looking for files in subdirectories
vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

# INTERNAL FUNCTIONS
FUNCTIONS	=	$(SRC_DIR)/check_map_string.c \
				$(SRC_DIR)/check_map_arr.c \
				$(SRC_DIR)/check_wall.c \
				$(SRC_DIR)/check.c \
				$(SRC_DIR)/exit_map.c \
				$(SRC_DIR)/exit.c \
				$(SRC_DIR)/ft_arr_cpy.c \
				$(SRC_DIR)/helper.c \
				$(SRC_DIR)/hook.c \
				$(SRC_DIR)/init_enemy.c \
				$(SRC_DIR)/init_helper.c \
				$(SRC_DIR)/init_item.c \
				$(SRC_DIR)/init_main.c \
				$(SRC_DIR)/load_textures_floor.c \
				$(SRC_DIR)/load_textures_obstacles.c \
				$(SRC_DIR)/load_textures.c \
				$(SRC_DIR)/unused_at_end.c \
				$(SRC_DIR)/main.c \
				$(SRC_DIR)/moves.c \
				$(SRC_DIR)/parsing.c \
				$(SRC_DIR)/unique.c \
				$(SRC_DIR)/update_display.c \

# BONUS INTERNAL FUNCTIONS
B_FUNCTIONS			=	$(B_SRC_DIR)/animation.c \
						$(B_SRC_DIR)/move_enemy.c \
						$(B_SRC_DIR)/check_collision.c \
# INTERNAL OBJECT
OBJECTS				= $(addprefix $(OBJ_DIR)/, $(notdir $(FUNCTIONS:.c=.o)))

# BONUS INTERNAL OBJECT
B_OBJECTS			= $(addprefix $(B_OBJ_DIR)/, $(notdir $(B_FUNCTIONS:.c=.o)))

# --- EXTERNAL LIBRARYS START --- #
# FT_PRINTF Resources
FT_PRINTF_DIR		= libs/ft_printf
FT_PRINTF			= $(FT_PRINTF_DIR)/libftprintf.a

# FT_LIBFT Resources
FT_LIBFT_DIR		= libs/libft
FT_LIBFT			= $(FT_LIBFT_DIR)/libft.a

# GET_NEXT_LINE Resources
GET_NEXT_LINE_DIR	= libs/get_next_line
GET_NEXT_LINE		= $(GET_NEXT_LINE_DIR)/libget_next_line.a

# EXTERNAL LIBRARY
LIB_FT_PRINTF		= -L$(FT_PRINTF_DIR) -lftprintf
LIB_FT_LIBFT		= -L$(FT_LIBFT_DIR) -lft
LIB_GET_NEXT_LINE	= -L$(GET_NEXT_LINE_DIR) -lget_next_line

# ALL LIBS
LIBS				= $(LIB_FT_PRINTF) $(LIB_FT_LIBFT) $(LIB_GET_NEXT_LINE)
LIBS_NAME			= $(FT_PRINTF) $(FT_LIBFT) $(GET_NEXT_LINE)
# --- EXTERNAL LIBRARYS END --- #

all : mlx_clone $(NAME)

# INTERNAL RULE
$(NAME) : $(LIBS_NAME) $(OBJECTS) $(B_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(B_OBJECTS) $(LIBS) $(MLX_INCLUDE) $(LIBXFLAGS) -o $(NAME)

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

# BONUS DIRECTORY
$(B_OBJ_DIR) :
	mkdir $(B_OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJ_DIR)/%.o: $(B_SRC_DIR)/%.c | $(B_OBJ_DIR)
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
	$(REMOVE) $(B_OBJ_DIR)
#	$(REMOVE) $(MLX42_DIR)

fclean : clean
#	$(MAKE) -C $(FT_LIBFT_DIR) fclean
#	$(MAKE) -C $(FT_PRINTF_DIR) fclean
#	$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	$(REMOVE) $(NAME)

re : fclean all

.PHONY : all mlx_clone clean fclean re
