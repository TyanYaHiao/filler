# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 19:40:29 by fsmith            #+#    #+#              #
#    Updated: 2019/09/07 13:36:06 by fsmith           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			fsmith.filler

SRC_PATH :=		src/
INC_PATH :=		includes/
LIB_PATH :=		lib/libft/
OBJ_PATH :=		.obj/

CC :=			clang
CFLAGS :=		-g -Wall -Wextra -Werror
IFLAGS :=		-I $(INC_PATH) -I $(LIB_PATH)
LFLAGS :=		-lft -L $(LIB_PATH)

HFILES :=		fl_filler
FILES :=		fl_main fl_solver fl_parser fl_utils fl_errors
LIB :=			$(LIB_PATH)libft.a

HDRS :=			$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=			$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=			$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	@ $(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)fsmith.filler created$(RESET)"
$(LIB):
	@ $(MAKE) -C $(dir $@) $(notdir $@)

$(OBJ_PATH):
	@ mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	@ $(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo -n '.'

clean: mclean
	@ make clean -C $(LIB_PATH)
	@ echo "$(RED)Filler objs deleted$(RESET)"
fclean: mfclean
	@ make fclean -C $(LIB_PATH)
	@echo "$(RED)Filler deleted$(RESET)"
re: fclean all

mclean:
	@ rm -f $(OBJS) $(DEPS)

mfclean:
	@ rm -f $(NAME)
	@ rm -rf $(OBJ_PATH)
	@ echo "$(RED)Filler objs deleted$(RESET)"

mre: mfclean all
norm:
	norminette src/*.c
	norminette libft/*.c
	norminette libft/*.h
	norminette includes/*.h

.PHONY: $(LIB) all clean fclean re mclean mfclean mre norm

try:
	./resources/filler_vm -p1 ./fsmith.filler -p2 resources/players/superjeannot.filler -f resources/maps/map00