/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_unsetenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 18:17:43 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/05 19:11:12 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_utilities.h"

static int	push_new_env_without_name(char **new_env, size_t len_env, const char *name)
{
	size_t	i;
	size_t	j;
	size_t	len_name;

	i = 0;
	j = 0;
	len_name = ft_strnlen(name, '=');
	ft_printf("========BEGIN========\n");
	while (i < (len_env - 1) && (environ[j]))
	{
		ft_printf("j = %ld\n", j);
		if (!ft_memcmp(environ[j], name, len_name) && environ[j][len_name] == '=')
		{
			//ft_printf("environ[%ld] = %s\n", j, environ[j]);
			//ft_printf("j=%ld\n", j);
			j++;
		}
		else
		{
		// ft_printf("%s\n", environ[j]);
			new_env[i] = ft_strdup(environ[j]);
			ft_printf("%s\n", new_env[i]);
			if (!new_env[i])
				return (FAILURE);
			++i;
			++j;
		}
	}
	ft_printf("=======END===========\n");
	ft_printf("len_env: %ld\n", len_env);
	ft_printf("len_name: %ld\n", len_name);
	new_env[len_env] = NULL;
	return (SUCCESS);
}

static int	delete_var_env(const char *name)
{
	size_t			len_env;
	char			**new_env;
	enum e_u_err	err;

	len_env = ft_lineslen(environ);
	ft_printf("len_env: %ld\n", len_env);
	new_env = (char **)ft_memalloc(sizeof(char *) * (len_env));
	if (!new_env)
		err = FAILURE;
	err = push_new_env_without_name(new_env, len_env, name);
	if (err != FAILURE)
	environ = new_env;
	return (err);
}

int			minishell_unsetenv(const char *name)
{
	char			**find_env;
	enum e_u_err	err;

	if (name && *name)
	{
		find_env = find_var_env(name);
		if (find_env && *find_env)
			err = delete_var_env(name);
	}
	return (err);
}
