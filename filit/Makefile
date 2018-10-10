# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 12:11:18 by otahirov          #+#    #+#              #
#    Updated: 2018/10/10 12:43:41 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
LIB=libft.a
LIB_P=../libft/

SRC=main.c fillit_solve.c ft_boardclean.c ft_piececol.c ft_setboard.c ft_undoboard.c \
	ft_pieceslen.c
INC_LIB=../libft/includes
INC=.

CFLAGS = -Wall -Wextra -Werror

CLANG = gcc

all : $(NAME)

$(NAME) : $(LIB) 
	@$(CLANG) $(CFLAGS) -o $@ $(SRC) -I $(INC) -I $(INC_LIB) -L $(LIB_P) -lft
	@echo "Compiled!"

$(LIB) : 
	@make -C $(LIB_P)
	@echo "Library was Compiled!"

clean :
	@make -C $(LIB_P) clean
	@echo "Object files were cleaned"

fclean :
	@make -C $(LIB_P) fclean
	@rm -f $(NAME)
	@echo "Object files were cleaned with the $(LIB)!"
	@echo "$(NAME) was removed!"

re : fclean all