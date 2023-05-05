GCC = gcc -Wall -Wextra -Werror
HEAD = -I ./minitalk.h

NAME = server 
NAMEC = client

NAMEB = serverbonus 
NAMECB = clientbonus

SRCS_C = ./client.c \

SRCS_S = ./server.c \

SRCS_CB = ./client_bonus.c \

SRCS_SB = ./server_bonus.c \

OBJS_C = ${SRCS_C:%.c=objets/%.o}
OBJS_S = ${SRCS_S:%.c=objets/%.o}

OBJS_CB = ${SRCS_CB:%.c=objets/%.o}
OBJS_SB = ${SRCS_SB:%.c=objets/%.o}

all : ${NAME}

${NAME} : ${OBJS_S} ${OBJS_C}
	@make -C libft
	@$(GCC) $(HEAD) -L ./libft -lft ${OBJS_S} -o ${NAME}
	@$(GCC) $(HEAD) -L ./libft -lft ${OBJS_C} -o ${NAMEC}
	@echo "Server and Client are ready! 👌"

objets/%.o : %.c
	@mkdir -p objets
	@$(GCC) $(HEAD) -c $< -o $@

clean :
	@make -s clean -C libft
	@rm -rf objets
	@echo "clean objects 🗑️"

fclean : clean
	@make fclean -s -C libft
	@rm -f ${NAMEC} ${NAME}
	@echo "clean all names and objects 🗑️"

re : fclean all

bonus : ${NAMEB}

${NAMEB} : ${OBJS_SB} ${OBJS_CB}
	@make -C libft
	@$(GCC) $(HEAD) -L ./libft -lft ${OBJS_SB} -o ${NAMEB}
	@$(GCC) $(HEAD) -L ./libft -lft ${OBJS_CB} -o ${NAMECB}
	@echo "Server and Client are ready! 👌"

objets/%.o : %.c
	@mkdir -p objets
	@$(GCC) $(HEAD) -c $< -o $@

cleanbonus :
	@make -s clean -C libft
	@rm -rf objets
	@echo "clean objects BONUS 🗑️"

fcleanbonus : cleanbonus
	@make fclean -s -C libft
	@rm -f ${NAMECB} ${NAMEB}
	@echo "clean all names and objects BONUS 🗑️"

rebonus : fcleanbonus bonus

.PHONY: all clean fclean re
