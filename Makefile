##
## Makefile for havetofly in /home/brunie_j/local/my/havetofly
##
## Made by Brunier Jean
## Login   <brunie_j@epitech.net>
##
## Started on  Wed Feb 13 15:57:38 2013 Brunier Jean
## Last update Sun Apr 14 11:39:23 2013 Brunier Jean
##

CXX	= clang++

NAME	= h2f

DOBJ	= obj
DSRC	= src
DINC	= .			\
	  math			\
	  graphics		\
	  human			\
	  action/passive	\
	  action/active		\
	  action


SRCS	= math/Angle.cpp		\
	  math/Math.cpp			\
	  math/Distance.cpp		\
	  math/Position.cpp		\
	  graphics/Graphics.cpp		\
	  Exception.cpp			\
	  MyTime.cpp			\
	  Hit.cpp			\
	  Hitbox.cpp			\
	  human/Bones.cpp		\
	  Game.cpp			\
	  human/Player.cpp		\
	  Wait.cpp			\
	  Key.cpp			\
	  Input.cpp			\
	  main.cpp


INCLUDE = $(addprefix -I $(DSRC)/, $(DINC))

OBJS	= $(addprefix $(DOBJ)/, $(SRCS:.cpp=.o))

CXXFLAGS= $(INCLUDE) -Wall -Wextra -Werror -O3 -pthread

LDXFLAGS= `sdl-config --cflags --libs` -lm -pthread

all: $(NAME)

$(NAME):  $(OBJS)
	$(CXX) $(LDXFLAGS) $^ -o $@

$(DOBJ)/%.o: $(DSRC)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $^ -c -o $@ $(CXXFLAGS)

clean:
	rm -Rf $(DOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
