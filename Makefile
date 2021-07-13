NAME	= push_swap

SRCS	= ./srcs/main.c ${shell find ./srcs/*.c}

OBJS	= $(SRCS:.c=.o)

HEADER	= ${shell find ./include/*.h}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror


#サフィックスルールに基づいた記述
#.oファイルが必要になれば.cファイルから作成する
# .c.o :
# 	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

test : $(SRCS)
	@echo "Hello!"
	@echo $^

all :
	gcc -g srcs/*/*.c srcs/*/*.h srcs/main.c libft/*.c libft/*.h

#コンパイル後に.cファイルの一部を変更した場合、再度コンパイルしようとすれば全ての.cファイルをコンパイルする必要がある
#.oファイルを使えば二度手間を省ける。
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
