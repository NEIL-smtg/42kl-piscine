/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:34:23 by suchua            #+#    #+#             */
/*   Updated: 2023/02/16 04:02:17 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(unsigned long addr)
{
	char	*base;

	base = "0123456789abcdef";
	if (addr >= 16)
	{
		print_addr(addr / 16);
		print_addr(addr % 16);
	}
	else
		write(1, &base[addr], 1);
}

void	print_line(char *str)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (!str[i])
			break ;
		if (str[i] < 32 || str[i] > 126)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
	}
}

void	print_spaces(char *str, int i, int j)
{
	int	counter;
	int	len;

	if (str[i + j])
		return ;
	len = 0;
	while (str[i + len])
		len++;
	counter = 16 - len;
	counter = counter * 2 + 1;
	while (counter >= 0)
	{
		write(1, " ", 1);
		--counter;
	}
}

int	handle_format(char *str, int i)
{
	int	j;

	j = 0;
	while (j < 16)
	{
		if (str[i + j] < 16)
			write(1, "0", 1);
		print_addr(str[i + j]);
		if ((j + 1) % 2 == 0)
			write(1, " ", 1);
		++j;
		if (!str[i + j])
			break ;
	}
	return (j);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*str;
	int		i;
	int		len;
	int		j;

	if (size == 0)
		return (addr);
	str = (char *) addr;
	i = 0;
	len = 0;
	while (str[len])
		++len;
	while (i < len)
	{
		print_addr((unsigned long) &str[i]);
		write(1, ": ", 2);
		j = handle_format(str, i);
		print_spaces(str, i, j);
		print_line(&str[i]);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

int	main(void)
{
	char	str[100] = "Bonjour les aminches\v\v\vc\v est fou\ntout\nce qu on peut faire avec\v\v\vprint_memory\n\n\n\nlol\vlol\n \n\0";

	ft_print_memory((void *)str, (unsigned int) 5);
	return (0);
}
