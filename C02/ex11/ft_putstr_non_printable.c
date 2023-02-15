/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:16:04 by suchua            #+#    #+#             */
/*   Updated: 2023/02/16 04:07:37 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	not_printable(char c)
{
	return (c < 32 || c > 126);
}

void	print_hex(int ch)
{
	char	*base;

	base = "0123456789abcdef";
	if (ch >= 16)
	{
		print_hex(ch / 16);
		print_hex(ch % 16);
	}
	else
		write(1, &base[ch], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (not_printable(str[i]))
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			print_hex(str[i]);
		}
		else
			write(1, &str[i], 1);
	}	
}

int	main(void)
{
	char str[100] = "Coucou\vtu vas bien";
	ft_putstr_non_printable(str);
	return (0);
}