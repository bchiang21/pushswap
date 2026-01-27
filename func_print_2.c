/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_print_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:24:48 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:24:52 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

void	rra(int *a, int *size_a)
{
	rra_core(a, size_a);
	write(1, "rra\n", 4);
}

void	rrb(int *b, int *size_b)
{
	rrb_core(b, size_b);
	write(1, "rrb\n", 4);
}

void	rr(int *a, int *b, int *size_a, int *size_b)
{
	ra_core(a, size_a);
	rb_core(b, size_b);
	write(1, "rr\n", 3);
}

void	rrr(int *a, int *b, int *size_a, int *size_b)
{
	rra_core(a, size_a);
	rrb_core(b, size_b);
	write(1, "rrr\n", 4);
}
