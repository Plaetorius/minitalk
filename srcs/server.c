/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:47:10 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/05 17:53:24 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int num)
{
	ft_printf("%d", num);
}


int main()
{
	struct sigaction	sa;
	pid_t	pid;

	pid = getpid();
	sa.sa_handler = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}