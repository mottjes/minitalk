/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:22:59 by mottjes           #+#    #+#             */
/*   Updated: 2024/01/09 14:34:15 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int signal)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		c += 1 << bit;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handler;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\nWaiting for client to send String ...\n", 1);
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			return (ft_putstr_fd("Error\n", 1), 1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			return (ft_putstr_fd("Error\n", 1), 1);
		pause();
	}
}
