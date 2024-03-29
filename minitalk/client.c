/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:57:51 by adi-fort          #+#    #+#             */
/*   Updated: 2023/03/10 16:28:29 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>

int main(int ac, char *av[])
{
	pid_t	pid;
	int		i;
	int		bit;
	
	i = 0;
	pid = atoi(av[1]);
	while (av[2][i])
	{
		bit = 0;
		while (bit != 8)
		{
			if ((av[2][i] % 2) == 1)
			{
				kill(pid, SIGUSR1);
				usleep(1000);
				av[2][i] = (av[2][i] / 2);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(1000);
				av[2][i] = (av[2][i] / 2);
			}
			bit++;
		}
		i++;
	}
}
