NAME = ClapTrap

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	  ClapTrap.cpp

OBJS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all