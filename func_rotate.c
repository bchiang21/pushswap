/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:24:58 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:25:01 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

void	ra_core(int *a, int *size_a)
{
	int	tmp;
	int	i;

	if (*size_a < 2)
		return ;
	tmp = a[0];
	i = 0;
	while (i < *size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*size_a - 1] = tmp;
}

void	rb_core(int *b, int *size_b)
{
	int	tmp;
	int	i;

	if (*size_b < 2)
		return ;
	tmp = b[0];
	i = 0;
	while (i < *size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[*size_b - 1] = tmp;
}

void	rra_core(int *a, int *size_a)
{
	int	tmp;
	int	i;

	if (*size_a < 2)
		return ;
	tmp = a[*size_a - 1];
	i = *size_a - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
}

void	rrb_core(int *b, int *size_b)
{
	int	tmp;
	int	i;

	if (*size_b < 2)
		return ;
	tmp = b[*size_b - 1];
	i = *size_b - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = tmp;
}
