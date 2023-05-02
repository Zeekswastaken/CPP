SRCS = Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp main.cpp
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = Animal
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
$(NAME) : $(OBJS)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)
clean :
		rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all