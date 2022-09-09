/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:34:57 by suchua            #+#    #+#             */
/*   Updated: 2022/09/07 13:34:57 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr / 10 >= 10)
	{
		putnbr(nbr / 10);
		putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + 48);
}

void	print(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		print(par[i].str);
		putnbr(par[i].size);
		write(1, "\n", 1);
		print(par[i].copy);
		i++;
	}
}
