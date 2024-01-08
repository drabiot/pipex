# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 17:25:51 by tchartie          #+#    #+#              #
#    Updated: 2023/12/27 17:40:43 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME		=		pipex

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

INCLUDE_DIR	=		include
INCLUDE		=		$(INCLUDE_DIR)/pipex.h

LIBFT_DIR	=		libft
PRINTF_DIR	=		ft_printf

SRCS_DIR	=		src/
OBJS_DIR	=		obj/

SRCS		=		main.c \
					access.c \
					error_check.c \
					append_link_list.c \
					lst_utils.c \
					process.c \
					check.c \
					display.c

OBJS		=		$(SRCS:.c=.o)

SRCS_F		=		$(addprefix $(SRCS_DIR),$(SRCS))
OBJS_F		=		$(addprefix $(OBJS_DIR),$(OBJS))

#========= EXECUTABLE =========#

all :				$(NAME)

makelibft :
					@make -C $(LIBFT_DIR) all --no-print-directory
makeprintf :
					@make -C $(PRINTF_DIR) all --no-print-directory

$(NAME) :			$(OBJS_F) | makelibft makeprintf
					@$(CC) $(OBJS_F) -o $(NAME) -Llibft -lft -Lft_printf -l:ft_printf.a -I$(INCLUDE_DIR)
					@echo "$(GREEN)Pipex successfully compiled! $(BASE_COLOR)"

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(INCLUDE)
					@mkdir -p $(OBJS_DIR)
					@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"
					@$(CC) $(GFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean :
					@rm -rf $(OBJS_DIR)
					@make -C $(LIBFT_DIR) clean --no-print-directory
					@make -C $(PRINTF_DIR) clean --no-print-directory
					@echo "$(BLUE)Pipex objects files cleanned! $(BASE_COLOR)"

fclean :
					@rm -rf $(OBJS_DIR)
					@echo "$(BLUE)Pipex objects files cleanned! $(BASE_COLOR)"
					@rm -rf $(NAME)
					@echo "$(CYAN)Pipex executable file cleanned! $(BASE_COLOR)"
					@make -C $(LIBFT_DIR) fclean --no-print-directory
					@make -C $(PRINTF_DIR) fclean --no-print-directory
					
re :				fclean all

.PHONY :			all makelibft makeprintf clean fclean re
