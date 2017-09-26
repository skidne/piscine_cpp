NAME = phonebook
GC = g++ -Wall -Wextra -Werror
SRC = main.cpp \
	  Contact.class.cpp
INCL = Contact.class.hpp

all:
	$(GC) $(SRC) $(INCL) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, re
