

SRCS = main_utils.cpp

SRCS_STACK = ./srcs/tests_stack/tests_stack_relational_operators.cpp \
			./srcs/tests_stack/tests_stack_member_functions.cpp

SRCS_VECTOR = ./srcs/tests_vector/tests_vector.cpp \
			  ./srcs/tests_vector/tests_vector_iterator.cpp \
			  ./srcs/tests_vector/tests_vector_reverse_iterator.cpp \
			  ./srcs/tests_vector/tests_vector_capacity.cpp \
			  ./srcs/tests_vector/tests_vector_modifiers.cpp \
			  ./srcs/tests_vector/tests_vector_element_access.cpp \
			  ./srcs/tests_vector/tests_vector_allocator.cpp \
			  ./srcs/tests_vector/tests_vector_relational_operators.cpp

SRCS_MAP = ./srcs/tests_map/tests_map.cpp \
		   ./srcs/tests_map/tests_map_element_access.cpp \
		   ./srcs/tests_map/tests_map_capacity.cpp \
		   ./srcs/tests_map/tests_map_modifiers.cpp \
		   ./srcs/tests_map/tests_map_observers.cpp \
		   ./srcs/tests_map/tests_map_operations.cpp \
		   ./srcs/tests_map/tests_map_allocator.cpp \
		   ./srcs/tests_map/tests_map_iterator.cpp \
		   ./srcs/tests_map/tests_map_reverse_iterator.cpp \
		   ./srcs/tests_map/tests_map tests_stack.cpp 


SRCS_FT = ./srcs/main.cpp

SRCS_STL = ./srcs/main_stl.cpp

OBJS_FT = ${SRCS_STACK:${DIR_STACK}%.cpp=${DIR_FT}%.o} ${SRCS_VECTOR:${DIR_STACK}%.cpp=${DIR_FT}%.o}


OBJS_FT = ${DIR_FT}${SRCS_FT:.cpp=.o} ${DIR_FT}${SRCS:.cpp=.o} \
			${SRCS_STACK:$(DIR_STACK)%.cpp=$(DIR_FT)%.o} ${DIR_FT}${SRCS_VECTOR:.cpp=.o} \
			${DIR_FT}${SRCS_MAP:.cpp=.o}

SRCS_STL = ./srcs/main_stl.cpp

OBJS_STL = ${SRCS_STL:.cpp=.o}

#DEP = ${SRCS_FT:.cpp=.d} ${SRCS_STL:.cpp=.d}

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I ./incl/

NAME = ft_containers
NAME2 = stl_containers
RM	= rm -rf


.PHONY:		all
all:		${NAME}# ${NAME2}


$(NAME):	${OBJS_FT}
			${CC} ${OBJS_FT} -o ${NAME}

$(NAME2):	${OBJS_STL}
			${CC} ${OBJS_STL} -o ${NAME2}

#-include ${DEP}
srcs/stl/%.o: srcs/%.cpp
	echo $(OBJS_FT)

srcs/ft/%.o: srcs/%.cpp
	echo truc
	echo $(OBJS_FT)

#${OBJS_FT}: ${DIR_SRCS}${SRCS_FT} ${DIR_SRCS}${SRCS} ${DIR_STACK}${SRCS_STACK} \
			${DIR_VECTOR}${SRCS_VECTOR} ${DIR_MAP}${SRCS_MAP}
		#${CC} -DLIB=ft -o $@ -c $< ${CFLAGS}
		#${CC} -MMD -MP -DLIB=ft -o $@ -c $< ${CFLAGS}

#${OBJS_STL}: %.o:%.cpp Makefile
#		${CC} -MMD -MP -DLIB=std -o $@ -c $< ${CFLAGS}

.PHONY:		clean
clean:
			${RM} ${OBJS_FT} ${OBJS_STL} #${DEP}

.PHONY:		fclean
fclean:		clean
			${RM} ${NAME} ${NAME2}

.PHONY:		re
re:			fclean all
