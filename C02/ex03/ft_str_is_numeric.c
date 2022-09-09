/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:53:37 by suchua            #+#    #+#             */
/*   Updated: 2022/08/23 18:35:43 by suchua           ###   ########.fr       */
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

int	checkchar(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_str_is_numeric(char *str)
{
	if (len(str) == 0)
		return (1);
	while (checkchar(*(str++)) && *str)
	{
	}
	return (checkchar(*(--str)));
}
