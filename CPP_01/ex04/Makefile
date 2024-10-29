NAME = Sed

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = file/main.cpp \
	   file/file.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all