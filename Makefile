# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 13:33:19 by mvisca-g          #+#    #+#              #
#    Updated: 2023/06/30 18:38:59 by mvisca-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------#
#	TARGET			#
#-------------------#

NAME			:=	push_swap

#-------------------#
#	INGREDIENTS		#
#-------------------#

LIB				:=	ft
LIB_TGT			:=	libft/libft.a
LIB_DIR			:=	$(dir (LIB_TGT))

SRCS_DIR		:=	src/
SRCS			:=	push_swap.c

DEPS			:=	$(SRCS:.o=.c)

#-------------------#
#	UTILS			#
#-------------------#

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=	-I./libft/include

RM				:=	rm -r -f

MAKEFLAGS		+=	--no-print-directory

#-------------------#
#	FORMAT			#
#-------------------#

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
NC				:= \033[0m

#-------------------#
#	RECIPES			#
#-------------------#

all: $(NAME) callforlib

$(NAME): $(LIB_TGT)
	$(CC) $(CFLAGS) $(CPPFLAGS) -L./libft/include -lft $(SRCS) -o $@

$(LIB_TGT):
	$(MAKE) -C $(@D)
-include $(DEPS)

clean:
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

callforlib:
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C . $(NAME)

.PHONY: clean fclean all callforlib