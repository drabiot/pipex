# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 18:05:50 by tchartie          #+#    #+#              #
#    Updated: 2023/11/09 01:17:11 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME		=		ft_printf.a

#========= COMPILATOR =========#

CC			=		clang

#=========== FLAGS ============#

CFLAGS		=		-Wall -Wextra -Werror	#Usual flags
GFLAGS		=		$(CFLAGS) -g			#Flag for gdb or valgrind

#=========== COLOR ============#

BASE_COLOR 	=		\033[0;39m
GRAY 		=		\033[0;90m
RED 		=		\033[0;91m
GREEN 		=		\033[0;92m
YELLOW 		=		\033[0;93m
BLUE 		=		\033[0;94m
MAGENTA		=		\033[0;95m
CYAN 		=		\033[0;96m
WHITE		=		\033[0;97m

#========== SOURCES ===========#

INCLUDE		=		../include/ft_printf.h

SRCS_DIR	=		src/
OBJS_DIR	=		obj/

SRCS 		= 		ft_printf.c \
					ft_putchar.c \
					ft_putnbr.c \
					ft_putnbr_unsigned.c \
					ft_putstr.c \
					ft_conv_hexa.c\
					ft_point_to_hexa.c
					
OBJS 		=		$(SRCS:.c=.o)

SRCS_F		=		$(addprefix $(SRCS_DIR),$(SRCS))
OBJS_F		=		$(addprefix $(OBJS_DIR),$(OBJS))

#========= EXECUTABLE =========#

all : 				$(NAME)

$(NAME) : 			$(OBJS_F)
					@ar -rcs $(NAME) $(OBJS_F)
					@echo "$(GREEN)Printf successfully compiled! $(BASE_COLOR)"

$(OBJS_DIR)%.o : 	$(SRCS_DIR)%.c $(INCLUDE)
					@mkdir -p $(OBJS_DIR)
					@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"
					@$(CC) $(CFLAGS) -c $< -o $@

clean :
					@rm -rf $(OBJS_DIR)
					@echo "$(BLUE)Printf objects files cleanned! $(BASE_COLOR)"

fclean :			clean
					@rm -rf $(NAME)
					@echo "$(CYAN)Printf executable file cleanned! $(BASE_COLOR)"

re :				fclean all
					@echo "$(GREEN)Cleanned and rebuild Printf! $(BASE_COLOR)"
	
.PHONY :			all clean fclean re
