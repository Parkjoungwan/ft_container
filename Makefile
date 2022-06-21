CC = c++
SRC = ./src/main2.cpp ./src/__tree.cpp
FALGS = -std=c++98 -Wall -Wextra -Werror
NAME = container
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -I ./include/ -o $(NAME)
.cpp.o:
	$(CC) $(FALGS) -I ./include/ -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
