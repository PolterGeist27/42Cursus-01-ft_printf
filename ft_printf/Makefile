DIRSRC = ./srcs/

DIRINCS = ./include/

DIRLIB = ./libft/

SRC =	ft_printf \
	token_utils \
	print_c \
	print_i \
	printf_utils \
	print_u \
	print_percent \
	print_s \
	print_p \
	print_x \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
NAMELIB = libft.a
CFLAGS = -Wall -Wextra -Werror -I $(DIRINCS)
CC = cc
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(DIRLIB)
	cp $(DIRLIB)/$(NAMELIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	make clean -C $(DIRLIB)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(DIRLIB)
	$(RM) $(NAME)

re: fclean all
