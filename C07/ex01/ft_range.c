/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:02:24 by suchua            #+#    #+#             */
/*   Updated: 2022/08/31 14:45:54 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (max <= min)
		return ((void *)0);
	arr = (int *)malloc((max - min) * sizeof(int));
	i = -1;
	while (min < max)
	{
		arr[++i] = min;
		min++;
	}
	return (arr);
}
