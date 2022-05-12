# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababouel <ababouel@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 23:35:29 by ababouel          #+#    #+#              #
#    Updated: 2022/05/12 17:42:23 by ababouel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc;
CFLAGS = -Wall -Werror -Wextra -lreadline
BDIR = build;
FILES = main.c 

OBJ = $(addprefix $(BDIR)/, $(FILES:=.o))
EXEC = minishell
INC = -I  
HEADERS = minishell.h

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(BDIR)/%.o : %.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	rm -rf build

fclean: clean
	rm -rf minishell 

re: fclean all

.PHONY : re all clean fclean
