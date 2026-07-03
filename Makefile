ROOT_DIR	=	./

BIN_DIR		=	$(ROOT_DIR)bin/
SRC_DIR		=	$(ROOT_DIR)src/
TEST_DIR	=	$(ROOT_DIR)test/
TEST_BIN_DIR	=	$(TEST_DIR)bin/
INC_DIR		=	$(ROOT_DIR)inc/

RM		=	rm
AR		=	ar
AS		=	nasm
CC		=	cc
CXX		=	c++
LD		=	ld


RMFLAGS		:=	-rf
ARFLAGS		:=	rcs
ASFLAGS		:=	-felf64
CCFLAGS		:=	-Wall -Wextra -Werror -MMD
CXXFLAGS	:=	-Wall -Wextra -Werror -MMD
LDFLAGS		:=	

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
				ft_strcmp			\
				ft_write			\
				ft_read				\
				ft_strdup			\

OBJ		:=	$(addprefix $(BIN_DIR), $(addsuffix .o, $(FUNC)))

TEST_SRC	:=	$(shell find test -name "*.c")

TEST	 	:=	$(patsubst %.c,$(TEST_BIN_DIR)%.run,$(notdir $(TEST_SRC)))

TEST_DEP	:=	$(patsubst %.c,$(BIN_DIR)%.d,$(notdir $(TEST_SRC)))

DEP		:=	$(OBJ:.o=.d)

VPATH	= $(ROOT_DIR)
VPATH	+= $(SRC_DIR)
VPATH	+= $(addprefix $(TEST_DIR), $(FUNC))

all	:	$(BIN_DIR) $(TEST_BIN_DIR) $(NAME)

$(BIN_DIR)	:
	mkdir $(BIN_DIR)

$(TEST_BIN_DIR)	:
	mkdir $(TEST_BIN_DIR)

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
	@./run_tests.sh



build_test: $(TEST)

$(TEST_BIN_DIR)%.run: $(BIN_DIR)%.o $(NAME) Makefile
	$(CC) $(CCFLAGS) $< $(NAME) -o $@



clean :
	$(RM) $(BIN_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

-include $(DEP)
-include $(TEST_DEP)

.PHONY:	all clean test fclean re
