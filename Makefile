#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oltkache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 14:09:37 by oltkache          #+#    #+#              #
#    Updated: 2018/02/17 14:09:38 by oltkache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC = main.c get_info.c get_room.c get_output.c search.c ft_nodes.c routes.c \
	del.c get_routes.c move_ants.c extra.c extra2.c

OBJ = main.o get_info.o get_room.o get_output.o search.o ft_nodes.o routes.o \
	del.o get_routes.o move_ants.o extra.o extra2.o

FLAGS = -Wall -Wextra -Werror

all: sub $(NAME)
	
sub:
	$(MAKE) -C ./libft

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) libft/libft.a

clean: subcl
	rm -f $(OBJ)

subcl:
	$(MAKE) -C ./libft clean

fclean: subf clean
	rm -f $(NAME)

subf:
	$(MAKE) -C ./libft fclean

re: fclean all

%.o : %.c
	gcc $(FLAGS) -c $<
	