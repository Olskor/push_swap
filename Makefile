NAME		= push_swap
INCLUDE		= includes
FT_PRINTF	= ft_printf
LIB			= libs/
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g -I
RM			= rm -f
AR			= ar rcs

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	main instruction1 tab_handler instruction2 quick_sort quick_sort2 quick_sort3 optimizer
LIBS_FILES	=	libftprintf

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
LIBS 		= 	$(addprefix $(LIB), $(addsuffix .a, $(LIBS_FILES)))


OBJF		=	.cache_exists

all:		whomadeit $(NAME)

$(NAME):	$(OBJ)
			@make -C $(FT_PRINTF) --no-print-directory
			@cp ft_printf/libftprintf.a libs/libftprintf.a
			@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBS) -o $(NAME)
			@echo "$(GREEN)$(NAME) Compiled successfully$(DEF_COLOR)"

nolib:		clean $(OBJ)
			@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBS) -o $(NAME)
			@echo "$(GREEN)$(NAME) Compiled successfully$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(LIB)
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(FT_PRINTF) --no-print-directory
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)_client
			@$(RM) -f $(NAME)_server
			@$(RM) -f $(FT_PRINTF)/libftprintf.a
			@$(RM) -f $(LIB)/libftprintf.a
			@echo "$(CYAN)$(NAME) executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(FT_PRINTF) | grep -v Norme -B1 || true

whomadeit:
			@echo "$(RED)this programm was made by jauffret if the evaluated person is not jauffret, he's a cheater$(DEF_COLOR)"

bonus:		all

.PHONY:		all clean fclean re norm
