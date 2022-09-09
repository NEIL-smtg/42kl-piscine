/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:50:09 by suchua            #+#    #+#             */
/*   Updated: 2022/09/07 13:50:09 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	len(char *s);

void	put_zero_neg(char *tab, int ifneg, int size)
{
	tab[size - 1] = 0;
	if (ifneg)
		tab[size - 2] = '-';
}

int	between_int(long total)
{
	if (total >= -2147483648 && total <= 2147483647)
		return (total);
	return (0);
}

void	final_convert(int nb, char *base_to, char *tab)
{
	int	size;

	size = len(base_to);
	if (nb == -2147483648)
	{
		final_convert(2147483648 / size, base_to, tab + 1);
		final_convert(2147483648 % size, base_to, tab);
	}
	else if (nb / size >= size)
	{
		final_convert(nb / size, base_to, tab + 1);
		final_convert(nb % size, base_to, tab);
	}
	else
	{
		if (nb / size != 0)
			final_convert(nb / size, base_to, tab + 1);
		*tab = base_to[nb % size];
	}
}

int	get_result_size(int nb, char *base_to)
{
	int	size;
	int	n;

	n = 0;
	size = len(base_to);
	if (nb == -2147483648)
	{
		n = get_result_size(2147483648 / size, base_to) + 1;
		get_result_size(2147483648 % size, base_to);
	}
	else if (nb / size >= size)
	{
		n = get_result_size(nb / size, base_to) + 1;
		get_result_size(nb % size, base_to);
	}
	else
	{
		if (nb / size != 0)
			n = get_result_size(nb / size, base_to) + 1;
		n++;
	}
	return (n);
}

void	revert(char *tab)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = len(tab) - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}	
}
