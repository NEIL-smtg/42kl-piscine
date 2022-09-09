/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:56:30 by suchua            #+#    #+#             */
/*   Updated: 2022/08/20 18:48:00 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int nb)
{
	char	z;
	char	c1;
	char	c2;

	z = '0';
	if (nb < 10)
	{
		write(1, &z, 1);
		c1 = nb + '0';
		write(1, &c1, 1);
	}
	else
	{
		c1 = nb / 10 + '0';
		c2 = nb % 10 + '0';
		write(1, &c1, 1);
		write(1, &c2, 1);
	}
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	n2 = 1;
	while (n1 <= 98)
	{
		while (n2 <= 99)
		{
			ft_print(n1);
			write(1, " ", 1);
			ft_print(n2);
			if (!(n1 == 98 && n2 == 99))
			{
				write(1, ", ", 2);
			}
			n2++;
		}
		n1++;
		n2 = n1 + 1;
	}
}
