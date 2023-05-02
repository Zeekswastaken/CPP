SRCS = main.cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = Serialization
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME) : $(OBJS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)
clean :
		rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all