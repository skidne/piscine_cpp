NAME = ft_gkrellm
GC = g++ -Wall -Wextra -Werror
SRC = src/*.cpp
INCL = -I./incl/

all:
	$(GC) $(SRC) $(INCL) -lglut -lGL -lGLU -lncurses -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, re
