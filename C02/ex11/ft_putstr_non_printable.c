/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:07:55 by suchua            #+#    #+#             */
/*   Updated: 2022/08/22 23:12:38 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	printhex(int np)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (np > 16)
	{
		printhex(np / 10);
		printhex(np % 10);
	}
	else
	{
		write(1, &hex[np], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			printhex(str[i]);
		}
		else
		{
			write(1, &str[i], 1);
		}
	}
}
