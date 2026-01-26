/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:25:45 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:25:47 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

/* ===================== parsing / utils ===================== */

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	parse_int(const char *s, int *out)
{
	long	sign;
	long	val;

	while (*s && is_space(*s))
		s++;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (*s < '0' || *s > '9')
		return (0);
	val = 0;
	while (*s >= '0' && *s <= '9')
	{
		val = val * 10 + (*s - '0');
		if (sign * val > INT_MAX || sign * val < INT_MIN)
			return (0);
		s++;
	}
	while (*s && is_space(*s))
		s++;
	if (*s != '\0')
		return (0);
	*out = (int)(sign * val);
	return (1);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	has_duplicates(int *a, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[i] == a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(int *a, int n)
{
	int	i;

	i = 0;
	while (i + 1 < n)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
