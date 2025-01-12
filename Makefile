NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRCS = 	core/ft_printf.c \
		str/ft_putchar.c \
		nbr/ft_puthex.c \
		nbr/ft_putnbr_unsigned.c \
		nbr/ft_putnbr.c \
		ptr/ft_putptr.c \
		str/ft_putstr.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
