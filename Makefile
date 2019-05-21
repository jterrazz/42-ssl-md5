# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 18:00:29 by jterrazz          #+#    #+#              #
#    Updated: 2019/05/21 19:46:05 by jterrazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# FILES             														   #
# **************************************************************************** #

PATH_INC = inc
PATH_LIB = lib
PATH_OBJ = obj
PATH_SRC = src

SOURCES += ft_ssl.c ft_errno.c
SOURCES += cmd/clean.c cmd/constants.c cmd/flag.c cmd/init.c cmd/reader.c \
	cmd/run.c
SOURCES += ft_md5/constants.c ft_md5/md5.c ft_md5/ops_bits.c ft_md5/ops_g.c
SOURCES += ft_sha256/constants.c ft_sha256/ops_bits.c ft_sha256/ops_rotation.c \
	ft_sha256/sha256.c
SOURCES += shared/ft_buffer.c shared/ft_hash_builder.c shared/ft_invert_bits.c \
	shared/ft_msg_padding.c shared/ft_rotate_bits.c shared/ft_uitoa_base.c

OBJECTS = $(SOURCES:%.c=$(PATH_OBJ)/%.o)

# **************************************************************************** #
# VARIABLES         														   #
# **************************************************************************** #

NAME = ft_ssl

CC = gcc

FLAGS_CC = -Wall -Wextra -Werror
FLAGS_LCC = -Wall -Wextra -Werror

LIBS = lib/libft/libft.a lib/ft_printf/libftprintf.a

# **************************************************************************** #
# COMMANDS  		    													   #
# **************************************************************************** #

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -s -C lib/ft_printf
	@echo "Make ft_printf \033[33mok\033[0m"
	@make -s -C lib/libft
	@echo "Make libft \033[33mok\033[0m"
	$(CC) $(FLAGS_LCC) -o $@ $^ $(LIBS)
	@echo "Compilation successful"

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS_CC) -c -o $@ $< -I inc

clean:
	@make clean -C lib/ft_printf
	@make clean -C lib/libft
	@rm -rf $(PATH_OBJ)
	@echo "Clean \033[33mok\033[0m"

fclean: clean
	@make fclean -C lib/ft_printf
	@make fclean -C lib/libft
	@rm -f $(NAME) $(LIB_NAME)
	@echo "Fclean \033[33mok\033[0m"

re: fclean $(NAME)
