/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:29:46 by suchua            #+#    #+#             */
/*   Updated: 2022/08/23 18:37:24 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	len(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
	}
	return (i);
}

int	ft_str_is_uppercase(char *str)
{
	if (len(str) == 0)
		return (1);
	while (*str)
	{
		if (*str < 'A' || *str > 'Z')
			return (0);
		str++;
	}
	return (1);
}
