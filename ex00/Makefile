NAME = ex00

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -f

SRC = Bureaucrat.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Bureaucrat.hpp

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re