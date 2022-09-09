/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:46:19 by suchua            #+#    #+#             */
/*   Updated: 2022/09/07 13:46:19 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_strs_len(char **s, int size, char *sep)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (++i < size)
		n += len(s[i]);
	n += (size - 1) * len(sep) + 1;
	return (n);
}

void	concat(char *tab, char *sep)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	j = 0;
	while (sep[j])
	{
		tab[i + j] = sep[j];
		j++;
	}
	tab[i + j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	tab = (char *)malloc(get_strs_len(strs, size, sep) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = '\0';
	i = -1;
	while (++i < size)
	{
		concat(tab, strs[i]);
		if (i != size - 1)
			concat(tab, sep);
	}
	return (tab);
}
