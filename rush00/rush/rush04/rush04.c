/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:38:10 by suchua            #+#    #+#             */
/*   Updated: 2022/08/21 12:56:09 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);

void	checkpoint(int x, int y, int cx, int cy)
{
	if ((cx == 1 && cy == 1) || (cx == x && cy == y && y > 1 && x > 1))
	{
		ft_putchar ('A');
	}
	else if ((cx == x && cy == 1) || (cx == 1 && cy == y))
	{
		ft_putchar ('C');
	}
	else if ((cx > 1 && cx < x) && (cy == 1 || cy == y))
	{
		ft_putchar ('B');
	}
	else if ((cy > 1 && cy < y) && (cx == 1 || cx == x))
	{
		ft_putchar ('B');
	}
	else
	{
		ft_putchar (' ');
	}
}

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cx = 0;
	cy = 0;
	while (++cy <= y)
	{
		cx = 0;
		while (++cx <= x)
		{
			checkpoint(x, y, cx, cy);
		}
		ft_putchar ('\n');
	}
}
