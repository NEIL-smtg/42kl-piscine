/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:49:33 by suchua            #+#    #+#             */
/*   Updated: 2022/08/23 18:48:45 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	int				i;

	src_len = 0;
	i = -1;
	while (src[src_len])
		src_len++;
	while (src[++i] && i < size - 1)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (src_len);
}
