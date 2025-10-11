# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 09:35:18 by hermarti          #+#    #+#              #
#    Updated: 2025/10/11 17:55:14 by hermarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

LIBFT := libft/libft.a
LIBFT_INC := libft/inc/

INC_DIR := inc/
INC_BONUS_DIR := inc_bonus/

SRC_DIR := src/
SRC_BONUS_DIR := src_bonus/

OBJ_DIR := obj/

INC := $(INC_DIR)push_swap.h
INC_BONUS := $(INC_BONUS_DIR)push_swap_bonus.h

SRCS := $(SRC_DIR)main.c \
		$(SRC_DIR)stack.c \
		$(SRC_DIR)stack_func.c \
		$(SRC_DIR)stack_func_utils.c \
		$(SRC_DIR)stack_func_utils2.c \
		$(SRC_DIR)stack_func_bot.c \
		$(SRC_DIR)stack_func_top.c \
		$(SRC_DIR)ps_stack_func.c \
		$(SRC_DIR)ps_stack_func2.c \
		$(SRC_DIR)ps_stack_func3.c \
		$(SRC_DIR)error.c \
		$(SRC_DIR)env.c \
		$(SRC_DIR)sort.c \
		$(SRC_DIR)sort_large.c \
		$(SRC_DIR)sort_large2.c \
		$(SRC_DIR)sort_large_cheap.c \
		$(SRC_DIR)sort_large_cheap2.c \
		$(SRC_DIR)sort_small.c \
		$(SRC_DIR)args_handler.c \
		$(SRC_DIR)numbers_handler.c \

SRCS_BONUS := $(SRCS_BONUS_DIR)main.c

OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
OBJS_BONUS := $(patsubst $(SRC_BONUS_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS_BONUS))

CC := cc
CFLAGS := -I$(LIBFT_INC) -Wall -Wextra -Werror

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g2 -O0
endif

RM = rm -f

.PHONY: all bonus clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_BONUS_DIR)%.c $(INC_BONUS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_BONUS_DIR) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -I$(INC_DIR) -o $@

bonus: $(LIBFT) .bonus
	@:

.bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -I$(INC_BONUS_DIR) -o $(NAME)
	@touch .bonus

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
