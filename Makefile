##
## Makefile for havetofly in /home/brunie_j/local/my/havetofly
##
## Made by Brunier Jean
## Login   <brunie_j@epitech.net>
##
## Started on  Wed Feb 13 15:57:38 2013 Brunier Jean
## Last update Sat Apr 20 19:54:20 2013 Brunier Jean
##

CXX	= clang++

NAME	= h2f

DOBJ	= obj
DSRC	= src
DINC	= .			\
	  math			\
	  graphics		\
	  human			\
	  input			\
	  util			\
	  game			\
	  action/passive	\
	  action/active		\
	  hit			\
	  action



	  ##math/Circle.cpp
	  ##math/Line.cpp
SRCS	= math/Angle.cpp		\
	  math/Math.cpp			\
	  math/Distance.cpp		\
	  math/Position.cpp		\
	  math/Ratio.cpp		\
	  graphics/Graphics.cpp		\
	  graphics/Display.cpp		\
	  util/Mutex.cpp		\
	  util/Exception.cpp		\
	  util/MyTime.cpp		\
	  util/Wait.cpp			\
	  util/ALoop.cpp		\
	  hit/Hitbox.cpp		\
	  hit/Hit.cpp			\
	  human/Bones.cpp		\
	  human/Player.cpp		\
	  human/MovePlayer.cpp		\
	  game/Game.cpp			\
	  game/GameLoader.cpp		\
	  input/Key.cpp			\
	  input/Input.cpp		\
	  input/Controler.cpp		\
	  action/ActionFactory.cpp	\
	  action/AAction.cpp		\
	  action/PassiveAction.cpp	\
	  action/passive/Gravity.cpp	\
	  action/passive/Death.cpp	\
	  action/passive/Inertie.cpp	\
	  action/passive/Tech.cpp	\
	  action/passive/HitWall.cpp	\
	  action/active/DoubleJump.cpp	\
	  action/active/Shield.cpp	\
	  action/active/HorDash.cpp	\
	  action/active/StickCeiling.cpp\
	  action/active/DownDash.cpp	\
	  action/active/Spin.cpp	\
	  action/active/StickWall.cpp	\
	  action/active/UpPunch.cpp	\
	  action/active/WallJump.cpp	\
	  action/active/Move.cpp	\
	  action/active/Stun.cpp	\
	  main.cpp


INCLUDE = $(addprefix -I $(DSRC)/, $(DINC))

OBJS	= $(addprefix $(DOBJ)/, $(SRCS:.cpp=.o))

CXXFLAGS= $(INCLUDE) -Wall -Wextra -Werror -pthread -g -O3

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
