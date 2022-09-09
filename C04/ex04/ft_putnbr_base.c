/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:52:35 by suchua            #+#    #+#             */
/*   Updated: 2022/08/25 10:52:35 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	j;
	int	i;

	i = 0;
	if (len(base) == 0)
		return (0);
	j = len(base) - 1;
	while (base[i])
	{	
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = len(base) - 1;
		while (j > i)
		{
			if (base[i] == base[j])
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

void	print_base(int nbr, char *base, int size)
{
	if (nbr == -2147483648)
	{
		print_base(2147483648 / size, base, len(base));
		print_base(2147483648 % size, base, size);
	}
	if (nbr / size >= size)
	{
		print_base(nbr / size, base, size);
		print_base(nbr % size, base, size);
	}
	else
	{
		if (nbr / size != 0)
			print_base(nbr / size, base, size);
		write(1, &base[nbr % size], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	valid_base;

	valid_base = check_base(base);
	if (!valid_base)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	print_base(nbr, base, len(base));
}
