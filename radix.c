static int	max_value(const int *A, int lenA)
{
	int i = 0;
	int m = 0;

	while (i < lenA)
	{
		if (A[i] > m)
			m = A[i];
		i++;
	}
	return m;
}

static int	count_bits(int x)
{
	int bits = 0;
	while ((x >> bits) != 0)
		bits++;
	return bits;
}

static void	radix_pass_bit_arr(int *A, int *lenA, int *B, int *lenB, int bit)
{
	int size;
	int i;

	size = *lenA;
	i = 0;
	while (i < size)
	{
		if (((A[0] >> bit) & 1) == 0)
			pb(A, lenA, B, lenB);
		else
			ra(A, *lenA);
		i++;
	}
	while (*lenB > 0)
		pa(A, lenA, B, lenB);
}

void	radix_sort_base4_lsd_arr(int *A, int lenA)
{
	int	*B;
	int	lenB;
	int	max;
	int	bits;
	int	shift;

	B = (int *)malloc(sizeof(int) * lenA);
	if (!B)
		return;
	lenB = 0;

	max = max_value(A, lenA);
	bits = count_bits(max);

	shift = 0;
	while (shift < bits)
	{
		radix_pass_bit_arr(A, &lenA, B, &lenB, shift);
		if (shift + 1 < bits)
			radix_pass_bit_arr(A, &lenA, B, &lenB, shift + 1);
		shift += 2;
	}

	free(B);
}
