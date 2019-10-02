/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_command_execution.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:44:51 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/02 13:39:27 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void execute_internal_cmd(char *const argv[], char *const enval[], int argc, const char *cmd)
{
	P_UNUSED(argv);
	P_UNUSED(enval);
	P_UNUSED(argc);
	P_UNUSED(cmd);
	int (*internal_cmd[NUM_INTERNAL_CMDS])(int argc, char *argv[], char *env[]);

	internal_cmd[0] = cd;
	internal_cmd[1] = echo;
	internal_cmd[2] = env;
	internal_cmd[3] = pwd;
	// internal_cmd[3] = my_unsetenv;
	// internal_cmd[4] = my_setenv;
	// internal_cmd[5] = pwd;

	internal_cmd[ft_atoi(cmd)]((int)argc, (char **)argv, (char **)enval);
}

void tmp(int sig)
{
	if (sig == SIGSEGV)
	{
		ft_printf("minishell: segmentation fault\n");
	}
	else if (sig == SIGINT)
	{
		exit(EXIT_SUCCESS);
	}
	// exit(EXIT_SUCCESS);
}

static void execute_cmd(char *const argv[], char *const env[], const char *path_cmd)
{
	pid_t pid;
	int status_child;

	signal(SIGSEGV, tmp);
	pid = NEW_PROCESS();
	if (pid == CHILD_PROCESS)
	{
		signal(SIGINT, tmp);
		if (execve(path_cmd, argv, env) == NOT_FOUND)
			CMD_NOT_FOUND(CMD_NAME);
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		wait(&status_child);
	}
}

int minishell_command_execution(t_argv *beg, char *const env[])
{
	enum e_find search;
	char cmd_for_ex[MAX_UNAME + 1];

	while (beg)
	{
		search = minishell_command_search(beg->CMD_NAME, cmd_for_ex);
		if (search == FOUND_EXIT)
			return (FOUND_EXIT);
		else if (search == FOUND_INTERNAL_CMD)
			execute_internal_cmd(beg->argv, env, beg->argc, cmd_for_ex);
		else if (search == FOUND_SHELL_DIR || search == FOUND_PATH_ENV)
			execute_cmd(beg->argv, env, cmd_for_ex);
		else
			CMD_NOT_FOUND(beg->CMD_NAME);
		beg = beg->next;
	}
	return (search);
}
