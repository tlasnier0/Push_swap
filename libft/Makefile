NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_split.c ft_strncmp.c ft_isdigit.c ft_bzero.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
