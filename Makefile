#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblokha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 11:40:29 by vblokha           #+#    #+#              #
#    Updated: 2018/07/03 11:40:31 by vblokha          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ssl

INC = -I ./ft_printf/headers/ -I ./ft_printf/libft/includes/ -I ./headers/

SRC = main.c ft_ssl.c ft_ssl_md5.c ft_ssl_sha256.c errors.c ft_ssl_read.c \
	hash.c

SRCDIR = sources/

OBJDIR = objects/

OBJ =  $(addprefix $(OBJDIR), $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

LIBFTPRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJDIR) $(OBJ)
	@gcc $(OBJ) $(LIBFTPRINTF) -o $(NAME)
	@echo project DONE

$(LIBFTPRINTF):
	@echo make ft_printf
	@make -C ft_printf

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJ) : $(OBJDIR)%.o : $(SRCDIR)%.c ./headers/*.h
	gcc $(FLAGS) $(INC) -c $< -o $@

debug:
	@rm -f debug
	@gcc -g $(INC) $(addprefix $(SRCDIR), $(SRC)) $(LIBFTPRINTF) -o debugFile

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	@make clean -C ft_printf
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all