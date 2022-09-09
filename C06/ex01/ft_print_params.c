/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:13:30 by suchua            #+#    #+#             */
/*   Updated: 2022/08/29 16:29:44 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	c;
	int	j;

	c = -1;
	j = 0;
	while (++j < argc)
	{
		c = -1;
		while (argv[j][++c])
			write(1, &argv[j][c], 1);
		write(1, "\n", 1);
	}
	return (0);
}
