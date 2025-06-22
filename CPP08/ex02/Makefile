NAME = MutantStack
CC = c++
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -std=c++98 
SRC = main.cpp
OBJ := $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ) : MutantStack.hpp

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
