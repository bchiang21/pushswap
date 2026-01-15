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
    i = 0;
    while (i < *size_b - 1)
    {
        b[i] = b[i + 1];
        i++;
    }
    (*size_b)--;
    a[*size_a] = value;
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
    i = 0;
    while (i < *size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    (*size_a)--;
    b[*size_b] = value;
    (*size_b)++;
    write(1, "pb\n", 3);
}

// === Your print helper (for debug) ===
static void print_stacks(int *a, int *b, int size_a, int size_b)
{
    int i;

    printf("\nA (%d): ", size_a);
    i = 0;
    while (i < size_a)
    {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");

    printf("B (%d): ", size_b);
    i = 0;
    while (i < size_b)
    {
        printf("%d ", b[i]);
        i++;
    }
    printf("\n");
}

// === main ===
int main(void)
{
   

    return (0);
}