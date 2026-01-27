/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:25:28 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:25:30 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*  operations  */

void	sa(int *a, int *size_a);
void	sb(int *b, int *size_b);
void	ra(int *a, int *size_a);
void	rb(int *b, int *size_b);
void	rra(int *a, int *size_a);
void	rrb(int *b, int *size_b);
void	pa(int *a, int *b, int *size_a, int *size_b);
void	pb(int *a, int *b, int *size_a, int *size_b);
void	sa_core(int *a, int *size_a);
void	sb_core(int *a, int *size_a);
void	ra_core(int *a, int *size_a);
void	rb_core(int *a, int *size_a);
void	rra_core(int *a, int *size_a);
void	rrb_core(int *a, int *size_a);

/*  parsing / utils  */

int		parse_int(const char *s, int *out);
int		has_duplicates(int *a, int n);
int		is_sorted(int *a, int n);
void	error_exit(void);

/*  algorithms  */

void	compress_to_ranks(int *a, int n);

int		try_tiny_sort(int *a, int *size_a, int *b, int *size_b);
void	sort_2(int *a, int *size_a);
void	sort_3(int *a, int *size_a);
void	sort_5(int *a, int *size_a, int *b, int *size_b);

void	algo_selection_small(int *a, int *size_a,
			int *b, int *size_b);
void	algo_radix(int *a, int *size_a,
			int *b, int *size_b);

void	sort_dispatch(int *a, int *size_a,
			int *b, int *size_b);

#endif
