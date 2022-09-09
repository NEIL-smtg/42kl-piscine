/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:06:41 by suchua            #+#    #+#             */
/*   Updated: 2022/09/01 15:18:41 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb == 2147483647)
		return (nb);
	if (nb <= 1)
		return (2);
	while (i * i <= nb)
	{
		if (nb % i == 0)
		{
			nb = ft_find_next_prime(nb + 1);
			break ;
		}
		i++;
	}
	return (nb);
}
