/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:04:03 by nsyazril          #+#    #+#             */
/*   Updated: 2022/08/28 17:51:40 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nbr);
int	len(int *grid);

int	up_chk(int *grid, int *cond, int col)
{
	int	r;
	int	col_sight;
	int	r_tall;
	int	n;

	n = ft_sqrt(len(grid));
	col_sight = 1;
	r = 0;
	r_tall = 0;
	while (++r < n)
	{
		if (grid[r_tall * n + col] < grid[r * n + col])
		{
			r_tall = r;
			col_sight++;
		}
	}
	if (cond[col] == col_sight)
	{
		return (1);
	}
	else
		return (0);
}

int	down_chk(int *grid, int *cond, int col)
{
	int	r;
	int	col_sight;
	int	r_tall;
	int	n;

	n = ft_sqrt(len(grid));
	col_sight = 1;
	r = n - 1;
	r_tall = n - 1;
	while (--r >= 0)
	{
		if (grid[r_tall * n + col] < grid[r * n + col])
		{
			r_tall = r;
			col_sight++;
		}
	}
	if (cond[col + n] == col_sight)
		return (1);
	else
		return (0);
}

int	right_chk(int *grid, int *cond, int row)
{
	int	c;
	int	row_sight;
	int	c_tall;
	int	n;

	n = ft_sqrt(len(grid));
	row_sight = 1;
	c = n - 1;
	c_tall = n - 1;
	while (--c >= 0)
	{
		if (grid[row * n + c_tall] < grid[row * n + c])
		{
			c_tall = c;
			row_sight++;
		}
	}
	if (cond[row + n * 3] == row_sight)
		return (1);
	else
		return (0);
}

int	left_chk(int *grid, int *cond, int row)
{
	int	c;
	int	row_sight;
	int	c_tall;
	int	n;

	n = ft_sqrt(len(grid));
	row_sight = 1;
	c = 0;
	c_tall = 0;
	while (++c < n)
	{
		if (grid[row * n + c_tall] < grid[row * n + c])
		{
			c_tall = c;
			row_sight++;
		}
	}
	if (cond[row + n * 2] == row_sight)
		return (1);
	else
		return (0);
}
