# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/25 13:02:54 by wbraeckm          #+#    #+#              #
#    Updated: 2018/10/18 18:37:07 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap
NAME_VISU = visualizer
CC = gcc
FLAGS = -O3 -Wall -Wextra -Werror
INCLUDES = ./includes/
SRCSFOLDER = ./srcs/
OBJFOLDER = ./obj/
LIBFOLDER = ./libft/
LIBINCLUDES = ./libft/includes/
LIBFT = $(LIBFOLDER)libft.a
MLXFOLDER = ./minilibx/
MLXINCLUDES = ./minilibx/
MLX = $(MLXFOLDER)libmlx.a

ITEMS = $(shell find srcs -type f | grep -E "\.c$$" | sed 's/srcs//g')
SRCS = $(addprefix $(SRCSFOLDER), $(ITEMS))
OBJ = $(addprefix $(OBJFOLDER), $(ITEMS:.c=.o))
SRCSUBS = $(shell find ./srcs -type d)
OBJSUBS = $(SRCSUBS:./srcs%=./obj%)
LONGEST = $(shell echo $(notdir $(SRCS)) | tr " " "\n" | \
	awk ' { if ( length > x ) { x = length; y = $$0 } }END{ print y }' | wc -c)

CHECKEROBJ = $(shell find srcs/common srcs/checker -type f | grep -E "\.c$$" \
| sed -e 's/^srcs/obj/g' | sed 's/.c$$/.o/g')
PUSHSWAPOBJ = $(shell find srcs/common srcs/pushswap -type f | grep -E "\.c$$" \
| sed -e 's/^srcs/obj/g' | sed 's/.c$$/.o/g')
VISUOBJ = $(shell find srcs/common srcs/visualizer -type f \
| grep -E "\.c$$" \
| sed -e 's/^srcs/obj/g' | sed 's/.c$$/.o/g')

ccblue = "\33[0;34m"
ccred = "\033[0;91m"
ccgreen = "\033[0;92m"
ccgreenhard = "\033[0;32m"
cccyan = "\033[0;96m"
ccreset = "\033[0;0m"
cclightgray = "\033[0;37m"

all: lib mlx $(NAME_CHECKER) $(NAME_PUSHSWAP) $(NAME_VISU)

$(OBJFOLDER)/%.o:$(SRCSFOLDER)/%.c
	@printf $(ccblue)
	@printf "Compiling %-$(LONGEST)s" $(notdir $<)
	@$(CC) $(FLAGS) -o $@ -c $< -I$(INCLUDES) -I$(LIBINCLUDES) -I$(MLXINCLUDES)
	@printf $(cclightgray)[$(ccgreenhard)√$(cclightgray)]$(ccreset)
	@printf "\r"

$(OBJSUBS):
	@mkdir $@

mlx:
	@make -C $(MLXFOLDER)

lib:
	@make -C $(LIBFOLDER)

$(NAME_CHECKER): $(OBJSUBS) $(OBJ)
	@printf $(cccyan)
	@printf "Compiling $(NAME_CHECKER) "
	@$(CC) $(FLAGS) -o $(NAME_CHECKER) $(CHECKEROBJ) -I$(INCLUDES) \
-I$(LIBINCLUDES) $(LIBFT)
	@printf $(cclightgray)[$(ccgreenhard)√$(cclightgray)]$(ccreset)
	@printf "                                                     \n"

$(NAME_PUSHSWAP): $(OBJSUBS) $(OBJ)
	@printf $(cccyan)
	@printf "Compiling $(NAME_PUSHSWAP) "
	@$(CC) $(FLAGS) -o $(NAME_PUSHSWAP) $(PUSHSWAPOBJ) -I$(INCLUDES) \
-I$(LIBINCLUDES) $(LIBFT)
	@printf $(cclightgray)[$(ccgreenhard)√$(cclightgray)]$(ccreset)
	@printf "                                                     \n"

$(NAME_VISU): $(OBJSUBS) $(OBJ)
	@printf $(cccyan)
	@printf "Compiling $(NAME_VISU) "
	@$(CC) $(FLAGS) -o $(NAME_VISU) $(VISUOBJ) -I$(INCLUDES) \
-I$(LIBINCLUDES) $(LIBFT) -I$(MLXINCLUDES) $(MLX) -framework OpenGL -framework AppKit
	@printf $(cclightgray)[$(ccgreenhard)√$(cclightgray)]$(ccreset)
	@printf "                                                     \n"

clean:
	@printf $(ccred)
	rm -rf obj/
	@make -C $(LIBFOLDER) clean
	@make -C $(MLXFOLDER) clean
	@printf $(ccreset)

fclean: clean
	@printf $(ccred)
	rm -rf $(NAME_PUSHSWAP) $(NAME_CHECKER)
	@make -C $(LIBFOLDER) fclean
	@printf $(ccreset)

re: fclean all

norm:
	@norminette $(SRCSFOLDER) $(INCLUDES)

.PHONY: norm clean fclean re
