NAME		= libftprintf.a
FTSRCS		= .c
DIRSRCS 	= ./
SRCS 		=	$(addsuffix ${FTSRCS},	\
				$(addprefix ${DIRSRCS},	\
				ft_printer_u			\
				ft_printer_upperx		\
				ft_putnbr_ui_hexa_low	\
				ft_putnbr_ul_hexa		\
				ft_len_nb_hexa			\
				ft_printer_x			\
				ft_printer_s			\
				ft_printf				\
				ft_printer_d			\
				ft_putnbr_ui			\
				ft_printer_c			\
				ft_putnbr_int			\
				ft_printer_p			\
				ft_printer_i			\
				ft_putnbr_ui_hexa_up	\
				))
LIBDIR		= libft
LIBNAME		= ft
INCLUDES	= -Iincludes
RM			= rm -rf
OBJS		= ${SRCS:.c=.o}
CC			= clang
FLAGS		= -Wall -Wextra -Werror
RED			= \033[0;31m
NC			= \033[0m
LGREEN		= \033[1;32m
CYAN		= \033[0;36m

.%.o: %.c
	@echo "${CYAN}Compiling $<${NC}"
	@${CC} ${FLAGS} -o $@ -c $^ -L${LIBDIR} -l${LIBNAME} ${INCLUDES}


all: ${NAME}
	@echo "${LGREEN}Successfully created${NC}${CYAN} ${NAME}${NC}${LGREEN}!${NC}"

${LIBDIR}/${LIBDIR}.a:
	@make -C ${LIBDIR}

${NAME}:	${OBJS} ${LIBDIR}/${LIBDIR}.a
	@cp ${LIBDIR}/${LIBDIR}.a ${NAME}
	@ar rcs ${NAME} ${OBJS}

clean:
	@echo "${CYAN}Cleaned Ft_printf${NC}"
	@${RM} ${OBJS}

fclean:		clean
	@echo "${CYAN}FCleaned Ft_printf${NC}"
	@${RM} ${NAME}


lib_re:
	@make -C ${LIBDIR} re

lib_clean:
	@make -C ${LIBDIR} clean

lib_fclean:
	@make -C ${LIBDIR} fclean

lib_all:
	@make -C ${LIBDIR} all

all_clean: clean lib_clean

all_fclean: fclean lib_fclean

re: lib_re fclean all
	@echo "${CYAN}Re-ed Ft_printf${NC}"
	

.PHONY: all clean fclean re lib_re lib_all lib_fclean lib_clean lib_re