NAME = Reference
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = main.cpp
OBJ := $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
		$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
