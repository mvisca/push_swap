# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 18:40:44 by mvisca-g          #+#    #+#              #
#    Updated: 2023/08/03 13:23:52 by mvisca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------#
#	FORMAT			#
#-------------------#

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
NC				:= \033[0m

#-------------------#
#	TARGET			#
#-------------------#

NAME			:=	push_swap

#-------------------#
#	INGREDIENTS		#
#-------------------#

INC_DIR			:=	include

LIB_DIR			:=	libft
LIB_TGT			:=	libft.a
LIB				:=	ft

SRCS_DIR		:=	src

SRCS			:=	push_swap.c							\
					push_swap_commands.c				\
					push_swap_debug.c					\
					push_swap_list_tools.c				\
					push_swap_mem_utils.c				\
					push_swap_parse.c					\
					push_swap_sort.c					\
					push_swap_sort_utils_a.c			\
					push_swap_sort_utils_b2a.c			\
					push_swap_sort_utils_b.c			\
					push_swap_sort_utils_long.c			\
					push_swap_sort_utils_three.c		\
					push_swap_sort_utils_five.c			\
					push_swap_sort_utils_two.c

SRCS			:=	$(addprefix $(SRCS_DIR)/, $(SRCS))

#DEPS			:=	$(SRCS:.c=.d)

#-------------------#
#	UTILS			#
#-------------------#

CC				:=	gcc #-g -fsanitize=address

CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=	-I./$(INC_DIR) -I./$(LIB_DIR)/$(INC_DIR)	\
					-L./$(LIB_DIR) -l$(LIB)

RM				:=	rm -r -f
MAKEFLAGS		+=	--no-print-directory

#-------------------#
#	RECIPES			#
#-------------------#

all: $(NAME)

$(NAME): $(LIB_TGT)
	@echo "$(YELLOW)Compiling... $(BLUE)$@$(NC)"
	@$(CC) $(CFLAGS) $(SRCS) $(CPPFLAGS) -o $@

$(LIB_TGT):
	@echo "Calling LIB_DIR make"
	@$(MAKE) -C $(LIB_DIR)
#-include $(DEPS)

clean:
	@echo "Cleaning LIB_DIR make clean"
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleting... $(NC)$(NAME) $(RED)>> 🗑️$(NC)"
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

callforlib:
	@echo "Making LIB_DIR make"
	@$(MAKE) -C $(LIB_DIR)
	@echo "Makeing . make"
	@$(MAKE) -C . $(NAME)

.PHONY: clean fclean all
