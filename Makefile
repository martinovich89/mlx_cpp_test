NAME		=	test

LIB			=	-L./libs/mlx -lm -lX11 -lbsd -lXext -lmlx
INC			=	-I./includes -I./libs/mlx

PARSING		=	parsing/parsing.c

RNDR		=	rndr/image.c \
				rndr/image_utils.c

MOVES		=	moves/moves.c

SETTERS		=	setters/setters.c

UTILS		=	utils/clear.c \
				utils/game_utils.c

CHECKERS	=	checkers/checks.c \
				checkers/checks_utils.c

GNL			=	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				get_next_line/get_next_line_utils2.c

ERRORS		=	errors/ft_error.c 

INPUTS		=	inputs/inputs.c 

INITS		=	inits/inits.c

SRC_PATH	=	./srcs/

#SRC			=	$(GNL) \
				$(ERRORS) \
				$(INPUTS) \
				$(INITS) \
				$(MOVES) \
				$(PARSING) \
				$(RNDR) \
				$(SETTERS) \
				$(CHECKERS) \
				$(UTILS) \
				main.c

SRC			=	main.cpp

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

FLAGSD		=	-Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g3

FLAGS		=	-Wall -Wextra -Werror

OBJS		=	$(SRCS:.cpp=.o)

CC			=	g++

RM			=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
		make -C libs/mlx
		cp ./libs/mlx/libmlx.a libs
		$(CC) $(FLAGSD) $(INC) -o $(NAME) $(OBJS) $(LIB)
		echo "$(NAME) created"

%.o: %.cpp
	$(CC) $(FLAGSD) $(INC) -o $@ -c $<

clean:
		make $@ -C libs/mlx
		$(RM) $(OBJS)
		echo "$(OBJS) deleted"

fclean: clean
		$(RM) ./libs/libft.a ./libs/libmlx.a
		$(RM) $(NAME)
		echo "$(NAME) deleted"

re:		fclean all

debug:
	@echo 'INC:$(INC)'
	@echo 'FLAGS:$(FLAGS)'

.PHONY: all clean fclean re
