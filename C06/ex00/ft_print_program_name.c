/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:08:58 by suchua            #+#    #+#             */
/*   Updated: 2022/08/30 18:58:16 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	c;

	c = -1;
	while (argv[0][++c] != '\0' && argc)
		write(1, &argv[0][c], 1);
	write(1, "\n", 1);
	return (0);
}
