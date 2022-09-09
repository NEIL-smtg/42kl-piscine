/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 12:49:14 by suchua            #+#    #+#             */
/*   Updated: 2022/08/22 10:41:41 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	rush(int x, int y);

int	main(int argc, char *argv[])
{
	int	n1;
	int	n2;
	int	i;

	i = -1;
	n1 = 0;
	n2 = 0;
	printf("%d\n",argv[0]);
	// if (argc == 3)
	// {
	// 	while (argv[1][++i])
	// 	{
	// 		n1 = n1 * 10 + argv[1][i] - '0';
	// 	}
	// 	i = -1;
	// 	while (argv[2][++i])
	// 	{
	// 		n2 = n2 * 10 + argv[2][i] - '0';
	// 	}
	// 	rush(n1, n2);
	// }
	// else
	// {
	// 	write(1, "\nwrong arguments.\n", 18);
	// }
	return (0);
}
