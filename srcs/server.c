/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:47:10 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/07 18:33:50 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int client_pid = -1;

static void signal_reception(int sig, siginfo_t *info, void *context)
{
	static unsigned char buff = 0;
	static int	factor = 128;

	(void)context;
	client_pid = info->si_pid;
	kill(client_pid, SIGUSR1);
	buff += (sig == SIGUSR2) * factor;
	factor /= 2;
	ft_printf("%d\n", factor);
	// ft_printf("%d", num == SIGUSR2);
	if (factor == 0)
	{
		ft_printf("BUFF %c /BUFF\n", buff);
		factor = 128;
		buff = 0;
	}
}

int main()
{
	struct sigaction	sa;
	pid_t	pid;
	static int count = 0;

	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_reception;
	ft_printf("COUNT %d /COUNT\n", count++);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	ft_printf("SERVER PID= %d\n", pid);
	while (1)
		pause();
	return (0);
}
