
NAME = Reference
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
OBJ := $(SRC:%.cpp=%.o)

all : $(NAME) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ) : HumanA.hpp HumanB.hpp Weapon.hpp

$(NAME) :

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
