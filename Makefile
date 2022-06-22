CC = c++
SRC = ./src/main.cpp ./src/main_lib.cpp ./src/__tree.cpp
FALGS = -std=c++98 -Wall -Wextra -Werror
NAME = container
OBJS = $(SRC:.cpp=.o)

all: $(NAME) $(NAME)_lib

$(NAME): $(OBJS)
	$(CC) ./src/main.o ./src/__tree.o -I ./include/ -o $(NAME)
$(NAME)_lib: $(OBJS)
	$(CC) ./src/main_lib.o ./src/__tree.o -I ./include/ -o $(NAME)_lib
.cpp.o:
	$(CC) $(FALGS) -I ./include/ -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME)_lib

re: fclean all
