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

static int	g_bit;

int	max_bits_needed(int n)
{
	int	bits;

	bits = 0;
	while ((n - 1) >> bits)
		bits++;
	return (bits);
}

static void	radix_pass(int *a, int *size_a, int *b, int *size_b)
{
	int	i;
	int	n;

	n = *size_a;
	i = 0;
	while (i < n)
	{
		if (((a[0] >> g_bit) & 1) == 0)
			pb(a, b, size_a, size_b);
		else
			ra(a, size_a);
		i++;
	}
	while (*size_b > 0)
		pa(a, b, size_a, size_b);
}

void	algo_radix(int *a, int *size_a, int *b, int *size_b)
{
	int	max_bits;

	if (*size_a <= 1 || is_sorted(a, *size_a))
		return ;
	compress_to_ranks(a, *size_a);
	max_bits = max_bits_needed(*size_a);
	g_bit = 0;
	while (g_bit < max_bits)
	{
		radix_pass(a, size_a, b, size_b);
		g_bit++;
	}
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
