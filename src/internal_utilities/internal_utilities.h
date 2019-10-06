/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_utilities.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 15:20:33 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/07 00:37:06 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_UTILITIES_H
# define INTERNAL_UTILITIES_H

# include "minishell.h"

/*
**ERRORS
*/
# define S_NO_SUCH "no such file or directory"
# define S_TOO_MANY "too many arguments"

# define PWD_ERR(err) ft_printf("pwd: %s\n", err)

# define CD_ERR(err, var_name) ft_printf("cd: %s: %s\n", err, var_name)

# define P_ARGS_UNUSED(...) (void)(__VA_ARGS__)

enum	e_u_err
{
	FAILURE = -1,
	SUCCESS
};

/*
**ENV
*/
# define ENV_OPT "PiuS"
# define USG	"usage: env [-iv] [-P utilpath] [-S string] [-u name]"
# define USG_1	"[name=value ...] [utility [argument ...]]"
# define ENV_ERR(err, filename) ft_printf("env: %s: %s\n", filename, err)
# define ERR_EXT(err, filename) ENV_ERR; exit(EXIT_FAILURE)
# define F_P 1
# define F_I 2
# define F_U 4
# define F_S 8

typedef unsigned char t_opts;

struct	s_nameval
{
	char	*name;
	char	*value;
};

typedef struct	s_env
{
	t_opts	opt;
	char	*path_exec;
	char	*string;
	char	*cmd;
	char	**cmd_argc;
}				t_env;

int			minishell_pwd(int argc, char **argv, char **env);
int			minishell_setenv(const char *name, const char *value, const int replace);
int			minishell_unsetenv(const char *name);
char		**find_var_env(const char *name);
int			minishell_env(int argc, char **argv, char **env);
void		work_opt(char *const *p_argv, t_env *env);
char		**split_s_key(const char *str);

char *const	*u_flag(char *const argv[]);

#endif