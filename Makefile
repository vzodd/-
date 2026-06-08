NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar rcs
RM = rm -rf

GREEN  = "\033[32m"

SOURCE = ft_exit.c\
	ft_printf.c\
	ft_putchar.c\
	ft_atoi.c\
	ft_is_int.c\
	ft_strchr.c\
	ft_strncmp.c\
	ft_split.c\
	stack_ops.c\
	stack_utils.c\
	bench.c\
	bench_utils.c\
	op_swap.c\
	op_push.c\
	op_rotate.c\
	op_reverse.c\
	compute_disorder.c\
	normalize_stack.c\
	sort_simple.c\
	sort_medium.c\
	sort_complex.c\
	sort_adaptive.c\
	parse_nums.c\
	parse_nums_utils.c\
	push_swap.c
OBJ = $(SOURCE:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

all: $(NAME)
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo $(GREEN)"Library created."

bonus:	$(OBJ) $(OBJ_BONUS)
	@$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "Object files removed."

fclean:
	@$(RM) $(OBJ) $(OBJ_BONUS) && $(RM) $(NAME)
	@echo "Library and object files removed."

re: fclean all

.PHONY: all clean fclean re bonus
