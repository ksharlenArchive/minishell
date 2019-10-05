/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 22:59:27 by rloraine          #+#    #+#             */
/*   Updated: 2019/10/05 14:33:12 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pwd(int argc, char *argv[], char *env[])
{
	char *pwd;

	P_UNUSED(argc);
	P_UNUSED(argv);
	P_UNUSED(env);
	pwd = (char[MAX_SIZE_PATH + 1]){0};
	if (getcwd(pwd, MAX_SIZE_PATH))
	{
		ft_printf("%s\n", pwd);
		return (0);
	}
	return (-1);
}
