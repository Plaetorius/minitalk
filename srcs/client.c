/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:47:03 by tgernez           #+#    #+#             */
/*   Updated: 2023/01/06 18:13:08 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned char *buff_filler(unsigned char c)
{
	int	i;
	unsigned char *buff;

	i = 0;
	buff = malloc(9);
	if (!buff)
		return (NULL);
	buff[8] = '\0';
	// ft_printf("%c\n", c);
	while (i < 8)
	{
		buff[7 - i] = c & 1;
		// ft_printf("C & 1 %d /C & 1\n", c & 1);
		c = c >> 1;
		i++;
	}

	// i = 0;
	// while (i < 8)
	// {
	// 	ft_printf("%d", buff[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	return (buff);
}

static void send_buff(unsigned char *buff, pid_t pid)
{
	int	i;
	
	i = 0;
	while (i < 8)
	{
		if (buff[i] == 0)
			kill(pid, SIGUSR1);
		else if (buff[i] == 1)
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

static int	transmitter(char *message, pid_t pid)
{
	int	len;
	int	i;
	int j;
	unsigned char *buff;

	i = 0;
	j = 0;
	len = 0;
	while (message[len])
		len++;
	ft_printf("LEN %d /LEN\n", len);
	while (i < len)
	{
		buff = buff_filler(message[i]);
		// ft_printf("BUFF %c /BUFF\n", *buff);
		if (!buff)
			return (ft_printf("Buff Alloc Crashed\n"), -1);
		send_buff(buff, pid);
		free(buff);
		i++;
	}
	return (1);
}

pid_t	get_pid(char *str)
{
	int	i;
	pid_t pid;

	i = 0;
	pid = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
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
	if (server_pid <= 0)
		return (ft_printf("%d is an incorrect PID\n", server_pid), -1);
	ft_printf("SERVER PID=%d\n", server_pid);
	transmitter(av[2], server_pid);
	return (0);
}