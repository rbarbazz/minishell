/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:24:52 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/18 16:24:41 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <sys/wait.h>
# include <sys/param.h>
# include <signal.h>
# include <dirent.h>

# define INVALID_CMD 127

typedef struct		s_lst
{
	char			*cont;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env
{
	char			*value;
	char			*key;
	struct s_env	*next;
}					t_env;

typedef struct		s_sh
{
	char			**buf;
	char			**buf_cpy;
	t_env			*env;
	t_env			*env_tmp;
	int				env_opt;
	int				ret;
	int				i;
}					t_sh;

void				read_stdin(t_sh *sh);
void				display_prompt(t_sh *sh);
void				command_not_found(t_sh *sh, int i);
char				**ft_tilde(t_sh *sh, char **buf);
char				**parser(char *input);

t_env				*list_env(char **environ);
t_env				*env_add(t_env *env, char *elem);
char				**mkenv_strstr(t_env *env);
char				**lst_to_arr(t_lst *buf);

void				free_env(t_env *env);
int					free_path(char **path, int status, t_sh *sh);
void				free_sh(t_sh *sh);
void				free_lst_buf(t_lst *buf);

void				ft_exit(int i, t_sh *sh);

int					ft_binaries(t_sh *sh);
int					exec_binaries(t_sh *sh, char **env, char **path,\
char **argv);
char				**get_path(t_env *env, char *exe);

int					check_builtins(int i, t_sh *sh);
int					ft_echo(int i, t_sh *sh);

int					ft_cd(int i, t_sh *sh);
void				mk_old_pwd(t_sh *sh);
void				mk_new_pwd(t_sh *sh, int hyphen);
char				*cd_home(t_sh *sh);
char				*cd_oldpwd(t_sh *sh, int *hyphen);

int					ft_env(int i, t_sh *sh);
int					env_print(t_env *env);
t_env				*clone_lst(t_env *e1, t_env *e2);
t_env				*mkenv_env(t_sh *sh, int *i);
int					ft_setenv(int i, t_sh *sh);
void				change_value(t_env *env, char *value);
t_env				*mkenvar(t_env *env, char *key, char *value);
int					ft_unsetenv(int i, t_sh *sh);

#endif
