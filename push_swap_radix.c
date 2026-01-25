#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define MAX_SIZE 500

/* ===================== core ops (no printing) ===================== */

static void sa_core(int *a, int *size_a)
{
    int tmp;
    if (*size_a < 2) return;
    tmp = a[0]; a[0] = a[1]; a[1] = tmp;
}

static void sb_core(int *b, int *size_b)
{
    int tmp;
    if (*size_b < 2) return;
    tmp = b[0]; b[0] = b[1]; b[1] = tmp;
}

static void ra_core(int *a, int *size_a)
{
    int tmp, i;
    if (*size_a < 2) return;
    tmp = a[0];
    i = 0;
    while (i < *size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    a[*size_a - 1] = tmp;
}

static void rb_core(int *b, int *size_b)
{
    int tmp, i;
    if (*size_b < 2) return;
    tmp = b[0];
    i = 0;
    while (i < *size_b - 1)
    {
        b[i] = b[i + 1];
        i++;
    }
    b[*size_b - 1] = tmp;
}

static void rra_core(int *a, int *size_a)
{
    int tmp, i;
    if (*size_a < 2) return;
    tmp = a[*size_a - 1];
    i = *size_a - 1;
    while (i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }
    a[0] = tmp;
}

static void rrb_core(int *b, int *size_b)
{
    int tmp, i;
    if (*size_b < 2) return;
    tmp = b[*size_b - 1];
    i = *size_b - 1;
    while (i > 0)
    {
        b[i] = b[i - 1];
        i--;
    }
    b[0] = tmp;
}

/* ===================== printing wrappers ===================== */

void sa(int *a, int *size_a) { sa_core(a, size_a); write(1, "sa\n", 3); }
void sb(int *b, int *size_b) { sb_core(b, size_b); write(1, "sb\n", 3); }
void ra(int *a, int *size_a) { ra_core(a, size_a); write(1, "ra\n", 3); }
void rb(int *b, int *size_b) { rb_core(b, size_b); write(1, "rb\n", 3); }
void rra(int *a, int *size_a) { rra_core(a, size_a); write(1, "rra\n", 4); }
void rrb(int *b, int *size_b) { rrb_core(b, size_b); write(1, "rrb\n", 4); }

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

/* push: top is index 0 */

void pa(int *a, int *b, int *size_a, int *size_b)
{
    int value, i;
    if (*size_b == 0) return;

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

void pb(int *a, int *b, int *size_a, int *size_b)
{
    int value, i;
    if (*size_a == 0) return;

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

/* ===================== parsing / utils ===================== */

static int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n'
        || c == '\v' || c == '\f' || c == '\r');
}

static int parse_int(const char *s, int *out)
{
    long sign, val;

    while (*s && is_space(*s)) s++;
    sign = 1;
    if (*s == '+' || *s == '-')
    {
        if (*s == '-') sign = -1;
        s++;
    }
    if (*s < '0' || *s > '9') return 0;

    val = 0;
    while (*s >= '0' && *s <= '9')
    {
        val = val * 10 + (*s - '0');
        if (sign * val > INT_MAX || sign * val < INT_MIN) return 0;
        s++;
    }
    while (*s && is_space(*s)) s++;
    if (*s != '\0') return 0;

    *out = (int)(sign * val);
    return 1;
}

static void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

static int has_duplicates(int *a, int n)
{
    int i, j;
    i = 0;
    while (i < n)
    {
        j = i + 1;
        while (j < n)
        {
            if (a[i] == a[j]) return 1;
            j++;
        }
        i++;
    }
    return 0;
}

static int is_sorted(int *a, int n)
{
    int i;
    i = 0;
    while (i + 1 < n)
    {
        if (a[i] > a[i + 1]) return 0;
        i++;
    }
    return 1;
}

/* ===================== rank compression (value -> index) ===================== */

/* simple bubble sort on an int array (for n <= 500, fine) */
static void bubble_sort(int *arr, int n)
{
    int i, swapped, tmp;
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

/* find index of value in sorted array (exists because no duplicates) */
static int index_in_sorted(int *sorted, int n, int value)
{
    int i;
    i = 0;
    while (i < n)
    {
        if (sorted[i] == value)
            return i;
        i++;
    }
    return -1;
}

/*
    Replace each value in A by its rank:
    smallest -> 0, next -> 1, ... largest -> n-1
*/
static void compress_to_ranks(int *a, int n)
{
    int *tmp;
    int i, idx;

    tmp = (int *)malloc(sizeof(int) * n);
    if (!tmp) error_exit();

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
        if (idx < 0) error_exit();
        a[i] = idx;
        i++;
    }

    free(tmp);
}

static int max_bits_needed(int n)
{
    int bits;
    bits = 0;
    while ((n - 1) >> bits)
        bits++;
    return bits;
}

/* ===================== radix algorithm ===================== */

/*
    Binary radix (LSD):
    For each bit = 0..max_bits-1:
      - Repeat original_size times:
          if (top bit is 0) pb
          else ra
      - Then pa until B empty
*/
static void algo_radix(int *a, int *size_a, int *b, int *size_b)
{
    int bit;
    int i;
    int original_size;
    int max_bits;

    if (*size_a <= 1 || is_sorted(a, *size_a))
        return;

    compress_to_ranks(a, *size_a);

    original_size = *size_a;
    max_bits = max_bits_needed(original_size);

    bit = 0;
    while (bit < max_bits)
    {
        i = 0;
        while (i < original_size)
        {
            if (((a[0] >> bit) & 1) == 0)
                pb(a, b, size_a, size_b);
            else
                ra(a, size_a);
            i++;
        }
        while (*size_b > 0)
            pa(a, b, size_a, size_b);
        bit++;
    }
}

/* ===================== main ===================== */

int main(int argc, char **argv)
{
    int *a;
    int *b;
    int size_a;
    int size_b;
    int i;

    if (argc <= 1)
        return 0;

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

    algo_radix(a, &size_a, b, &size_b);

    free(a);
    free(b);
    return 0;
}
