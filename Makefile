# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 19:59:42 by lperson-          #+#    #+#              #
#    Updated: 2022/04/12 12:56:26 by lperson-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := containers
NAME_STD := containers_std

MKDIR := mkdir -p
RM := rm -rf

PATHS := srcs
PATHB := build
PATHD = ${PATHB}/depends
PATHI := include

CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CXXFLAGS += ${addprefix -I , ${PATHI}}
CXXFLAGS += -g
DFLAGS = -MMD -MT $@ -MF ${PATHD}/$*.d
LD := g++
LDFLAGS :=

SRCS_DIR = ${shell find ${PATHS} -type d}
vpath %.cpp ${foreach dir, ${SRCS_DIR}, ${dir}:}

SRCS := \
main.cpp \
basic_test.cpp \
IBaseTest.cpp \
TestCase.cpp \
TestSuite.cpp \
test_iterator.cpp \
test_type_traits.cpp \
test_vector.cpp \
test_stack.cpp \
test_utility.cpp \
test_binary_search_tree.cpp \
test_map.cpp
OBJS = ${addprefix ${PATHB}/, ${SRCS:.cpp=.o}}
OBJS_STD = ${addprefix ${PATHB}/, ${SRCS:.cpp=_std.o}}
DFILES = ${addprefix ${PATHD}/, ${SRCS:.cpp=.d}}

.PHONY := all clean fclean re

all:${NAME_STD} ${NAME}

${NAME}: ${OBJS}
	${LD} -o $@ $^ ${LDFLAGS}

${NAME_STD}: ${OBJS_STD}
	${LD} -o $@ $^ ${LDFLAGS}

${OBJS_STD}: CXXFLAGS += -DSTD

${PATHB}/%.o: %.cpp | ${PATHB} ${PATHD}
	${CXX} ${DFLAGS} ${CXXFLAGS} -c $< -o $@

${PATHB}/%_std.o: %.cpp | ${PATHB} ${PATHD}
	${CXX} ${DFLAGS} ${CXXFLAGS} -c $< -o $@

${PATHB}:
	${MKDIR} $@

${PATHD}:
	${MKDIR} $@

clean:
	${RM} ${PATHB}

fclean: clean
	${RM} ${NAME} ${NAME_STD}

re: fclean all

-include ${DFILES}
