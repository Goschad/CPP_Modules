NAME	= PhoneBook

CPP		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp \
		  Contact.cpp \
	   	  PhoneBook.cpp

OBJS 	= $(SRCS:.cpp=.o)
	   
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