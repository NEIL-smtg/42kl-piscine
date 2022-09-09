/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simpleconditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:56:53 by nsyazril          #+#    #+#             */
/*   Updated: 2022/08/28 17:56:24 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	col_is_filled(int *grid, int col);
int	row_is_filled(int *grid, int row);

int	ft_sqrt(int nbr)
{
	int	i;

	i = 1;
	while (i * i <= nbr)
		i++;
	return (--i);
}

int	len(int *grid)
{
	int	i;

	i = 0;
	while (grid[i] != -42)
		i++;
	return (i);
}

int	sum_of_row_col(int n)
{
	int	sum;

	sum = 0;
	while (n > 0)
	{
		sum += n;
		n--;
	}
	return (sum);
}

int	used_in_row(int *grid, int row, int num)
{
	int	c;
	int	n;

	n = ft_sqrt(len(grid));
	c = -1;
	while (++c < n)
	{
		if (grid[row * n + c] == num)
			return (1);
	}
	return (0);
}

int	used_in_col(int *grid, int col, int num)
{
	int	r;
	int	n;

	n = ft_sqrt(len(grid));
	r = -1;
	while (++r < n)
	{
		if (grid[r * n + col] == num)
			return (1);
	}
	return (0);
}
