
SRCS = ./srcs/

INCS = ./includes/

libft = ./libft/

BNS_SRCS =	

OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:%.c=%.o)

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = cc
LIBC = ar rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)																	
	$(LIBC) $(NAME) $(OBJS)

bonus: $(BNS_OBJS) $(OBJS)
	$(LIBC) $(NAME) $(BNS_OBJS) $(OBJS)

clean:
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all