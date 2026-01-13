// pseudocode

/* take in string with arg c/ v
buffer = string

1. sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none. */

void sa(int * a, int size_a)
{
    int temp;

    if (size_a < 2)
        return a[0];

    temp == a[0];
    a[0] == a[1];
    a[1] == temp;

    write(1, "sa\n", 3));

    return (a[0]);

}

/* 2. sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none. */

void sb(int *b, int size_b)
{
    int temp;

    if (size_b < 2)
        return a[0];

    temp == b[0];
    b[0] == b[1];
    b[1] == temp;

    write(1, "sb\n", 3);

    return (a[0]);

}

// 3. ss : sa and sb at the same time.

int ss(int *a, int *b, int size_a, int size_b)
{
    sa(a, size_a); 
    sb(b, size_b);

    write(1, "ss\n", 3);

} 

/* 4. pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty */

void pa(int *a, int *b, int *size_a, int *size_b)
{
    int temp = b[0];
    int i = 0;

    if (*size_b == 0)
        return;
  
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

    a[0] == temp;
    (*size_a)

    write(1, "pa\n", 3);
}


/* 5. pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */

void pb(int *a, int *b, int *size_a, int *size_b)
{
    int i;
    int value = a[0];

    if (*size_a == 0)
        return;

    i = 0;
    while (i < *size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    (*size_a)--;

    b[*size_b -1] = value;
    (*size_b)++;

    b[*size_b] = value;
    (*size_b)++;

    write(1, "pb\n", 3);
}

/* 6. ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one. */

void ra(int *a, int *size a)
{
    int temp;
    int i;

    if (size_a < 2)
        return;

    temp[] == a[0];
    
    i = 0;
    
    while (i < *size_a - 1)
    {
        a[i] = a[i + 1]; 
        i++;
    }

    a[*size_a - 1] = temp;

    write(1, "ra\n",3);

}

7. rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

void rb(int *b, int *size b)
{
    int temp;

    if (size_b < 2)
        return;

    temp[] == array_b[0];
    
    while (i < *size_b -1)
    {
        b[i] = b[i +1];
        b++;
    }
        b[*size_b - 1] = temp;

    write(1, "rb\n", 3);
}

// 8. rr : ra and rb at the same time.

void rr(int *a, int *b, int *size_a, int *size_b)
{
    if (*size_a >= 2)
     ra(a, size_a);

    if (*size_b >= 2)
     rb(b, size_b);

    write(1, "rr\n", 3);
}


// 9. rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

void    rra(int *a, int *size_a, int print)
{
    int first;
    int i;

    if (*size_a < 2)
        return;

    first = a[0];
    i = 0;
    while (i < *size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    a[*size_a - 1] = first;

    if (print)
        write(1, "ra\n", 3);
}


// 10. rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

void    rrb(int *b, int *size_b, int print)
{
    int first;
    int i;

    if (*size_b < 2)
        return;

    first = b[0];
    i = 0;
    while (i < *size_b - 1)
    {
        b[i] = b[i + 1];
        i++;
    }
    b[*size_b - 1] = first;

    if (print)
        write(1, "rb\n", 3);
}


/* To print Normal independent use → print
rra(a, size_a, 1);
ra(b, size_b, 1); */

// 11.. rrr : rra and rrb at the same time.

void    rrr(int *a, int *b, int *size_a, int *size_b)
{
    rra(a, size_a, 0);
    rrb(b, size_b, 0);
    write(1, "rrr\n", 4);
}