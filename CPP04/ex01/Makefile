NAME = 	Animal
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = main.cpp Animal.cpp Cat.cpp  Dog.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp
OBJ := $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ) : Animal.hpp Cat.hpp Dog.hpp Brain.hpp WrongAnimal.hpp WrongCat.hpp

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
