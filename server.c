/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:54:16 by adi-fort          #+#    #+#             */
/*   Updated: 2023/03/15 15:31:22 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>

void	ft_handler(int signum)
{
	static int	i;
	static int	c;

	if (signum == SIGUSR1)
	{
		c *= 2;
		c += 1;	
		i++;
	}
	else
	{
		i++;
		c *= 2;
	}	
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;
	pid_t				pid;

	signal.sa_handler = &ft_handler;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
		pause();
}
