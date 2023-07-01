# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 18:40:44 by mvisca-g          #+#    #+#              #
#    Updated: 2023/07/01 17:10:59 by mvisca           ###   ########.fr        #
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
LIB_TGT			:=	libft.a
LIB				:=	ft
LIB_DIR			:=	libft
LIB_HEADER		:=	include
SRCS			:=	push_swap.c
# DEPS			:=	$(SRCS:.c=.d)

#-------------------#
#	UTILS			#
#-------------------#
CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=	-I. -I./$(LIB_DIR)/$(LIB_HEADER) -L./$(LIB_DIR) -l$(LIB)

RM				:=	rm -r -f
MAKEFLAGS		+=	--no-print-directory

#-------------------#
#	RECIPES			#
#-------------------#
all: $(NAME)

$(NAME): $(LIB_TGT)
	@echo "$(YELLOW)Compiling... $(BLUE)$@$(NC)"
	@$(CC) $(CFLAGS) $(SRCS) $(CPPFLAGS) -L./libft -lft -o $@

$(LIB_TGT):
	@echo "Making LIB_DIR make"
	@$(MAKE) -C $(LIB_DIR)
# -include $(DEPS)

clean:
	@echo "Making LIB_DIR make clean"
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