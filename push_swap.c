/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:25:19 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:25:21 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

int	max_bits_needed(int n)
{
	int	bits;

	bits = 0;
	while ((n - 1) >> bits)
		bits++;
	return (bits);
}

static void	radix_pass(int **p, int bit)
{
	int	i;
	int	n;

	n = *(p[2]);
	i = 0;
	while (i++ < n)
	{
		if (((p[0][0] >> bit) & 1) == 0)
			pb(p[0], p[1], p[2], p[3]);
		else
			ra(p[0], p[2]);
	}
	while (*(p[3]) > 0)
		pa(p[0], p[1], p[2], p[3]);
}

void	algo_radix(int *a, int *size_a, int *b, int *size_b)
{
	int	*ctx[4];
	int	bit;
	int	max_bits;

	if (*size_a <= 1 || is_sorted(a, *size_a))
		return ;
	compress_to_ranks(a, *size_a);
	ctx[0] = a;
	ctx[1] = b;
	ctx[2] = size_a;
	ctx[3] = size_b;
	max_bits = max_bits_needed(*size_a);
	bit = 0;
	while (bit < max_bits)
		radix_pass(ctx, bit++);
}

int	try_tiny_sort(int *a, int *size_a, int *b, int *size_b)
{
	if (*size_a <= 1)
		return (1);
	if (is_sorted(a, *size_a))
		return (1);
	if (*size_a == 2)
	{
		sort_2(a, size_a);
		return (1);
	}
	if (*size_a == 3)
	{
		sort_3(a, size_a);
		return (1);
	}
	if (*size_a == 5)
	{
		sort_5(a, size_a, b, size_b);
		return (1);
	}
	return (0);
}

void	sort_dispatch(int *a, int *size_a, int *b, int *size_b)
{
	int	n;

	n = *size_a;
	if (n <= 1 || is_sorted(a, n))
		return ;
	if (try_tiny_sort(a, size_a, b, size_b))
		return ;
	if (n <= 20)
		algo_selection_small(a, size_a, b, size_b);
	else
		algo_radix(a, size_a, b, size_b);
}
