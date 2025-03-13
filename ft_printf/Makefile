SRCS =  ft_printf.c			\
		ft_print_char.c		\
		ft_print_hex.c		\
		ft_print_int.c		\
		ft_print_unsigned.c	\
		ft_print_str.c		\
		ft_print_ptr.c		\

OBJS 			= $(SRCS:.c=.o)

CC 				= cc
RM 				= rm -rf
CFLAGS 			= -Wall -Wextra -Werror

NAME 			= libftprintf.a

all: 			$(NAME)

$(NAME):		$(OBJS)
				ar -rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean: 		clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re