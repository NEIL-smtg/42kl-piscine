/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:59:18 by suchua            #+#    #+#             */
/*   Updated: 2022/08/22 21:44:22 by suchua           ###   ########.fr       */
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

int	ft_checkchar(char c)
{
	if (c != '\0')
	{
		if ((c < 65 || c > 122) || (c >= 91 && c <= 96))
			return (0);
	}
	return (1);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (len(str) == 0)
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (!ft_checkchar(str[i]))
		{
			break ;
		}
		i++;
	}
	return (ft_checkchar(str[i]));
}
