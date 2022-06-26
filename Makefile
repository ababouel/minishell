# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 23:35:29 by ababouel          #+#    #+#              #
#    Updated: 2022/06/26 21:42:44 by sismaili         ###   ########.fr        #
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
FILES = main parse/lexer parse/lexerbis parse/token parse/parstree\
		parse/parselst/parsecmd parse/parselst/parsepipe parse/parselst/parseio\
		tools/ft_split tools/ft_strncmp tools/lsnode tools/ft_strdup tools/ft_strjoin tools/freestack\
		tools/ft_isalpha exec/built exec/cd exec/echo exec/export_unset exec/pwd_env\
		exec/ft_which exec/execution exec/exectool exec/env_var errors/tokens_check errors/errors
		
NAME = minishell
OBJ = $(addprefix $(BDIR)/, $(FILES:=.o))
INC = -I ./inc -I /Users/sismaili/.brew/opt/readline/include
HEADERS = inc/minishell.h inc/lib.h inc/token.h  inc/lexer.h inc/exec.h

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GRAY)-COMPILING Minishell...\n"
	@$(CC) $(CFLAGS) $^ -o $@ -lreadline -L /Users/sismaili/.brew/opt/readline/lib 
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
