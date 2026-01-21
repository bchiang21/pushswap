#include <stdio.h>   // for printf (debug only, remove later)
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 500

// Core / silent operations (no printing)

// Swap a core
static void sa_core(int *a, int *size_a)
{
    int tmp;

    if (*size_a < 2)
        return;

    tmp = a[0];
    a[0] = a[1];
    a[1] = tmp;
}

// Swap b core
static void sb_core(int *b, int *size_b)
{
    int tmp;

    if (*size_b < 2)
        return;

    tmp = b[0];
    b[0] = b[1];
    b[1] = tmp;
}

// Rotate a core
static void ra_core(int *a, int *size_a)
{
    int tmp;
    int i;

    if (*size_a < 2)
        return;

    tmp = a[0];
    i = 0;
    while (i < *size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    a[*size_a - 1] = tmp;
}

// Rotate b core
static void rb_core(int *b, int *size_b)
{
    int tmp;
    int i;

    if (*size_b < 2)
        return;

    tmp = b[0];
    i = 0;
    while (i < *size_b - 1)
    {
        b[i] = b[i + 1];
        i++;
    }
    b[*size_b - 1] = tmp;
}

// Reverse rotate a core
static void rra_core(int *a, int *size_a)
{
    int tmp;
    int i;

    if (*size_a < 2)
        return;

    tmp = a[*size_a - 1];
    i = *size_a - 1;
    while (i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }
    a[0] = tmp;
}

// Reverse rotate b core
static void rrb_core(int *b, int *size_b)
{
    int tmp;
    int i;

    if (*size_b < 2)
        return;

    tmp = b[*size_b - 1];
    i = *size_b - 1;
    while (i > 0)
    {
        b[i] = b[i - 1];
        i--;
    }
    b[0] = tmp;
}

// Printing wrappers — call these in your algorithm to perform op + print

void sa(int *a, int *size_a)
{
    sa_core(a, size_a);
    write(1, "sa\n", 3);
}

void sb(int *b, int *size_b)
{
    sb_core(b, size_b);
    write(1, "sb\n", 3);
}

void ra(int *a, int *size_a)
{
    ra_core(a, size_a);
    write(1, "ra\n", 3);
}

void rb(int *b, int *size_b)
{
    rb_core(b, size_b);
    write(1, "rb\n", 3);
}

void rra(int *a, int *size_a)
{
    rra_core(a, size_a);
    write(1, "rra\n", 4);
}

void rrb(int *b, int *size_b)
{
    rrb_core(b, size_b);
    write(1, "rrb\n", 4);
}

// Combined operations — use cores + print combined name

void ss(int *a, int *b, int *size_a, int *size_b)
{
    sa_core(a, size_a);
    sb_core(b, size_b);
    write(1, "ss\n", 3);
}

void rr(int *a, int *b, int *size_a, int *size_b)
{
    ra_core(a, size_a);
    rb_core(b, size_b);
    write(1, "rr\n", 3);
}

void rrr(int *a, int *b, int *size_a, int *size_b)
{
    rra_core(a, size_a);
    rrb_core(b, size_b);
    write(1, "rrr\n", 4);
}

// Operations that always print (no combined)

void pa(int *a, int *b, int *size_a, int *size_b)
{
    int value;
    int i;

    if (*size_b == 0)
        return;

    value = b[0];

    // remove top of B
    i = 0;
    while (i < *size_b - 1)
    {
        b[i] = b[i + 1];
        i++;
    }
    (*size_b)--;

    // make room at top of A
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


void pb(int *a, int *b, int *size_a, int *size_b)
{
    int value;
    int i;

    if (*size_a == 0)
        return;

    value = a[0];

    // remove top of A
    i = 0;
    while (i < *size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    (*size_a)--;

    // make room at top of B
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


/* ************************************************************************** */
/*  push_swap_selection.c                                                     */
/*  Array-based push_swap selection-sort strategy (top is A[0])               */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static void	putstr(const char *s)
{
	while (*s)
		write(1, s++, 1);
}

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

/* Strict atoi: returns 1 on success, 0 on error (non-int / overflow / junk) */
static int	parse_int(const char *s, int *out)
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

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	has_duplicates(int *a, int n)
{
	int i;
	int j;

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

static int	is_sorted(int *a, int n)
{
	int i;

	i = 0;
	while (i + 1 < n)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/* ===================== selection-sort strategy ===================== */

static int	index_of_min(int *a, int size_a)
{
	int i;
	int min_i;

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

static void	rotate_min_to_top(int *a, int size_a)
{
	int i;

	i = index_of_min(a, size_a);
	if (i <= size_a / 2)
	{
		while (i > 0)
		{
			ra(a, &size_a);
			i--;
		}
	}
	else
	{
		while (i < size_a)
		{
			rra(a, &size_a);
			i++;
		}
	}
}

static void algo_selection(int *a, int *size_a, int *b, int *size_b)
{
    if (is_sorted(a, *size_a))
        return;

    while (*size_a > 0)
    {
        rotate_min_to_top(a, *size_a);
        pb(a, b, size_a, size_b);   // <-- fixed
    }
    while (*size_b > 0)
        pa(a, b, size_a, size_b);   // <-- fixed
}


/* ===================== main ===================== */

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	i;

	if (argc <= 1)
		return (0);

	size_a = argc - 1;
	size_b = 0;

	a = (int *)malloc(sizeof(int) * size_a);
	b = (int *)malloc(sizeof(int) * size_a);
	if (!a || !b)
		error_exit();

	i = 0;
	while (i < size_a)
	{
		if (!parse_int(argv[i + 1], &a[i]))
			error_exit();
		i++;
	}
	if (has_duplicates(a, size_a))
		error_exit();

	algo_selection(a, &size_a, b, &size_b);

	free(a);
	free(b);
	return (0);
}

