SRCS = main.cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = easyfind
#OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME) : $(SRCS)
		$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
clean :
		rm -f $(NAME)
fclean : clean
re : fclean all