NAME = Base

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	  Base.cpp

OBJS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all