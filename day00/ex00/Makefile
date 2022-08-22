SRCS = megaphone.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = clang++
NAME = megaphone
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)
clean :
		rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all