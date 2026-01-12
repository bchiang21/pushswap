// pseudocode

/* take in string with arg c/ v
buffer = string

1. sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.

if (array < 2) return;
string length the array;
temp == array[last];
array[last] == array[second last]
array[second last] == temp

2. sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.

if array == null or == array[0], return null;
string length the array;
temp == array[last];
array[last] == array[second last]
array[second last] == temp

3. ss : sa and sb at the same time.

function_ss()
{
    function_sa(); 
    function_sb();
} 

4. pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty

pa(a, size_a, b, size_b);
if size_b == 0;
    return

    value = b[size_b -1]
    size_b--

    a[size_a] == value
    a++

5. pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

pb(a, size_a, b, size_b)
if size_a == 0, return

value = a[size_a -1]
size_a--

b[size_b -1] == value
b++


6. ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

ra(a, size a)
    if size_a < 2 return

temp[] == a[size_a - 1]
i = size_a -1
while i > 0
    a[i] = a[i - 1]
    i--
    a[0] = temp


7. rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rb(b, size b)
    if size_b < 2
    return

    temp[] == array_b[size_b -1]

    i = size_b - 1
    while i > 0
    b[i]



8. rr : ra and rb at the same time.

rr(char * ra, char * rb)
{
    ra()
    rb()
}


9. rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rra(a, size_a)

temp[] == array_a[0]

i = 0
while i < size_a -1
a[i] = a[i+1]
i++
a[size_a - 1] = temp

print "rra\n"

10. rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrb(b, size_b)

temp[] == array_b[0]

i = 0
while i < size_b -1
b[i] = b[i+1]
i++
b[size_b - 1] = temp

print "rrb\n"



11.. rrr : rra and rrb at the same time.

rrr(char * rra, char * rrb)
{
    no_print_rra()
    no_print_rrb()

    print rrr
}