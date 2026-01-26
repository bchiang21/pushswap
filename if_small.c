/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_small.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:25:06 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:25:08 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

/* === small selection strategy (<= 20) =========== */

static int	index_of_min(int *a, int size_a)
{
	int	i;
	int	min_i;

	i = 1;
	min_i = 0;
	while (i < size_a)
	{
		if (a[i] < a[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

/* static void	rotate_index_to_top(int *a, int *size_a, int idx)
{
	int	half;

	if (*size_a < 2)
		return ;
	half = *size_a / 2;
	if (idx <= half)
	{
		while (idx > 0)
		{
			ra(a, size_a);
			idx--;
		}
	}
	else
	{
		while (idx < *size_a)
		{
			rra(a, size_a);
			idx++;
		}
	}
}

void	algo_selection_small(int *a, int *size_a, int *b, int *size_b)
{
	int	idx;

	if (*size_a <= 1 || is_sorted(a, *size_a))
		return ;
	while (*size_a > 0)
	{
		idx = index_of_min(a, *size_a);
		rotate_index_to_top(a, size_a, idx);
		pb(a, b, size_a, size_b);
	}
	while (*size_b > 0)
		pa(a, b, size_a, size_b);
} */

/* ===================== tiny sorts: 2 / 3 / 5 ===================== */

void	sort_2(int *a, int *size_a)
{
	if (*size_a == 2 && a[0] > a[1])
		sa(a, size_a);
}

void	sort_3(int *a, int *size_a)
{
	int	x;
	int	y;
	int	z;

	if (*size_a != 3)
		return ;
	x = a[0];
	y = a[1];
	z = a[2];
	if (x > y && y < z && x < z)
		sa(a, size_a);
	else if (x > y && y > z)
	{
		sa(a, size_a);
		rra(a, size_a);
	}
	else if (x > y && y < z && x > z)
		ra(a, size_a);
	else if (x < y && y > z && x < z)
	{
		sa(a, size_a);
		ra(a, size_a);
	}
	else if (x < y && y > z && x > z)
		rra(a, size_a);
}

static void	rotate_a_idx_to_top(int *a, int *size_a, int idx)
{
	int	half;

	if (*size_a < 2)
		return ;
	half = *size_a / 2;
	if (idx <= half)
	{
		while (idx > 0)
		{
			ra(a, size_a);
			idx--;
		}
	}
	else
	{
		while (idx < *size_a)
		{
			rra(a, size_a);
			idx++;
		}
	}
}

void	sort_5(int *a, int *size_a, int *b, int *size_b)
{
	int	idx;
	int	pushes;

	if (*size_a != 5)
		return ;
	pushes = 0;
	while (pushes < 2)
	{
		idx = index_of_min(a, *size_a);
		rotate_a_idx_to_top(a, size_a, idx);
		pb(a, b, size_a, size_b);
		pushes++;
	}
	sort_3(a, size_a);
	pa(a, b, size_a, size_b);
	pa(a, b, size_a, size_b);
	if (*size_a >= 2 && a[0] > a[1])
		sa(a, size_a);
}
