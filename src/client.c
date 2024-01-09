/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:23:03 by mottjes           #+#    #+#             */
/*   Updated: 2024/01/09 14:34:07 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_bit(int server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Please enter correct input!\n", 1);
		ft_putstr_fd("-> ./client <pid_of_server> <String>\n", 1);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_bit(server_pid, argv[2][i]);
		i++;
	}
	send_bit(server_pid, argv[2][i]);
}
