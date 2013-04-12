##
## Makefile for havetofly in /home/brunie_j/local/my/havetofly
##
## Made by Brunier Jean
## Login   <brunie_j@epitech.net>
##
## Started on  Wed Feb 13 15:57:38 2013 Brunier Jean
## Last update Wed Apr 10 13:54:43 2013 Brunier Jean
##

CXX	= clang++

NAME	= h2f

DOBJ	= obj
DSRC	= src
DINC	= .			\
	  math


SRCS	= math/Angle.cpp		\
	  math/Math.cpp			\
	  math/Distance.cpp		\
	  math/Position.cpp

INCLUDE = $(addprefix -I $(DSRC)/, $(DINC))

OBJS	= $(addprefix $(DOBJ)/, $(SRCS:.cpp=.o))

CXXFLAGS= $(INCLUDE) -Wall -Wextra -Werror -O3

LDFLAGS	= `sdl-config --cflags --libs` -lm

all: $(NAME)

$(NAME):  $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

$(DOBJ)/%.o: $(DSRC)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $^ -c -o $@ $(CXXFLAGS)

clean:
	rm -Rf $(DOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
