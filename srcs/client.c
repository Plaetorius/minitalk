/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:47:03 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/05 17:41:22 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int num)
{
	(void)num;
	write(1, "J'ai recu le signal ehehe\n", 27);
}

pid_t	get_pid(char *str)
{
	int	i;
	pid_t pid;

	i = 0;
	pid = 0;
	while (str[i])
	{
		pid = pid * 10 + (str[i] - '0');
		i++;
	}
	return (pid);
}

int main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 3)
		return (ft_printf("Problem in arguments\n"), -1);
	server_pid = get_pid(av[1]);
	if (server_pid < 0)
		return (ft_printf("%d is an incorrect PID\n", server_pid), -1);
	ft_printf("SERVER PID=%d", server_pid);
	return (0);
}