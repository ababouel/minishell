# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 23:21:55 by ababouel          #+#    #+#              #
#    Updated: 2022/07/05 09:39:08 by ababouel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



MAGENTA = \033[35m
RED = \e[1;31m
YELLOW = \e[93;5;226m
CURVE = \e[33;3m
RESET =  \e[0m
GRAY	=	\e[33;2;37m
GREEN = \033[0;32m
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
BDIR = build
FILES = main lexer/lexer lexer/lexerbis lexer/token  lexer/lexerlst parse/parstree\
		parse/parselst/parsecmd parse/parselst/parsepipe parse/parselst/parseio parse/parselst/parsetool\
		tools/ft_split tools/ft_strncmp tools/lsnode tools/ft_strdup tools/ft_strjoin tools/freestack\
		tools/ft_isalpha exec/built exec/cd exec/echo exec/export_unset exec/pwd_env\
		exec/ft_which exec/execution exec/exectool exec/env_var errors/tokens_check errors/errors
		
NAME = minishell
OBJ = $(addprefix $(BDIR)/, $(FILES:=.o))
INC = -I ./inc -I /Users/ababouel/.brew/opt/readline/include
HEADERS = inc/minishell.h inc/lib.h inc/token.h  inc/lexer.h inc/exec.h

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(GRAY)-COMPILING Minishell...\n"
	@$(CC) $(CFLAGS) $^ -o $@ -lreadline -L/Users/ababouel/.brew/opt/readline/lib
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
