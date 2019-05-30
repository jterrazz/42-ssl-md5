# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 18:00:29 by jterrazz          #+#    #+#              #
#    Updated: 2019/05/30 16:18:59 by jterrazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH = inc
LIB_PATH = libs
BUILD_PATH = obj
SRC_PATH = src

SOURCES += ft_ssl.c ft_errno.c
SOURCES += cmd/clean.c cmd/constants.c cmd/flag.c cmd/init.c cmd/reader.c \
	cmd/run.c
SOURCES += ft_md5/constants.c ft_md5/md5.c ft_md5/ops_bits.c ft_md5/ops_g.c
SOURCES += ft_sha256/constants.c ft_sha256/ops_bits.c ft_sha256/ops_rotation.c \
	ft_sha256/sha256.c
SOURCES += shared/ft_buffer.c shared/ft_hash_builder.c shared/ft_invert_bits.c \
	shared/ft_msg_padding.c shared/ft_rotate_bits.c shared/ft_uitoa_base.c

LIB_SOURCES = $(LIB_PATH)/libft/libft.a $(LIB_PATH)/ft_printf/libftprintf.a

OBJECTS = $(SOURCES:%.c=$(BUILD_PATH)/%.o)

# **************************************************************************** #
# VARIABLES         														   #
# **************************************************************************** #

NAME = ft_ssl

CC = gcc

FLAGS_CC = -Wall -Wextra -Werror

# **************************************************************************** #
# COMMANDS  		    													   #
# **************************************************************************** #

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -s -C $(LIB_PATH)/ft_printf
	@echo "Make ft_printf \033[33mok\033[0m"
	@make -s -C $(LIB_PATH)/libft
	@echo "Make libft \033[33mok\033[0m"
	$(CC) $(FLAGS_CC) -o $@ $^ $(LIB_SOURCES)
	@echo "Compilation successful"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS_CC) -c -o $@ $< -I $(INC_PATH)

clean:
	@make clean -C $(LIB_PATH)/ft_printf
	@make clean -C $(LIB_PATH)/libft
	@rm -rf $(BUILD_PATH)
	@echo "Clean \033[33mok\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)/ft_printf
	@make fclean -C $(LIB_PATH)/libft
	@rm -f $(NAME) $(LIB_NAME)
	@echo "Fclean \033[33mok\033[0m"

re: fclean $(NAME)
