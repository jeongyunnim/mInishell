/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:45:57 by hyecheon          #+#    #+#             */
/*   Updated: 2023/03/22 15:46:11 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit(char **argv)
{
	int	tmp;

	if (argv[1] == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	else if (argv[1] != NULL)
	{
		printf("exit\n");
		tmp = ft_atoi(argv[1]);
		if (check_numeric(argv[1]) != 0 || \
		(argv[1][0] != '-' && tmp == -1) || (argv[1][0] == '-' && tmp == 0))
		{
			print_builtin_error("exit", argv[1]);
			exit (255);
		}
		else if (argv[2] != NULL)
		{
			ft_putendl_fd("minishell: exit: too many arguments", 2);
			g_exit_code = 1;
			return ;
		}
		exit(tmp);
	}
}
