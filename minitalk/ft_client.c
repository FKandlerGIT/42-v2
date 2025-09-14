/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:56:21 by fkandler          #+#    #+#             */
/*   Updated: 2025/08/03 19:08:54 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PrintF-v2/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void	send_bits(int pid, int bit)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			exit(1);
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			exit(1);
	}
	usleep(100);
}
void	send_char(int pid, char c)
{
	int	bit;
	int	i;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		send_bits(pid, bit);
		i++;
	}
}
void	send_string(int pid, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <string>\n", argv[0]);
		return (1);
	}
	pid = (pid_t)ft_atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
