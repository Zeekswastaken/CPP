SRCS = main.cpp Span.cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = Span
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME) : $(OBJS)
		$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $?
clean :
		rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all