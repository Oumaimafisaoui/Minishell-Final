CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = minishell
DIRBUILD = objdir
INC  = -I ./includes
HEADERS = includes/minishell.h
LIBFT = includes/libft/libft.a
SRC =  cmd_creation cmd_managment cmd_utils_ cmd_utils creat_cmds enviroment error_free\
execution_built execution_utils execution_utils2 execution export_tool finding_ finding\
get_tokens__ get_tokens_ heredoc_utils heredoc_utils2 heredoc in_out_file_managment\
in_out_utils joining list_manupulation main pipe_asign pipe_management removing signals\
suite_syntax syntax_analyzer token expantion \
builtins/ft_exit builtins/ft_env builtins/ft_echo\
builtins/more_func export_tool suite_syntax builtins/built_tools builtins/built_checks \
builtins/unset builtins/exit_utils builtins/ft_export builtins/ft_pwd builtins/ft_cd builtins/go_build

OBJ = $(addprefix $(DIRBUILD)/, $(SRC:=.o))

all : $(NAME)
$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $^ -o $(NAME) -lreadline  $(LDFLAGS)  $(LIBFT)

$(LIBFT) :
	@make -C includes/libft
	
$(DIRBUILD)/%.o : source/%.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(INC) $(CPPFLAGS) -c $< -o $@
clean :
	@rm -rf $(DIRBUILD)
	@make clean -C includes/libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C includes/libft
	@echo "\033[0;95m Everything is fcleaned in minishell!\033[m"

re : fclean all

.PHONY : re fclean clean all
