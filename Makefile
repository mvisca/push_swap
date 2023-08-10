# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 18:40:44 by mvisca-g          #+#    #+#              #
#    Updated: 2023/08/10 16:42:55 by mvisca-g         ###   ########.fr        #
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

PS_INC_DIR		:=	include/
PS_INCLUDE		:=	push_swap.h

LIB_DIR			:=	libft/
LIB_INC_DIR		:=	$(LIB_DIR)include/
LIB_TGT			:=	$(LIB_DIR)libft.a
LIB_HEAD		:=	$(LIB_INC_DIR)libft.h

SRCS_DIR		:=	src/
OBJS_DIR		:=	.build/

FILES			:=	push_swap.c							\
						push_swap_commands.c			\
						push_swap_debug.c				\
						push_swap_list_tools.c			\
						push_swap_mem_utils.c			\
						push_swap_parse.c				\
						push_swap_sort.c				\
						push_swap_sort_utils_a.c		\
						push_swap_sort_utils_b2a.c		\
						push_swap_sort_utils_b.c		\
						push_swap_sort_utils_long.c		\
						push_swap_sort_utils_three.c	\
						push_swap_sort_utils_five.c		\
						push_swap_sort_utils_two.c

SRCS			:=	$(FILES:%=$(SRCS_DIR)%)

OBJS			:=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

DEPS			:=	$(OBJS:.o=.d)

DEPS			+=	$(DEPS_LIB)

#-------------------#
#	UTILS			#
#-------------------#

CC				:=	gcc #-g -fsanitize=address

CFLAGS			:=	-Wall -Wextra -Werror -MMD -MP

DIR_DUP			:=	mkdir -p $(OBJS_DIR)

MAKEFLAGS		+=	--no-print-directory
RM				:=	rm -r -f

#-------------------#
#	RECIPES			#
#-------------------#

all: callforlib $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(RED)$@ $(YELLOW)ready! $(NC)"
	@$(CC) $(CFLAGS) -L./$(LIB_DIR) -lft -I./$(LIB_INC_DIR) -I./$(PS_INC_DIR) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile $(LIB_TGT)
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) -I./$(LIB_INC_DIR) -I./$(PS_INC_DIR) -c $< -o $@
	@echo "$(GREEN)Creating... $(NC) $(notdir $@)"
-include $(DEPS)

# $(LIB_TGT): $(LIB_DIR)Makefile $(LIB_HEAD)
# 	@$(MAKE) -C $(LIB_DIR)

callforlib:
	@$(MAKE) -C $(LIB_DIR)

clean:
	@echo "$(RED)Deleting objects for... $(NC)$(NAME) *.o *.d $(RED)>> 🗑️$(NC)"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleting... $(NC)$(NAME) $(RED)>> 🗑️$(NC)"
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: clean fclean re all callforlib
