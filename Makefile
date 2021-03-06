# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 19:59:42 by lperson-          #+#    #+#              #
#    Updated: 2022/01/27 12:36:40 by lperson-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := containers

MKDIR := mkdir -p
RM := rm -rf

PATHS := srcs
PATHB := build
PATHD = ${PATHB}/depends
PATHI := include

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CXXFLAGS += ${addprefix -I , ${PATHI}}
DFLAGS = -MMD -MT $@ -MF ${PATHD}/$*.d
LD := c++
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
test_type_traits.cpp
OBJS = ${addprefix ${PATHB}/, ${SRCS:.cpp=.o}}
DFILES = ${addprefix ${PATHD}/, ${SRCS:.cpp=.d}}

.PHONY := all clean fclean re

all: ${NAME}

${NAME}: ${OBJS}
	${LD} -o $@ $^ ${LDFLAGS}

${PATHB}/%.o: %.cpp | ${PATHB} ${PATHD}
	${CXX} ${DFLAGS} ${CXXFLAGS} -c $< -o $@

${PATHB}:
	${MKDIR} $@

${PATHD}:
	${MKDIR} $@

clean:
	${RM} ${PATHB}

fclean: clean
	${RM} ${NAME}

re: fclean all

-include ${DFILES}
