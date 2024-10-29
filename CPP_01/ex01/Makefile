NAME = ZombieHorde

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   Zombie.cpp \
	   zombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all