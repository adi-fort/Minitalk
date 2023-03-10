/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:54:16 by adi-fort          #+#    #+#             */
/*   Updated: 2023/03/10 16:28:31 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <signal.h>

void	ft_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		c = c+ 1;
		printf("%c", c);
		c * 2;
	}
	else
	{
		printf("%c", c);
		c * 2;
	}
}

int main()
{
	static char	c;
	struct sigaction	signal; 
	
	pid_t pid;
	c = 0;
	signal.sa_handler = ft_handler;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	pid = getpid();
	printf("%d\n", pid);
	while (1)
		pause();
}
