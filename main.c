/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:25:12 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:25:14 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

void	run_push_swap(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;

	size_a = count_numbers(argc, argv);
	if (size_a <= 0)
		error_exit();
	a = (int *)malloc(sizeof(int) * size_a);
	b = (int *)malloc(sizeof(int) * size_a);
	if (!a || !b)
		error_exit();
	load_args(argc, argv, a, size_a);
	if (has_duplicates(a, size_a))
		error_exit();
	size_b = 0;
	sort_dispatch(a, &size_a, b, &size_b);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	run_push_swap(argc, argv);
	return (0);
}
