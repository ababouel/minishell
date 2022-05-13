# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 23:35:29 by ababouel          #+#    #+#              #
#    Updated: 2022/05/14 00:55:08 by ababouel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAGENTA = \033[35m
RED = \e[1;31m
YELLOW = \e[93;5;226m
CURVE = \e[33;3m
RESET =  \e[0m
GRAY	=	\e[33;2;37m
GREEN = \033[0;32m
###
CC = cc
CFLAGS = -Wall -Werror -Wextra 
BDIR = build
FILES = main parse/lexer parse/token\
		tools/ft_split tools/ft_strncmp tools/lsnode tools/ft_strdup
		
NAME = minishell
OBJ = $(addprefix $(BDIR)/, $(FILES:=.o))
INC = -I ./inc 
HEADERS = inc/minishell.h inc/lib.h inc/token.h inc/lsnode.h inc/lexer.h

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GRAY)-COMPILING Minishell...\n"
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "$(GREEN)Done !"

$(BDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
clean:
	@printf "$(RED)Deleting build\n"
	@rm -rf build

fclean: clean
	@printf "$(RED)Deleting minishell\n"
	@rm -rf minishell 

re: fclean all

.PHONY : re all clean fclean
