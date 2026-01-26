/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:25:12 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:25:14 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

/* ===================== main ===================== */

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	i;

	if (argc <= 1)
		return (0);
	size_a = argc - 1;
	size_b = 0;
	a = (int *)malloc(sizeof(int) * size_a);
	b = (int *)malloc(sizeof(int) * size_a);
	if (!a || !b)
		error_exit();
	i = 0;
	while (i < size_a)
	{
		if (!parse_int(argv[i + 1], &a[i]))
			error_exit();
		i++;
	}
	if (has_duplicates(a, size_a))
		error_exit();
	sort_dispatch(a, &size_a, b, &size_b);
	free(a);
	free(b);
	return (0);
}
