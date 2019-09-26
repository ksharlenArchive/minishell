/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloraine <rloraine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:10:52 by rloraine          #+#    #+#             */
/*   Updated: 2019/09/26 23:26:51 by rloraine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MYERROR 1

void	my_unsetenv(char *key)
{
	if (unsetenv(key))
		exit(0);
}

void	my_setenv(char *key, char *value, char *old_pwd)
{
	int n;

	n = -1;
	if (ft_strequ(key, "PWD"))
	{
		if (setenv(key, value, 1))
			exit(0);
		if (setenv("OLDPWD", old_pwd, 1))
			exit(0);
	}
	else
	{
		// for env
	}
}
