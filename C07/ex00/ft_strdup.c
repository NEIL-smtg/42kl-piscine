/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:51:57 by suchua            #+#    #+#             */
/*   Updated: 2022/08/31 14:35:01 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*duplicate;
	int		i;

	i = -1;
	duplicate = (char *)malloc((len(src) + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (src[++i])
		duplicate[i] = src[i];
	duplicate[i] = '\0';
	return (duplicate);
}
