/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:06:11 by nsyazril          #+#    #+#             */
/*   Updated: 2022/08/28 17:02:30 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int c)
{
	c = c + 48;
	write(1, &c, 1);
}

void	print_grid(int *grid, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			putnbr(grid[i * n + j]);
			if (j != n - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}
