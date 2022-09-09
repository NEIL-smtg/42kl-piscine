/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:58:02 by nsyazril          #+#    #+#             */
/*   Updated: 2022/08/28 17:54:43 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	used_in_row(int *grid, int row, int num);
int	used_in_col(int *grid, int col, int num);
int	col_is_filled(int *grid, int col);
int	row_is_filled(int *grid, int row);
int	up_chk(int *grid, int *cond, int col);
int	down_chk(int *grid, int *cond, int col);
int	right_chk(int *grid, int *cond, int row);
int	left_chk(int *grid, int *cond, int row);
int	ft_sqrt(int nbr);
int	len(int *grid);

int	check_constraints(int *grid, int *cond, int pos, int num)
{
	int	row;
	int	col;
	int	n;

	n = ft_sqrt(len(grid));
	row = pos / n;
	col = pos % n;
	grid[row * n + col] = num;
	if (row_is_filled(grid, row))
	{
		if (!(left_chk(grid, cond, row) && right_chk(grid, cond, row)))
		{
			grid[row * n + col] = 0;
			return (0);
		}
	}
	if (col_is_filled(grid, col))
	{
		if (!(up_chk(grid, cond, col) && down_chk(grid, cond, col)))
		{
			grid[row * n + col] = 0;
			return (0);
		}
	}
	return (1);
}

int	is_safe(int *grid, int *cond, int pos, int num )
{	
	int	row;
	int	col;
	int	n;

	n = ft_sqrt(len(grid));
	row = pos / n;
	col = pos % n;
	if (used_in_row(grid, row, num) || used_in_col(grid, col, num))
		return (0);
	if (!check_constraints(grid, cond, pos, num))
		return (0);
	return (1);
}	

int	solve_puzzle(int *grid, int *cond, int pos)
{
	int	num;
	int	row;
	int	col;
	int	n;

	n = ft_sqrt(len(grid));
	row = pos / n;
	col = pos % n;
	if (pos == n * n)
		return (1);
	num = 0;
	while (++num <= n)
	{
		if (is_safe(grid, cond, pos, num))
		{
			grid[row * n + col] = num;
			if (solve_puzzle(grid, cond, pos + 1))
				return (1);
			grid[row * n + col] = 0;
		}
	}
	return (0);
}
