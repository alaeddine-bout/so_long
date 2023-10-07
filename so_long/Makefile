NAME = so_long
BONUS = so_long_bonus
CFLAGS = 

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = so_long.c\
		get_next_line.c\
		get_next_line_utils.c\
		./mapcheck/mapchecker.c\
		./mapcheck/mapvalidpath.c\
		game.c\
		playermovement.c\
		playermovement2.c\
		displaymap.c\
		you_win.c\
	
BONUSRCS= get_next_line.c\
			get_next_line_utils.c\
			so_long_bonus.c\
			game_bonus.c\
			playermovement_bonus.c\
			playermovement2_bonus.c\
			displaymap_bonus.c\
			you_win_bonus.c\
			displaymap+enemy_bonus.c\
			./mapcheck/mapchecker_bonus.c\
			./mapcheck/mapvalidpath_bonus.c\

OBJ = ${SRCS:.c=.o}
JBO = ${BONUSRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
		@gcc  $(MLXFLAGS) ${CFLAGS} ${OBJ} ./libft/libft.a -o ${NAME}

bonus : ${BONUS}

%.o:%.c
	@gcc ${CFLAGS} -c $< -o $@
	@echo "$@ \r\t\t\t is compiled"

${BONUS} : ${JBO}
		@gcc  $(MLXFLAGS) ${CFLAGS} ${JBO} ./libft/libft.a -o ${BONUS}

clean :
	@rm -f ${OBJ}
	@rm -f ${JBO}
	@echo object files deleted !

fclean : clean
	@rm -f ${NAME}
	@rm -f ${BONUS}
	@echo program file deleted !

re : fclean all

.PHONY : fclean clean all re
