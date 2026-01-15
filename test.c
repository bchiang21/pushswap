int main(void)
{
    int a[MAX_SIZE];
    int b[MAX_SIZE];
    int size_a;
    int size_b;

    // ── Initial setup ───────────────────────────────────────────────
    size_a = 6;
    size_b = 0;

    a[0] = 42;
    a[1] = 17;
    a[2] =  -8;
    a[3] =  99;
    a[4] =   3;
    a[5] =  25;

    printf("=== INITIAL STATE ===\n");
    print_stacks(a, b, size_a, size_b);

    // ── Swaps ───────────────────────────────────────────────────────
    printf("\n=== sa ===\n");
    sa(a, &size_a);
    print_stacks(a, b, size_a, size_b);

    printf("\n=== sb === (nothing happens - b empty)\n");
    sb(b, &size_b);
    print_stacks(a, b, size_a, size_b);

    printf("\n=== ss ===\n");
    ss(a, b, &size_a, &size_b);
    print_stacks(a, b, size_a, size_b);

    // ── Rotations ───────────────────────────────────────────────────
    printf("\n=== ra ===\n");
    ra(a, &size_a);
    print_stacks(a, b, size_a, size_b);

    printf("\n=== rb === (nothing - b empty)\n");
    rb(b, &size_b);
    print_stacks(a, b, size_a, size_b);

    printf("\n=== rr ===\n");
    rr(a, b, &size_a, &size_b);
    print_stacks(a, b, size_a, size_b);

    // ── Reverse rotations ───────────────────────────────────────────
    printf("\n=== rra ===\n");
    rra(a, &size_a);
    print_stacks(a, b, size_a, size_b);

    printf("\n=== rrb === (nothing - b empty)\n");
    rrb(b, &size_b);
    print_stacks(a, b, size_a, size_b);

    printf("\n=== rrr ===\n");
    rrr(a, b, &size_a, &size_b);
    print_stacks(a, b, size_a, size_b);

    // ── Push operations ─────────────────────────────────────────────
    printf("\n=== pb x3 === (move 3 elements to b)\n");
    pb(a, b, &size_a, &size_b);
    pb(a, b, &size_a, &size_b);
    pb(a, b, &size_a, &size_b);
    print_stacks(a, b, size_a, size_b);

    printf("\n=== pa x2 === (move 2 back to a)\n");
    pa(a, b, &size_a, &size_b);
    pa(a, b, &size_a, &size_b);
    print_stacks(a, b, size_a, size_b);

    // Final state
    printf("\n=== FINAL STATE ===\n");
    print_stacks(a, b, size_a, size_b);

    return (0);
}