/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fekandle <fekandle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:59:14 by fekandle          #+#    #+#             */
/*   Updated: 2025/08/03 19:09:02 by fekandle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PrintF-v2/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_global
{
	int		Index;
	char	*buffer;
}			t_global;

t_global	g_global;

void	write_buffer(void)
{
	write(1, g_global.buffer, g_global.Index - 1);
	write(1, "\n", 1);
	free(g_global.buffer);
	g_global.buffer = NULL;
	g_global.Index = 0;
}

void	allocate_buffer(char c)
{
	char	*new_buffer;

	new_buffer = ft_calloc(g_global.Index + 2, sizeof(char));
	if (new_buffer == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (g_global.buffer != NULL)
	{
		memcpy(new_buffer, g_global.buffer, g_global.Index);
		free(g_global.buffer);
	}
	g_global.buffer = new_buffer;
	g_global.buffer[g_global.Index] = c;
	g_global.Index++;
}

void	receive_signal(int signal)
{
	static char	c;
	static int	bits;

	if (signal == SIGUSR1)
	{
		c |= 1 << bits;
	}
	else if (signal == SIGUSR2)
		c &= ~(1 << bits);
	bits++;
	if (bits != 8)
		return ;
	allocate_buffer(c);
	if (g_global.buffer[g_global.Index - 1] == '\0')
		write_buffer();
	c = 0;
	bits = 0;
}
int	main(void)
{
	g_global.buffer = NULL;
	g_global.Index = 0;
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
