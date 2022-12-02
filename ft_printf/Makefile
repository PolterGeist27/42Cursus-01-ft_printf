
DIRSRCS = ./srcs/

DIRINCS = ./includes/

DIROBJ		= ./objs/

DIRLIB = ./libft/

SRC =	ft_printf \
		token_utils \
		print_c \
		print_i \
		print_p \
		print_percent \
		print_s \
		print_u \
		print_x \
		printf_utils \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
NAMELBFT = libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc
LIBC = ar rc
RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c -I${DIRINCS} -I${DIRLIB} $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	cd $(DIRLIB) && $(MAKE) && cp $(NAMELBFT) ../$(NAME)
	$(LIBC) $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all