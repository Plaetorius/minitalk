# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 17:23:52 by tgernez           #+#    #+#              #
#    Updated: 2023/01/05 17:40:45 by tgernez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			= client
SERVER			= server
INCLUDES		= -Iincludes
PRINTFDIR		= ft_printf
PRINTFLIB		= -lft_printf
CC				= clang
FLAGS			= -Wall -Wextra -Werror
CLIENT_SRCS		= srcs/client.c
SERVER_SRCS		= srcs/server.c
CLIENT_OBJS		= ${CLIENT_SRCS:.c=.o}
SERVER_OBJS		= ${SERVER_SRCS:.c=.o}
RM				= rm -rf
RED				= \033[1;31m
NC				= \033[0m
LGREEN			= \033[1;32m
CYAN			= \033[1;36m

%.o: %.c
	@echo "\033[1A                                                          "
	@echo -n "\033[1A"
	@echo "${CYAN}Compiling $< ${NC}"
	@${CC} ${FLAGS} -o $@ -c $^ ${INCLUDES}

all: ${CLIENT} ${SERVER}
	@echo "${LGREEN}Successfully created${NC}${CYAN} ${CLIENT} & ${SERVER} ${NC}${LGREEN}!${NC}"

${CLIENT}: ${CLIENT_OBJS} ${PRINTFDIR}/libft_printf.a
	@${CC} ${CLIENT_OBJS} ${INCLUDES} -L${PRINTFDIR} ${PRINTFLIB} -o $@

${SERVER}: ${SERVER_OBJS} ${PRINTFDIR}/libft_printf.a
	@${CC} ${SERVER_OBJS} ${INCLUDES} -L${PRINTFDIR} ${PRINTFLIB} -o $@

${PRINTFDIR}/libft_printf.a:
	@make -C ${PRINTFDIR}

safe:
	git add .
	git commit -m "SEMIAUTO-SAFEGUARD"
	git push

#----------------------------PIPEX

clean:
	@echo "${CYAN}Cleaned Minitalk${NC}"
	@${RM} ${OBJS}

fclean:		clean
	@echo "${CYAN}FCleaned Minitalk${NC}"
	@${RM} ${CLIENT}
	@${RM} ${SERVER}

re: fclean all

#----------------------------PRINTF

printf_all:
	@make -C ${PRINTFDIR} all

printf_clean:
	@make -C ${PRINTFDIR} clean

printf_fclean:
	@make -C ${PRINTFDIR} fclean


printf_re:
	@make -C ${PRINTFDIR} re

#----------------------------ALL

all_clean: clean printf_clean

all_fclean: fclean printf_fclean

all_re: printf_re fclean all
	@echo "${CYAN}Re-ed everything ${NC}"
