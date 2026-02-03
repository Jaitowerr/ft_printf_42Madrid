# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 17:32:47 by aitorres          #+#    #+#              #
#    Updated: 2026/01/30 19:16:55 by aitorres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c\
			ft_putendl_fd.c

OBJ		=	$(SRC:.c=.o)

AR		=	ar rcs
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)	#crea la librería con todos los objetos (incluyendo listas)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(NAME) creado."

%.o:		%.c	#para compilar cualquier .c a .o
			@$(CC) $(FLAGS) -c $< -o $@

clean:		
			@rm -f $(OBJ)
			@echo "Objetos eliminados."
			
fclean:		clean
			@rm -f $(NAME)
			@echo "Librería eliminada."

re:			fclean	all	#recompila desde cero

# bonus: $(NAME)

# make        # Compila todo
# make clean  # Borra objetos
# make fclean # Borra objetos y librería
# make re     # Limpia y recompila