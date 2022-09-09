/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:26:57 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/08/28 18:19:58 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		solve_puzzle(int *grid, int *cond, int pos);
int		check(int ac, char **av, int n);
int		get_numbers(char *str, int *tab);
void	print_grid(int *grid, int n);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putzero(int *grid, int n)
{
	int	i;

	i = -1;
	while (++i < n * n)
		grid[i] = 0;
}

int	main(int ac, char **av)
{
	int	n;
	int	*grid;
	int	*cond;

	n = 1;
	if (ac == 2)
	{
		if (((ft_strlen(av[1]) + 1) / 4) % 2 == 0)
			n = (ft_strlen(av[1]) + 1) / 8;
	}
	grid = (int *)malloc((n * n + 1) * sizeof(int));
	*(grid + n * n) = -42;
	ft_putzero(grid, n);
	if (check(ac, av, n) == 1)
		return (0);
	cond = (int *)malloc(n * 4 * sizeof(int));
	get_numbers(av[1], cond);
	if (solve_puzzle(grid, cond, 0))
		print_grid(grid, n);
	else
		write(1, "Error\n", 6);
	free(grid);
	free(cond);
	return (0);
}
