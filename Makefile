NAME	=  libasm.a

SRC_DIR	= src
OBJ_DIR	= obj

CC		= nasm
FLAGS	= -f elf64

AR	= ar rcs
RM		= rm -rf

SRC_FILES = ft_strlen.s


MAIN_SRC	= main.c
MAIN_EXEC	= test_libasm

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)

all: $(NAME) $(MAIN_EXEC)

$(NAME): $(OBJ)
	@echo $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(SRC) -o $(OBJ)

$(MAIN_EXEC): $(MAIN_SRC) $(NAME)
	@gcc $(MAIN_SRC) -L. -lasm -o $(MAIN_EXEC)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(MAIN_EXEC)

re: fclean all

.PHONY: all, clean fclean re