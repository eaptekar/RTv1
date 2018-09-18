# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/02 15:17:33 by eaptekar          #+#    #+#              #
#    Updated: 2018/09/18 18:05:45 by eaptekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RTv1

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
MLX		= -lmlx -framework OpenGL -framework AppKit
LIBFT	= $(P_LFT)libft.a

SRCS	= main.c scene.c raytracing.c math.c color.c hooks.c intersection.c\

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
	@mkdir -p $(OBJ_DIR)
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
