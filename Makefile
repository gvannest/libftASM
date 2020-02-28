# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <gvannest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 14:25:36 by gvannest          #+#    #+#              #
#    Updated: 2020/02/27 13:20:15 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = exec.out

VPATH = 	#./libft/ ./printf/ ./GNL/
CPPFLAGS = 	#./includes/
MAIN = 		main.c
SRC = 		ft_strcpy.s ft_strlen.s ft_strcmp.s ft_write.s ft_read.s ft_strdup
SRC_NAME =	$(SRC)
ASM = 		nasm
ASFLAGS =	-f macho64
LD = 		ld
LDFLAGS = 	-lSystem -macosx_version_min 10.14
CC =		gcc
CFLAGS =	-g #-Wall -Wextra -Werror
OBJ_PATH =	objs/
OBJ_NAME =	$(SRC_NAME:%.s=%.o)
OBJ_NAME_MAIN =	$(MAIN:%.c=%.o)
OBJS =		$(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_MAIN =	$(addprefix $(OBJ_PATH),$(OBJ_NAME_MAIN))

all : $(NAME)

$(NAME): $(OBJ_MAIN) $(OBJS) link
	@ echo "--------------------------- done"

link:
	@ $(LD) $(LDFLAGS) $(OBJS) $(OBJ_MAIN) -o $(NAME)

$(OBJ_PATH)%.o : %.s
	@ mkdir -p $(OBJ_PATH)
	@ $(ASM) $(ASFLAGS) $^ -o $@

$(OBJ_PATH)%.o : %.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -c $^ -o $@

clean :
	@ rm -rf $(OBJ_PATH)

fclean: clean
	@ rm -f $(NAME)

re : fclean all
