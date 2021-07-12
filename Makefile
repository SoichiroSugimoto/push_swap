NAME	= push_swap

SRCS	= ${shell find ./srcs/*/*.c} srcs/main.c

OBJS	= $(SRCS:.c=.o)

HEADER	= ${shell find ./srcs/*/*.h}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -I $(HEADER)　$(SRCS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	cp libft/libft.a push_swap
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
