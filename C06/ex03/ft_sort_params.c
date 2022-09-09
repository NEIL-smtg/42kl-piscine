/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:33:59 by suchua            #+#    #+#             */
/*   Updated: 2022/08/30 12:23:44 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_strswap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	print_params(int argc, char **argv)
{
	int	c;
	int	j;

	j = 0;
	while (++j < argc)
	{
		c = -1;
		while (argv[j][++c])
			write(1, &argv[j][c], 1);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc - 1)
	{
		j = argc;
		while (--j > i)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_strswap(&argv[i], &argv[j]);
		}
	}
	print_params(argc, argv);
	return (0);
}
