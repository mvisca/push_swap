# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 18:40:44 by mvisca-g          #+#    #+#              #
#    Updated: 2023/08/04 17:47:31 by mvisca           ###   ########.fr        #
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

PS_INC_DIR		:=	include

LIB_DIR			:=	libft
LIB_INC_DIR		:=	libft/include
LIB_TGT			:=	libft/libft.a

SRCS_DIR		:=	src
OBJS_DIR		:=	obj

FILES			:=	push_swap.c								\
					push_swap_commands.c					\
					push_swap_debug.c						\
					push_swap_list_tools.c					\
					push_swap_mem_utils.c					\
					push_swap_parse.c						\
					push_swap_sort.c						\
					push_swap_sort_utils_a.c				\
					push_swap_sort_utils_b2a.c				\
					push_swap_sort_utils_b.c				\
					push_swap_sort_utils_long.c				\
					push_swap_sort_utils_three.c			\
					push_swap_sort_utils_five.c				\
					push_swap_sort_utils_two.c

SRCS			:=	$(addprefix $(SRCS_DIR)/, $(FILES))

OBJS			:=	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.o))

DEPS			:=	$(addprefix $(OBJS_DIR)/, $(FILES:.c=.d))

#-------------------#
#	UTILS			#
#-------------------#

CC				:=	gcc #-g -fsanitize=address

CFLAGS			:=	-Wall -Wextra -Werror -MMD

RM				:=	rm -r -f
MAKEFLAGS		+=	--no-print-directory

#-------------------#
#	RECIPES			#
#-------------------#

all: $(NAME)

$(NAME): $(OBJS) $(LIB_TGT)
	@echo "$(YELLOW)Compiling... $(BLUE)$@ $(NC)"
	@$(CC) $(CFLAGS) -L/$(LIB_DIR) -lft -I/$(PS_INC_DIR) -I/$(LIB_INC_DIR) $(OBJS) $(CPPFLAGS) -o $@

%.o: $(SRCS:%.c) Makefile
	@echo "$(YELLOW)Creating... $(BLUE)$@$(NC)"
	@$(CC) $(CPFLAGS) -I/$(PS_INC_DIR) -I/$(LIB_INC_DIR) $< -o $(OBJS_DIR)/$@

$(LIB_TGT):
	@echo "Calling LIB_DIR make"
	@$(MAKE) -C $(LIB_DIR)
-include $(DEPS)

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
	@echo "Making . make"
	@$(MAKE) -C . $(NAME)

.PHONY: clean fclean all
