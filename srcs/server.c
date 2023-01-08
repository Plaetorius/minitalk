/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:47:10 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/08 18:57:16 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	*add_char(unsigned char *message, unsigned char c)
{
	unsigned char *tmp;
	int	i;
	static int len = 2;

	i = 0;
	tmp = malloc(len++);
	if (!tmp)
		return (ft_printf("Alloc failed in add_char\n"), NULL);
	while (message[i])
	{
		tmp[i] = message[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(message);
	return (tmp);
}


static void signal_reception(int sig, siginfo_t *info, void *context)
{
	static unsigned char buff = 0;
	static int	factor = 128;
	static unsigned char *message;
	int	client_pid;

	(void)context;
	client_pid = info->si_pid;
	message = malloc(1);
	if (kill(client_pid, SIGUSR1) == -1 || !message)
	{
		ft_printf("failed in signal recep\n");
		return ;
	}
	message[0] = '\0';
	buff += (sig == SIGUSR2) * factor;
	factor /= 2;
	if (factor == 0)
	{
		message = add_char(message, buff);
		if (!message)
		{
			ft_printf("Failing for empty message\n");
			return ;
		}
		factor = 128;
		buff = 0;
	}
	ft_printf("%s", message);
}

int main()
{
	struct sigaction	sa;
	pid_t	pid;

	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_reception;
	if (sigemptyset(&sa.sa_mask) != 0)
		return (ft_printf("Problem with initialisation\n"), 1);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (EXIT_FAILURE);
	ft_printf("SERVER PID= %d\n", pid);
	while (1)
		pause();
	return (0);
}
