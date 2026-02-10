_This project has been created as part of the 42 curriculum by bchiang._

**PUSH SWAP**

**Description**

Push Swap is a movement based sorting algorithm. The goal of the project is to sort a list of integers in ascending order using two stacks and a restricted set of operations, while minimizing the total number of operations produced.

The program takes a sequence of integers as input (stack A), uses an auxiliary stack (stack B), and outputs a list of instructions that, when executed, result in stack A being sorted.

This project considers:

- Algorithmic thinking under constraints
- Optimization of operation count
- Correct handling of edge cases
- C implementation

**Instructions**

1. Compile the project using make:

`make`

This will generate the executable push_swap.

Execution

Run the program by passing a list of integers as arguments:

` ./push_swap 3 2 1 `


The program will output a sequence of operations, one per line.

Example output:

pb
pb
sa
pa
pa

Verification (Optional)

You can verify the correctness of the output using the provided checker program:

` ./push_swap 3 2 1 | ./checker 3 2 1 `


The checker will output OK if the operations correctly sort the stack, or KO otherwise.

**Algorithm Overview**

This implementation uses the radix sorting strategy:

1. Input values are first indexed relative to their sorted order (rank_compress.c)

2. From the indexed ranks, Stack B is then organized so that elements can be pushed back to stack A in the correct order.

3. Special optimized logic is used for small inputs such as 2, 3, or 5 numbers (if_small and if_very_small).

This approach balances simplicity and efficiency, keeping the number of operations within acceptable limits for evaluation.

**Error Handling**

The program prints Error\n and exits if:

    - Any argument is not a valid integer
    - Duplicate values are detected
    - Values exceed integer limits
    - No arguments are provided

**Resources**

42 subject PDF for push_swap

General Google for 
    - Stack-based sorting concepts
    - Insertion sort and radix-inspired strategies
    - Algorithm optimization under constraints

Official C documentation (man, cppreference)

External Articles and Tutorials

“Sorting Algorithms” — GeeksforGeeks

“Understanding Stack Operations” — TutorialsPoint

Various peer explanations and diagrams from the 42 community

Use of AI

ChatGPT was used as a supporting aid, not as an automated solution generator.
Specifically, AI was used for:

    - Clarifying algorithmic concepts (e.g. chunking strategies)
    - Reviewing and improving documentation clarity (README wording)
    - Sanity-checking edge cases and explanations

All core logic, implementation decisions, and code were written and understood by the author.

**Additional Notes**

The program strictly follows the allowed operations defined in the subject.

No unnecessary instructions are printed.

The project was developed and tested according to 42 norms.