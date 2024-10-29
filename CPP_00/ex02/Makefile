NAME	= Account

CPP		= @c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= tests.cpp \
		  Account.cpp

OBJS = tests.o \
		  Account.o

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) was successfully compiled !"

clean :
	@rm -rf $(OBJS)
	@echo "$(OBJS) was successfully deleted !"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(NAME) was successfully deleted !"

re : fclean all