NAME	= teste.out

SRC_DIR	= src
OBJ_DIR	= obj

CC		= nasm -f elf64

LINKER	= ld -s -o

RM		= rm -rf

SRC_FILES = hello.s

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(OBJ)
	@$(LINKER) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(SRC) -o $(OBJ)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean fclean re