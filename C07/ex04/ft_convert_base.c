/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:42:12 by suchua            #+#    #+#             */
/*   Updated: 2022/09/04 13:42:12 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	final_convert(int nb, char *base_to, char *tab);
int		between_int(long total);
int		get_result_size(int nb, char *base_to);
void	revert(char *tab);
void	put_zero_neg(char *tab, int ifneg, int size);

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
	int	i;

	if (len(base) == 0)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || *base == ' ')
			return (0);
		i = 0;
		while (base[++i])
		{
			if (*base == base[i])
				return (0);
		}
		base++;
	}
	return (1);
}

int	check_str(char c, char *base_from)
{
	int	i;

	i = -1;
	while (base_from[++i])
	{
		if (c == base_from[i])
			return (i);
	}
	return (-42);
}

int	ft_atoi_base(char *nbr, int size, char *base_from)
{
	int			i;
	int			sign;
	long		total;

	total = 0;
	sign = 1;
	i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || (nbr[i] == ' '))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i])
	{
		if (check_str(nbr[i], base_from) == -42)
			break ;
		total = total * size + check_str(nbr[i], base_from);
		i++;
	}
	return (between_int(total * sign));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*tab;
	int		ifneg;
	int		size;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, len(base_from), base_from);
	if (nb == 0)
		return (NULL);
	ifneg = 0;
	if (nb < 0)
	{
		ifneg = 1;
		if (nb != -2147483648)
			nb = -nb;
	}
	size = get_result_size(nb, base_to) + ifneg;
	tab = (char *)malloc(size * sizeof(char));
	if (!tab)
		return (NULL);
	final_convert(nb, base_to, tab);
	put_zero_neg(tab, ifneg, size);
	revert(tab);
	return (tab);
}
