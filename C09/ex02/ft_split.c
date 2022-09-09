/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:55:58 by suchua            #+#    #+#             */
/*   Updated: 2022/09/07 22:13:00 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	check_split(char s, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (s == charset[i])
			return (1);
	}
	return (0);
}

int	get_row_num(char *str, char *charset)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (str[i])
	{
		while (check_split(str[i], charset) && str[i])
			i++;
		while (!check_split(str[i], charset) && str[i])
			i++;
		if (check_split(str[i], charset))
			row++;
		if (str[i] == '\0' && !check_split(str[i - 1], charset))
			row++;
	}
	return (row + 1);
}

int	get_row_len(char *str, char *charset, int cur_row)
{
	int	i;
	int	row;
	int	len;

	i = 0;
	row = 0;
	while (row <= cur_row)
	{
		while (check_split(str[i], charset) && str[i])
			i++;
		len = 0;
		while (!check_split(str[i], charset) && str[i])
		{
			len++;
			i++;
		}
		if (check_split(str[i], charset))
			row++;
		if (str[i] == '\0')
			row++;
	}
	return (len + 1);
}

void	ft_strcpy(char *tab, char *str, char *charset, int cur_row)
{
	int	i;
	int	row;
	int	j;

	j = 0;
	i = 0;
	row = 0;
	while (row <= cur_row)
	{
		while (check_split(str[i], charset) && str[i])
			i++;
		while (!check_split(str[i], charset) && str[i])
		{
			if (cur_row == row)
			{
				tab[j] = str[i];
				j++;
			}
			i++;
		}
		if (check_split(str[i], charset))
			row++;
		if (str[i] == '\0')
			row++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(get_row_num(str, charset) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (++i < get_row_num(str, charset))
	{
		tab[i] = (char *)malloc(get_row_len(str, charset, i) * sizeof(char));
		ft_strcpy(tab[i], str, charset, i);
		tab[i][get_row_len(str, charset, i) - 1] = '\0';
		if (tab[i][0] == '\0')
			tab[i] = 0;
	}
	return (tab);
}
