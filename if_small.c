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

int	index_of_min(int *a, int size_a)
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

void	rotate_index_to_top(int *a, int *size_a, int idx)
{
	int	half;
	int	steps;

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
		steps = *size_a - idx;
		while (steps > 0)
		{
			rra(a, size_a);
			steps--;
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
}
