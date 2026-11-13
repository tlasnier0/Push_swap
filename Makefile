NAME = push_swap
SRCS = main.c ft_push_swap.c ft_flag_parsing.c ft_flag_parsing_utils.c ft_print_error.c
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
