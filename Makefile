ROOT_DIR	=	./

BIN_DIR		=	$(ROOT_DIR)bin/
SRC_DIR		=	$(ROOT_DIR)src/
TEST_DIR	=	$(ROOT_DIR)test/
INC_DIR		=	$(ROOT_DIR)inc/

RM		=	rm
AR		=	ar
AS		=	nasm
CC		=	cc
CXX		=	c++

RMFLAGS		:=	-rf
ARFLAGS		:=	rcs
ASFLAGS		:=	-felf64
CCFLAGS		:=	-Wall -Wextra -Werror -MMD
CXXFLAGS	:=	-Wall -Wextra -Werror -MMD

CINC		:=	-I$(BIN_DIR)
CINC		+=	-I$(INC_DIR)
CXXFLAGS	+=	$(CINC)
CCFLAGS	+=	$(CINC)

CDEBUG		:=	-g
CXXFLAGS	+=	$(CDEBUG)
CCFLAGS		+=	$(CDEBUG)

NAME	=	libasm.a


FUNC		:=	ft_strlen			\
#				ft_strcpy.o			\
#				ft_strcmp.o			\
#				ft_write.o			\
#				ft_read.o			\
#				ft_strdup.o			\

OBJ			:=	$(addprefix $(BIN_DIR), $(addsuffix .o, $(FUNC)))

TEST	 	:=	$(addprefix $(TEST_DIR), $(addsuffix .test.run, $(OBJ)))

DEP		:=	$(OBJ:.o=.d)

VPATH	= $(ROOT_DIR)
VPATH	+= $(SRC_DIR)

all	:	$(BIN_DIR) $(NAME)

$(BIN_DIR)	:
	mkdir $(BIN_DIR)

$(NAME) : $(OBJ) Makefile
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(BIN_DIR)%.o : %.cpp	Makefile 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)%.o : %.c	Makefile 
	$(CC) $(CCFLAGS) -c $< -o $@

$(BIN_DIR)%.o : %.s	Makefile 
	$(AS) $(ASFLAGS) $< -o $@

test: build_test
	echo testing all the functions.

build_test: $(TEST_DIR) $(TEST)

$(TEST_DIR)%.test.run: $(SRC_DIR)%.test.cpp


clean :
	$(RM) $(BIN_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

-include $(DEP)

.PHONY:	all clean test fclean re
