# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/02 15:17:33 by eaptekar          #+#    #+#              #
#    Updated: 2018/09/23 15:52:23 by eaptekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RTv1

CC		= gcc
FLAGS	= -Wall -Wextra -Werror -lm -g
#MLX		= -lmlx -framework OpenGL -framework AppKit
MLX  = -lmlx -lXext -lX11
LIBFT	= $(P_LFT)libft.a

SRCS	=	main.c		raytracing.c	initialization.c	intersection.c			parsing.c	\
			math.c		quaternion.c	rotate.c			color.c					hooks.c		\
			scenes/demo_sphere.c							scenes/light/light_sphere.c			\
			scenes/demo_cylinder.c							scenes/light/light_cylinder.c		\
			scenes/demo_cone.c								scenes/light/light_cone.c			\
			scenes/three_spheres.c							scenes/light/light_three_spheres.c	\
			scenes/room.c									scenes/light/light_room.c			\
			scenes/figures.c								scenes/light/light_figures.c		\
			scenes/columns.c								scenes/light/light_columns.c		\
			scenes/sphere_mirror.c							scenes/light/light_sphere_mirror.c	\
			parser/parser.c parser/readers.c 

SRC_DIR	= src/
OBJ_DIR	= obj/
I_INC	= includes/
I_LFT	= libft/includes/
P_LFT	= libft/

INC 	= $(addprefix -I,$(I_INC) $(I_LFT))
SRC 	= $(addprefix $(SRC_DIR),$(SRCS))
OBJ 	= $(addprefix $(OBJ_DIR),$(OBJS))

OBJS 	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)
	@echo "\n$(NAME) is ready"

$(LIBFT):
	@make -C $(P_LFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(I_INC)rtv1.h
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/parser $(OBJ_DIR)/scenes $(OBJ_DIR)/scenes/light
	@$(CC) $(FLAGS) $< -o $@ -c $(INC)
	@echo -n █

clean:
	@make -C $(P_LFT) clean
	@rm -rf $(OBJ_DIR)
	@echo "removing ./obj/"

fclean: clean
	@make -C $(P_LFT) fclean
	@rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all
