# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 12:11:18 by otahirov          #+#    #+#              #
#    Updated: 2018/10/12 12:20:25 by otahirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
LIB=libft.a
LIB_P=libft/
SRC_P=filit/

SRC=$(SRC_P)main.c $(SRC_P)fillit_solve.c $(SRC_P)ft_boardclean.c \
	$(SRC_P)ft_piececol.c $(SRC_P)ft_setboard.c $(SRC_P)ft_undoboard.c \
	$(SRC_P)ft_pieceslen.c $(SRC_P)fillit_print.c $(SRC_P)ft_piecewidth.c \
	$(SRC_P)fillit_mapcheck.c $(SRC_P)pieces.c $(SRC_P)ft_freemap.c

INC_LIB= -I libft/includes
INC= -I filit/

CFLAGS = -Wall -Wextra -Werror

CLANG = gcc

all : $(NAME)

$(NAME) :
	@make -C $(LIB_P)
	@echo "Library was Compiled!"
	@$(CLANG) $(CFLAGS) -o $@ $(SRC) $(INC) $(INC_LIB) -L $(LIB_P) -lft
	@echo "Compiled!"	

clean :
	@make -C $(LIB_P) clean
	@echo "Object files were cleaned"

fclean :
	@make -C $(LIB_P) fclean
	@rm -f $(NAME)
	@echo "Object files were cleaned with the $(LIB)!"
	@echo "$(NAME) was removed!"

re : fclean all
