/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:24:37 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:24:41 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

/* ===================== core ops (no printing) ===================== */

void	sa_core(int *a, int *size_a)
{
	int	tmp;

	if (*size_a < 2)
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

void	sb_core(int *b, int *size_b)
{
	int	tmp;

	if (*size_b < 2)
		return ;
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
}

/* ===================== push (top is index 0) ===================== */

void	pa(int *a, int *b, int *size_a, int *size_b)
{
	int	value;
	int	i;

	if (*size_b == 0)
		return ;
	value = b[0];
	i = 0;
	while (i < *size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*size_b)--;
	i = *size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = value;
	(*size_a)++;
	write(1, "pa\n", 3);
}

void	pb(int *a, int *size_a, int *b, int *size_b)
{
	int	value;
	int	i;

	if (*size_a == 0)
		return ;
	value = a[0];
	i = 0;
	while (i < *size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*size_a)--;
	i = *size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = value;
	(*size_b)++;
	write(1, "pb\n", 3);
}
