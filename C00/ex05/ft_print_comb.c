/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:10:08 by suchua            #+#    #+#             */
/*   Updated: 2022/08/20 19:04:52 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int n1, int n2, int n3)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = n1 + '0';
	c2 = n2 + '0';
	c3 = n3 + '0';
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
	if (!(n1 == 7 && n2 == 8 && n3 == 9))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = 0;
	n2 = 1;
	n3 = 2;
	while (n1 <= 7)
	{
		while (n2 <= 8)
		{
			while (n3 <= 9)
			{
				ft_print(n1, n2, n3);
				n3++;
			}
			n2++;
			n3 = n2 + 1;
		}
		n1++;
		n2 = n1 + 1;
		n3 = n2 + 1;
	}
}
