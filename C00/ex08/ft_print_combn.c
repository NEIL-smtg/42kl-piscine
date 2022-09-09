/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:59:44 by suchua            #+#    #+#             */
/*   Updated: 2022/08/20 18:47:17 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(char *arr, char *check)
{
	int	i;

	i = -1;
	while (arr[++i] != '\0')
	{
		if (arr[i] != check[i])
			return (0);
	}
	return (1);
}

void	ft_print(char *arr, char *check)
{
	int	i;

	i = -1;
	while (arr[++i] != '\0')
	{
		write(1, &arr[i], 1);
	}
	if (!ft_check (arr, check))
	{
		write(1, ", ", 2);
	}
}

void	ft_append_the_rest(int count, int n, char *arr)
{
	arr[count]++;
	while (++count < n)
	{
		arr[count] = arr[count - 1] + 1;
	}
}

void	ft_algo(char *arr, int n, char *check)
{
	int		count;
	int		last;

	last = n - 1;
	while (!ft_check(arr, check))
	{
		ft_print(arr, check);
		if (arr[last] != '9')
		{
			arr[last]++;
		}
		else
		{
			count = last - 1;
			while (arr[count] == check[count] && count >= 0)
				count--;
			ft_append_the_rest(count, n, arr);
		}
	}
	ft_print(arr, check);
}

void	ft_print_combn(int n)
{
	char	arr[10];
	char	check[10];
	int		i;
	int		j;

	i = -1;
	while (++i < 9)
	{
		arr[i] = i + '0';
		if (i >= n)
			arr[i] = '\0';
	}
	j = 9;
	while (--i >= 0)
	{
		if (i < n)
		{
			check[i] = j + '0';
			j--;
		}
		else
			check[i] = '\0';
	}
	ft_algo(arr, n, check);
}
