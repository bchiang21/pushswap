/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:25:45 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/26 17:25:47 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "push_swap.h"

long	read_value(const char **ps, int sign)
{
	long	val;

	val = 0;
	while (is_digit(**ps))
	{
		val = val * 10 + (**ps - '0');
		if ((sign == 1 && val > INT_MAX)
			|| (sign == -1 && - val < INT_MIN))
			error_exit();
		(*ps)++;
	}
	return (val);
}

int	parse_next_int(const char **ps, int *out)
{
	int		sign;
	long	val;

	if (!skip_spaces(ps))
		return (0);
	sign = read_sign(ps);
	val = read_value(ps, sign);
	if (**ps && !is_space(**ps))
		error_exit();
	*out = (int)(val * sign);
	return (1);
}

int	count_numbers_in_str(const char *s)
{
	int	tmp;
	int	count;

	count = 0;
	while (parse_next_int(&s, &tmp))
		count++;
	return (count);
}

int	count_numbers(int argc, char **argv)
{
	int	total;
	int	i;

	total = 0;
	i = 1;
	while (i < argc)
	{
		total += count_numbers_in_str(argv[i]);
		i++;
	}
	return (total);
}

void	load_args(int argc, char **argv, int *a, int size_a)
{
	const char	*s;
	int			i;
	int			k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		s = argv[i];
		while (parse_next_int(&s, &a[k]))
		{
			k++;
			if (k > size_a)
				error_exit();
		}
		i++;
	}
	if (k != size_a)
		error_exit();
}
