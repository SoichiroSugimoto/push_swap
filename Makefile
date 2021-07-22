NAME	= push_swap

SRCS	= ${shell find ./srcs/*.c}

OBJS	= $(SRCS:.c=.o)

HEADER	= ${shell find ./include/*.h}

LIBFT	= ./libft/libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -L ./libft -lft

$(LIBFT) :
	make -C libft

clean :
	rm -f $(OBJS)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
