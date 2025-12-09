NAME        = iter

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++17

SRCS        = main.cpp
OBJS        = $(SRCS:.cpp=.o)

# --- Rules ---

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp whatever.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
