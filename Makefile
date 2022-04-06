DIR_SRCS = ./srcs/
DIR_FT = ./srcs/ft/
DIR_STL = ./srcs/stl/

SRCS = ./srcs/main.cpp \
	   ./srcs/main_utils.cpp \
	   ./srcs/tests_stack_relational_operators.cpp \
	   ./srcs/tests_stack_member_functions.cpp \
	   ./srcs/tests_stack.cpp \
	   ./srcs/tests_vector.cpp \
	   ./srcs/tests_vector_init.cpp \
	   ./srcs/tests_vector_iterator.cpp \
	   ./srcs/tests_vector_reverse_iterator.cpp \
	   ./srcs/tests_vector_capacity.cpp \
	   ./srcs/tests_vector_modifiers.cpp \
	   ./srcs/tests_vector_element_access.cpp \
	   ./srcs/tests_vector_allocator.cpp \
	   ./srcs/tests_vector_relational_operators.cpp \
	   ./srcs/tests_map.cpp \
	   ./srcs/tests_map_init.cpp \
	   ./srcs/tests_map_element_access.cpp \
	   ./srcs/tests_map_capacity.cpp \
	   ./srcs/tests_map_modifiers.cpp \
	   ./srcs/tests_map_observers.cpp \
	   ./srcs/tests_map_operations.cpp \
	   ./srcs/tests_map_allocator.cpp \
	   ./srcs/tests_map_iterator.cpp \
	   ./srcs/tests_map_reverse_iterator.cpp

OBJS_FT = ${SRCS:${DIR_SRCS}%.cpp=${DIR_FT}%.o}
OBJS_STL = ${SRCS:${DIR_SRCS}%.cpp=${DIR_STL}%.o}

DEP_FT = ${OBJS_FT:.o=.d}
DEP_STL = ${OBJS_STL:.o=.d}

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I ./incl/

NAME = ft_containers
NAME2 = stl_containers
RM	= rm -rf

.PHONY:		all
all:		${NAME} ${NAME2}

$(NAME):	${OBJS_FT}
			${CC} ${OBJS_FT} -o ${NAME}

$(NAME2):	${OBJS_STL}
			${CC} ${OBJS_STL} -o ${NAME2}

-include ${DEP_FT}
-include ${DEP_STL}


./srcs/ft/%.o: ./srcs/%.cpp Makefile
		${CC} ${CFLAGS} -MMD -MP -DLIB=ft -o $@ -c $< 

./srcs/stl/%.o: ./srcs/%.cpp Makefile
		${CC} ${CFLAGS} -MMD -MP -DLIB=std -o $@ -c $< 

.PHONY:		clean
clean:
			${RM} ${OBJS_FT} ${OBJS_STL} ${DEP_FT} ${DEP_STL}

.PHONY:		fclean
fclean:		clean
			${RM} ${NAME} ${NAME2}

.PHONY:		re
re:			fclean all
