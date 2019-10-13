/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_read_stdio.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:06:22 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/13 23:01:44 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	skip_tabs(const char *str)
{
	size_t	len;

	len = 0;
	while (*str && !(TABS(*str)))
	{
		++len;
		++str;
	}
	return (len);
}

static void		insert_env(char *buf, const char *read_stdio)
{
	char		buf_env[MAX_SIZE_PATH + 1];
	size_t		len_w;
	char		*val_env;

	len_w = 0;
	if (read_stdio)
		while (read_stdio)
		{
			ft_bzero(buf_env, MAX_SIZE_PATH + 1);
			read_stdio = ft_strscat(buf, (char *)read_stdio, '$');
			if (read_stdio)
			{
				len_w = skip_tabs(read_stdio);
				if (len_w)
				{
					ft_strncpy(buf_env, read_stdio, len_w);
					val_env = minishell_getenv(buf_env);
					if (val_env)
						ft_strcat(buf, val_env);
					read_stdio += len_w;
				}
			}
		}
}

char			*minishell_read_stdio(void)
{
	char	*read_stdio;
	int		stat_gnl;
	char	*buf;

	buf = (char[ARG_MAX]){0};
	minishell_signals(handler_parrent);
	if ((stat_gnl = get_next_line(STDIN_FILENO, &read_stdio, FLAG_OFF)) == RET_ERROR)
		err_exit(E_MALLOC, "minishell");
	insert_env(buf, read_stdio);
	ft_strdel(&read_stdio);
	return (ft_strdup(buf));
}
