/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:09:56 by jeseo             #+#    #+#             */
/*   Updated: 2023/02/28 20:40:18 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *env[])
{
	char	*input;
	t_info	info;

	//env에 추가될 수 있으니까 연결리스트로 맵 만들기.
	//대충 노드 안에 네임이랑 밸류.
	info.envs = save_env(env);
	while (1)
	{
		input = readline("Minishell$ ");
		if (input == NULL)
		{
			continue ;// 이자리는 엑싯임
		}
		add_history(input);
		parse(input, &info);
		free(input);
	}
	return (0);
}
