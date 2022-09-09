/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:57:58 by suchua            #+#    #+#             */
/*   Updated: 2022/08/30 11:54:55 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str, int len_base)
{
	int	i;
	int	sign;
	int	total;

	i = 0;
	sign = 1;
	total = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			total = total * len_base + str[i] - '0';
		else
			break ;
		i++;
	}
	total *= sign;
	return (total);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int	valid_base;
	int	nbr;

	valid_base = check_base(base);
	if (!valid_base)
		return (0);
	nbr = ft_atoi(str, len(base));
	return (nbr);
}
