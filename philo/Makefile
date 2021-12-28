NAME = philo

SRCS :=	main.c ft_parse_argv.c philo_life.c philo_utils.c \
		ft_arrlen.c ft_atoi.c ft_is_space.c ft_isdigit.c ft_putstr_fd.c ft_observer.c

GCC = gcc -Wall -Werror -Wextra -g

OBJS = $(SRCS:.c=.o)

%.o:        %.c
		$(GCC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		$(GCC) $(OBJS) -o $(NAME) -lpthread

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re