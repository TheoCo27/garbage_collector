# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 17:29:12 by tcohen            #+#    #+#              #
#    Updated: 2024/10/13 19:36:17 by tcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRCS = srcs/main.c srcs/garbage.c srcs/ft_malloc.c srcs/ft_free.c 
INCLUDE_DIRS = ./srcs ./libft
LIBFT = libft.a
LIB_DIR = ./libft
OBJ_DIR = obj
OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -g3
LFLAGS = -L$(LIB_DIR) -lft

NAME = garbage_collector

# Génère des flags d'inclusion pour chaque répertoire dans INCLUDE_DIRS
INCLUDES = $(foreach dir, $(INCLUDE_DIRS), -I$(dir))

all: $(LIBFT) $(NAME)

# Crée le dossier obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compile chaque .o dans le dossier obj
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Génère la libft.a
$(LIBFT): 
	$(MAKE) -C $(LIB_DIR)

# Crée l'exécutable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
