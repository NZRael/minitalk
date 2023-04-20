GCC = gcc -Wall -Wextra -Werror
HEAD = -I ./minitalk.h

NAMEC = client
NAMES = server

SRCS_C = ./client.c ./minitalk_utils1.c ./minitalk_utils2.c \

SRCS_S = ./server.c ./minitalk_utils1.c ./minitalk_utils2.c \

OBJS_C = ${SRCS_C:%.c=objets/%.o}
OBJS_S = ${SRCS_S:%.c=objets/%.o}

all : $(NAMES) $(NAMEC)

$(NAMES) : ${OBJS_S}
	@$(GCC) $(HEAD) ${OBJS_S} -o ${NAMES}

$(NAMEC) : ${OBJS_C}
	@$(GCC) $(HEAD) ${OBJS_C} -o ${NAMEC}

objets/%.o : %.c
	@mkdir -p objets
	@$(GCC) $(HEAD) -c $< -o $@

clean :
	@rm -rf objets

fclean : clean
	@rm -f ${NAMEC} ${NAMES}

re : fclean all

.PHONY: all clean fclean re
