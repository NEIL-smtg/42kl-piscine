/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isfilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:56:31 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/08/28 17:57:52 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nbr);
int	len(int *grid);
int	sum_of_row_col(int n);

int	col_is_filled(int *grid, int col)
{
	int	r;
	int	col_value;
	int	n;

	n = ft_sqrt(len(grid));
	r = -1;
	col_value = 0;
	while (++r < n)
		col_value += grid[r * n + col];
	if (col_value == sum_of_row_col(n))
		return (1);
	else
		return (0);
}

int	row_is_filled(int *grid, int row)
{
	int	c;
	int	row_value;
	int	n;

	n = ft_sqrt(len(grid));
	c = -1;
	row_value = 0;
	while (++c < n)
		row_value += grid[row * n + c];
	if (row_value == sum_of_row_col(n))
		return (1);
	else
		return (0);
}
