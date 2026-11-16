NAME = push_swap
BENCH_SRCS = ft_bench.c ft_bench_utils.c
PARSE_SRCS = ft_flag_parsing.c ft_flag_parsing_utils.c
OP_SRCS = ft_ops_push.c ft_ops_rev_rotate.c ft_ops_rotate.c ft_ops_swap.c
OTHER_SRCS = ft_push_swap.c ft_disorder.c ft_print_error.c ft_sort_utils.c ft_index_stack.c
ALGO_SRCS = ft_sort_minmax.c ft_sort_butterfly_chunk.c ft_sort_radix.c
SRCS = main.c $(BENCH_SRCS) $(PARSE_SRCS) $(OP_SRCS) $(ALGO_SRCS) $(OTHER_SRCS)
OBJS = $(SRCS:.c=.o)
CFLAGS  = -Wall -Werror -Wextra
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c ft_push_swap.h
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
