/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-yamo <ael-yamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:26:50 by oufisaou          #+#    #+#             */
/*   Updated: 2022/07/01 23:07:51 by ael-yamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <termios.h>
# include <signal.h>
# include <string.h>
# include <fcntl.h>
# include "../includes/libft/libft.h"

# define YES 1
# define NO 0
# define PATH_MAX 4096

typedef enum type_s
{
	WORD,
	QUOTE,
	DQUOTE,
	SPAACE,
	GREAT,
	DGREAT,
	LESS,
	DLESS,
	PIPE,
	DOLLAR
}	t_type;

typedef struct token_s
{
	char			*data;
	char			*old_data;
	unsigned int	type;
	struct token_s	*next;
	struct token_s	*prev;

}	t_token;

typedef struct s_cmd
{
	char	*cmd_path;
	char	**cmd_args;
	int		infile;
	int		outfile;
	t_token	*tokens_cmd;
	int		exec;
}	t_cmd;

typedef struct s_var
{
	t_list	**tmp;
	t_list	*p1;
	t_list	*p2;
	int		index1;
	int		index2;
	int		swapped;
}	t_var;

typedef struct s_gen
{
	int		exit_status;
	int		exec;
	int		skip_all;
	t_list	*env;
	char	**envp;
	char	*pwd;
}	t_gen;

t_gen	g_gen;

int			check_arg(char *next);
int			check_arg2(char *next);
int			array_len(char **array);
char		*ft_to_lower(char *str);
int			ft_strlen2(char **str);
char		*join_str(const char *s1, const char *s2);
void		print_err_exp(char *next);
void		print_err_uns(char *next);
int			modify_env(char *pwd);
int			ft_cd(char **path);
int			change_env(char *p);
int			ft_add_list(t_list **env_list, char *str);
void		suite(char **str);
void		ft_echo(char **str);
int			set_flag(char *s);
void		ft_env(char **str);
void		suite7(char *str);
int			ft_exit(char **next);
int			is_long(char *next);
int			check_valid(char *next);
void		suite3(char *str);
int			has_equal(char *str);
void		suite4(char *str);
void		print_export(t_list *env);
int			ft_export(char **next);
void		ft_pwd(void);
int			commands(char **line);
void		go_commands(char **line);
int			small(char **p);
int			small2(char **p);
int			small3(char **pwd);
int			s1(char *str);
int			ft_unset(char **next);
int			start_unset(t_list *env, char *next);
long long	ft_atoll(const char *dest);
char		**get_cmds(t_token *tokens);
void		creat_cmd_args(t_cmd **cmds, int pipe);
t_cmd		*cmds_and_redirections(t_token **tokens, int *pipes);
void		get_path_and_execute(t_token **toknes);
char		*get_cmd_path(char *path, char *cmd);
void		get_cmds_paht_err(t_cmd **cmds, int i);
int			is_directory_check(t_cmd **cmds, int i);
int			get_cmds_path(t_cmd **cmds, int pipes);
void		cmd_not_found(char *cmd);
int			is_directory(const char *path);
void		is_a_dir(char *dir);
char		*return_path(char **cmd_path, char **paths);
char		*ft_strjoin_1(char const *s1, char const *s2);
void		free_arr(char **arr);
t_cmd		*creat_cmds(t_token **tokens);
t_list		*env_create(char **envp);
char		**set_env(char **envp);
void		error_free(char *str, t_token *tokens);
int			is_buit_in(char *cmd);
void		exec_built_in(t_cmd *cmds, int i);
void		close_cmd_files(t_cmd *cmds, int count);
void		free_envp(void);
char		*str_to_lower(char *str);
void		free_cmds(t_cmd *cmds, int pipes_num);
void		sig_ign(void);
void		sig_dfl(void);
void		sig_handler(void);
int			run_cmd(t_cmd *cmds, int **pipes, int pipes_num, int *i);
void		wait_all(int pid, int i, int pipes_num);
void		execut(t_cmd *cmds, int **pipes, int pipes_num, int i);
void		execution(t_cmd *cmds, int pipes_num);
void		expander(t_token **tokens);
void		expander_in_quotes_utils(t_token **token, t_list *env);
void		expander_in_quotes(t_token **tokens);
void		bubblesort(t_list **head, int count);
t_list		*swap(t_list *ptr1, t_list *ptr2);
int			len_list(t_list **list);
void		ft_sort(t_gen *gen);
void		change_data(t_token **tokens, char *data);
void		play_with_tokens(t_token **tokens, char *str, t_list *env);
char		*get_var_utils(char **str, int *i, t_list *env);
char		*get_var(char **str, char *final_quote, t_list *env);
char		*find_value(char *str, t_list *env_l);
char		*get_var_str(char *str, int *i);
char		*get_env_var(char *str, t_list *env);
int			get_dollars(char *str);
void		get_sympol_less(t_token **tokens, char **str, int *here);
void		get_token_utils(t_token **tokens, \
char **str, int *here, int *here2);
int			get_quote(char **str, char c);
int			get_word(char **str, int *here, int *here2);
char		*get_char(char **str, char *c, int increment);
void		get_sympol_great(t_token **tokens, char **str);
int			ft_strcmp(char *s1, char *s2);
void		write_to_fd(int fd, char *str);
int			expand_y_n(char **str);
char		*expander_heredoc(char *line);
int			heredoc(char *limiter, int *exit_status);
void		wait_heredoc(int *exit_status, int pid);
void		handler1(int sig);
void		rm_redirecitons(t_cmd **cmds, int pipes);
void		check_file_direcitons(t_cmd **cmds, int pipes);
int			open_file(t_token **tokens, int type);
int			creat_in_files(t_cmd **cmds, t_token *tokens, int i);
int			creat_out_files(t_cmd **cmds, t_token *tokens, int i);
char		*join_mix(t_token *token1, t_token *token2);
void		join_word(t_token **tokens);
char		*join(char *final_quote, char *tmp);
t_token		*new_token(unsigned int type, char *data);
void		add_at_end(t_token **tokens_head, t_token *token);
void		add_token_last(t_token **token_head, \
unsigned int type, char *data);
char		**convert_to_array(t_list **env);
void		assign_pipes(int **pipes, t_cmd **cmds, int pipes_num);
int			count_pipes(t_token *tokens);
void		fail_to_generat_pipes(int **pipes, int i);
void		free_pipes(int **pipes, int pipes_num);
void		close_pipes(int **pipes, int count);
int			**creat_pipes(int pipes_num);
char		*rm_quotes(char *str, char c);
void		rm_quotes_tokens(t_token **tokens);
void		rm_token(t_token **tokens);
void		rm_spaces(t_token **tokens);
int			ctrld(void);
void		handler(int sig);
int			handle_signals(void);
int			terminal_settings(void);
int			handle_spaces2(t_token *c);
int			is_other(t_token *c);
int			syntax_err(t_token *token);
int			is_other2(t_token *c);
void		free_split(char **array);
static int	check_pairs1(char *s);
int			check_quotes(t_token *token);
int			check_inside(t_token *tmp);
int			check_newline(t_token *c);
int			handle_spaces(t_token *c);
void		get_token(t_token **tokens, char **str);
int			count_tokens(t_token *tokens);
void		clear_tokens(t_token **tokens);
t_token		*tokenize(char *line);
char		*join_cmd(char *path, char *cmd);
void		free_all(t_list *tokens);
int			check_nature(char *next);
int			error(char *next);
void		suite8(char *str);
char		*ft_itoa1(long long n);
int			to_num(char c);
void		suite9(char *str);
#endif