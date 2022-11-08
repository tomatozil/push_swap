CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_BONUS = checker

SRCS = mandatory/deque.c \
	   mandatory/deque_utils.c \
	   mandatory/deque_life_death.c \
	   mandatory/operations.c \
	   mandatory/operations_r.c \
	   mandatory/ft_function.c \
	   mandatory/main.c \
	   mandatory/check_n_parse.c \
	   mandatory/prepare.c \
	   mandatory/sort.c \
	   mandatory/move_cost.c \
	   mandatory/move_cost_utils.c \
	   mandatory/push_swap.c \
	   mandatory/lis.c \
	   mandatory/lis_utils.c \
	   mandatory/manage_arr.c
SRCS_BONUS = bonus/check_n_parse_bonus.c \
             bonus/checker_bonus.c \
             bonus/deque_bonus.c \
             bonus/deque_utils_bonus.c \
             bonus/deque_life_death_bonus.c \
             bonus/ft_function_bonus.c \
             bonus/get_next_line_bonus.c \
             bonus/get_next_line_utils_bonus.c \
             bonus/main_bonus.c \
             bonus/manage_arr_bonus.c \
             bonus/operations_bonus.c \
             bonus/operations_r_bonus.c \
             bonus/prepare_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
HDR = ./includes

INCLUDES = -I$(HDR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS):$(OBJS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: fclean all clean re bonus