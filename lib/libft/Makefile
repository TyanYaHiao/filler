#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsmith <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 19:16:24 by fsmith            #+#    #+#              #
#    Updated: 2018/12/01 19:16:26 by fsmith           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

OBJ_PATH :=	.obj/
SRC_PATH :=	src/
INC_PATH :=	includes/

CC :=		gcc
CFLAGS :=	-g -Wall -Wextra -Werror
IFLAGS :=	-I $(INC_PATH)

HFILES :=	libft

FILES :=	ft_abs ft_abs_double ft_atoi_base ft_atoi_hex ft_atoi ft_bzero\
			ft_catstr ft_count_words ft_diff_double ft_dtoa ft_fibonacci\
			ft_is_sort ft_isalnum ft_isalpha ft_isascii ft_isdigit\
			ft_isprint ft_itoa_base_big_h ft_itoa_base_big_hh\
			ft_itoa_base_big_l ft_itoa_base_big_ll ft_itoa_base_big\
			ft_itoa_base_small_h ft_itoa_base_small_hh ft_itoa_base_small_l\
			ft_itoa_base_small_ll ft_itoa_base_small ft_itoa_h ft_itoa_hh\
			ft_itoa_l ft_itoa_ll ft_itoa ft_itoalen ft_lstadd ft_lstdel\
			ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_max ft_memalloc\
			ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove\
			ft_memset ft_min ft_power ft_putchar_fd ft_putchar\
			ft_putendl_fd ft_putendl ft_putnbr_fd ft_putnbr ft_putstr_fd\
			ft_putstr ft_recursive_factorial ft_recursive_power\
			ft_round_double ft_sqrt_up ft_sqrt ft_strcat ft_strchr\
			ft_strchrn ft_strclr ft_strcmp ft_strcpy ft_strcut ft_strdel\
			ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin\
			ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat\
			ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr\
			ft_strrchr ft_strrejoin ft_strrev ft_strsplit ft_strstr\
			ft_strsub ft_strtrim ft_tolower ft_toupper ft_utoa_h\
			ft_utoa_hh ft_utoa_l ft_utoa_ll ft_utoa get_next_line

HDRS =		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS =		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS =		$(addprefix $(OBJ_PATH), $(addsuffix .o, $(FILES)))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@ar rc libft.a $(OBJS)
	@ranlib libft.a
	@echo "\n$(GREEN)libft.a created$(RESET)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDRS)
	@$(CC) $(CFLAGS) -c $(IFLAGS) $< -o $@
	@echo -n '.'

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)libft objs deleted$(RESET)"

fclean: clean
	@rm -rf libft.a
	@echo "$(RED)libft.a deleted$(RESET)"

re: fclean all
