# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvannest <gvannest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 14:25:36 by gvannest          #+#    #+#              #
#    Updated: 2020/03/06 18:56:05 by gvannest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

#COMPILATION
CC = 		ar
LFLAGS = 	-rcs
CFLAGS =	-g -Wall -Wextra -Werror
ASM = 		nasm
ASFLAGS =	-f macho64

#BINARY
NAME = libasm.a

#PATHS
SRC_PATH = 			./
SRC_BONUS_PATH = 	./bonus/

OBJ_PATH =	objs/

#SOURCES
SRC = 		ft_strcpy.s ft_strlen.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRC_BONUS =	ft_atoi_base.s

# LD = 		ld
# LDFLAGS = 	-lSystem -macosx_version_min 10.14
# CC =		gcc
#OBJECTS
OBJ_NAME =	$(SRC:%.s=%.o)
OBJ_BONUS_NAME =	$(SRC_BONUS:%.s=%.o)

#PREFIXES
OBJS =			$(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJS_BONUS =	$(addprefix $(OBJ_PATH),$(OBJ_BONUS_NAME))

all : $(NAME)

$(NAME): Makefile $(OBJ_PATH) $(OBJS)
	@ $(CC) $(LFLAGS) $(NAME) $(OBJS)
	@ echo "--------------------------- library compiled"

bonus : Makefile $(OBJ_PATH) $(OBJS_BONUS)
	@ $(CC) $(LFLAGS) $(NAME) $(OBJS_BONUS)
	@ echo "--------------------------- bonus added to library"

$(OBJ_PATH):
	@ mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o : $(SRC_PATH)%.s
	@ $(ASM) $(ASFLAGS) $^ -o $@

$(OBJ_PATH)%.o : $(SRC_BONUS_PATH)%.s
	@ $(ASM) $(ASFLAGS) $^ -o $@

clean :
	@ rm -rf $(OBJ_PATH)

fclean: clean
	@ rm -f $(NAME)

re : fclean all
