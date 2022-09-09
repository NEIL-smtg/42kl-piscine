/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:13:04 by suchua            #+#    #+#             */
/*   Updated: 2022/08/23 11:26:00 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		displaynewline();
	}
	return (addr);
}

int	main(void)
{
	unsigned int	n;

	n = 6;
	return (0);
}
