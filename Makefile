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
				ft_strcpy			\
#				ft_strcmp			\
#				ft_write			\
#				ft_read				\
#				ft_strdup			\

OBJ			:=	$(addprefix $(BIN_DIR), $(addsuffix .o, $(FUNC)))

TEST_SRC	:=	$(shell find test -name "*.c")

TEST	 	:=	$(patsubst %.c,%.run,$(TEST_SRC))

TEST_DEP	 :=	$(patsubst %.c,%.d,$(TEST_SRC))

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
	@echo '//'
	@echo '//  'testing all the functions.
	@echo '//'
	@for test in $(TEST) ; do \
		$$test ; \
		if [ $$? -eq 0 ] ; then \
			echo "\033[32mSuccess\033[0m" at $$test ; \
		else  \
			echo "\033[31mFailed\033[0m" at $$test ; \
		fi ; \
	done 
		

build_test: $(TEST)

$(TEST_DIR)%.test.run: $(TEST_DIR)%.test.cpp Makefile
	$(CXX) $(CXXFLAGS) $< $(NAME) -o $@

$(TEST_DIR)%.test.run: $(TEST_DIR)%.test.c Makefile
	$(CC) $(CCFLAGS) $< $(NAME) -o $@

$(TEST_DIR)%.test.run: $(TEST_DIR)%.test.s Makefile
	echo "to be implemented."
#	$(AS) $(ASFLAGS) $< $(NAME)


clean :
	$(RM) $(BIN_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

-include $(DEP)
-include $(TEST_DEP)

.PHONY:	all clean test fclean re
