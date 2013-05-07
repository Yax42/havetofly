##
## Makefile for havetofly in /home/brunie_j/local/my/havetofly
##
## Made by Brunier Jean
## Login   <brunie_j@epitech.net>
##
## Started on  Wed Feb 13 15:57:38 2013 Brunier Jean
## Last update Tue May 07 00:37:52 2013 Brunier Jean
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
	  menu			\
	  game			\
	  action/passive	\
	  action/active		\
	  action/active/a	\
	  action/active/b	\
	  action/active/x	\
	  action/active/y	\
	  throw			\
	  hit			\
	  action



	  ##math/Circle.cpp
	  ##math/Line.cpp
SRCS	= math/Angle.cpp			\
	  math/Math.cpp				\
	  math/Distance.cpp			\
	  math/Position.cpp			\
	  math/Ratio.cpp			\
	  math/RatioPosition.cpp		\
	  graphics/Graphics.cpp			\
	  graphics/APrintable.cpp		\
	  graphics/Display.cpp			\
	  util/Mutex.cpp			\
	  util/Exception.cpp			\
	  util/MyTime.cpp			\
	  util/Wait.cpp				\
	  util/ALoop.cpp			\
	  util/Color.cpp			\
	  hit/Hitbox.cpp			\
	  hit/Hit.cpp				\
	  human/Bones.cpp			\
	  human/Player.cpp			\
	  human/MovePlayer.cpp			\
	  game/Game.cpp				\
	  game/GameLoader.cpp			\
	  input/Key.cpp				\
	  input/Input.cpp			\
	  input/Controler.cpp			\
	  action/ActionFactory.cpp		\
	  action/AAction.cpp			\
	  action/PassiveAction.cpp		\
						\
	  action/passive/Gravity.cpp		\
	  action/passive/Death.cpp		\
	  action/passive/Inertie.cpp		\
	  action/passive/Tech.cpp		\
	  action/passive/Tempo.cpp		\
	  action/passive/HitWall.cpp		\
	  action/passive/HitCeiling.cpp		\
	  action/passive/Move.cpp		\
						\
	  action/active/Stun.cpp		\
	  action/active/HitLagg.cpp		\
	  action/active/StickCeiling.cpp	\
	  action/active/StickWall.cpp		\
						\
	  action/active/a/WallJump.cpp		\
	  action/active/a/DoubleJump.cpp	\
						\
	  action/active/x/Shield.cpp		\
	  action/active/x/HorDash.cpp		\
	  action/active/x/HorTP.cpp		\
	  action/active/x/DownDash.cpp		\
	  action/active/x/Spin.cpp		\
	  action/active/x/Curve.cpp		\
	  action/active/x/UpPunch.cpp		\
						\
	  action/active/y/ThrowBall.cpp		\
	  action/active/y/AutoGun.cpp		\
	  action/active/y/GunJump.cpp		\
						\
	  action/active/b/ThrowShuriken.cpp	\
	  action/active/b/Television.cpp	\
	  action/active/b/EffectiveTV.cpp	\
						\
	  throw/AThrowable.cpp			\
	  throw/Ball.cpp			\
	  throw/Blast.cpp			\
	  throw/Shuriken.cpp			\
	  menu/SetKeys.cpp			\
	  main.cpp


INCLUDE = $(addprefix -I $(DSRC)/, $(DINC))

OBJS	= $(addprefix $(DOBJ)/, $(SRCS:.cpp=.o))

CXXFLAGS= $(INCLUDE) -Wall -Wextra -Werror -pthread -g -O3

LDXFLAGS= `sdl-config --cflags --libs` -lm -pthread

all: $(NAME)



$(NAME):  $(OBJS)
	$(CXX) $^ -o $@ $(LDXFLAGS)

$(DOBJ)/%.o: $(DSRC)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $^ -c -o $@ $(CXXFLAGS)

clean:
	rm -Rf $(DOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
