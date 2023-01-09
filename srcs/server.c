/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:47:10 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/09 17:11:49 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char	*add_char(unsigned char *message, unsigned char c)
{
	unsigned char *tmp;
	int	i;
	static int len = 1;

	i = 0;
	tmp = malloc(++len);
	if (!tmp)
		return (ft_printf("Alloc failed in add_char\n"), NULL);
	while (len > 2 && message[i])
	{
		tmp[i] = message[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	if (len > 2)
		free(message);
	return (tmp);
}


static void signal_reception(int sig, siginfo_t *info, void *context)
{
	static unsigned char	buff = 0;
	static unsigned char	factor = 128;
	static unsigned char	*message;
	int						client_pid;

	(void)context;
	client_pid = info->si_pid;
	buff += (sig == SIGUSR2) * factor;
	// ft_printf("%d->%d\t", factor, (sig == SIGUSR2));
	factor /= 2;
	if (factor == 0)
	{
		message = add_char(message, buff);
		if (!message)
		{
			ft_printf("Failing for empty message\n");
			return ;
		}
		// ft_printf("\n");
		if (factor == 0 && buff == 0)
			ft_printf("%s\n", message);
		factor = 128;
		buff = 0;
	}
	if (kill(client_pid, SIGUSR1) == -1)
		ft_printf("Failed Sending Signal Acknoledgement\n");
	// ft_printf("%s", message);
}

int main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t	pid;

	(void)av;
	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_reception;
	if (ac != 1)
		return (ft_printf("Wrong usage.\n"), EXIT_FAILURE);
	if (sigemptyset(&sa.sa_mask) != 0)
		return (ft_printf("Problem with initialisation\n"), EXIT_FAILURE);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Couldn't handle SIGUSR1 properly\n"),EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Couldn't handle SIGUSR2 properly\n"), EXIT_FAILURE);
	ft_printf("SERVER PID= %d\n", pid);
	while (1)
		pause();
	return (0);
}
