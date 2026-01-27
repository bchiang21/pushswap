/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_compress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:25:37 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:25:39 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

/*  rank compression (value -> index) */

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	swapped;
	int	tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i + 1 < n)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	index_in_sorted(int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	compress_to_ranks(int *a, int n)
{
	int	*tmp;
	int	i;
	int	idx;

	tmp = (int *)malloc(sizeof(int) * n);
	if (!tmp)
		error_exit();
	i = 0;
	while (i < n)
	{
		tmp[i] = a[i];
		i++;
	}
	bubble_sort(tmp, n);
	i = 0;
	while (i < n)
	{
		idx = index_in_sorted(tmp, n, a[i]);
		if (idx < 0)
			error_exit();
		a[i] = idx;
		i++;
	}
	free(tmp);
}
