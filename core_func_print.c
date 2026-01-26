/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_func_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:24:12 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:24:24 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

/* ===================== printing wrappers ===================== */

void	sa(int *a, int *size_a)
{
	sa_core(a, size_a);
	write(1, "sa\n", 3);
}

void	sb(int *b, int *size_b)
{
	sb_core(b, size_b);
	write(1, "sb\n", 3);
}

void	ss(int *a, int *b, int *size_a, int *size_b)
{
	sa_core(a, size_a);
	sb_core(b, size_b);
	write(1, "ss\n", 3);
}

void	ra(int *a, int *size_a)
{
	ra_core(a, size_a);
	write(1, "ra\n", 3);
}

void	rb(int *b, int *size_b)
{
	rb_core(b, size_b);
	write(1, "rb\n", 3);
}
