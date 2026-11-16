
*This activity has been created as part of the 42 curriculum by noclemen, tlasnier.*

# Push_swap

## Description

Push_swap is an algorithmic project from the 42 curriculum. The goal of this project is to sort a list of integers using two stacks (A and B) and a limited set of operations, while minimizing the total number of operations.

At the beginning, all integers are stored in stack A, while stack B is empty. The program must generate a sequence of instructions that sorts the numbers in ascending order in stack A, using only the authorized operations.

The project focuses on algorithm design, sorting strategies, data structures, complexity analysis, and optimization.

This implementation includes four sorting strategies, allowing different approaches to be selected depending on the size and initial disorder of the input.

---

## Instructions

### Compilation

The project includes a Makefile with the following targets:

    make : Compiles the project with -Wall -Wextra -Werror and creates the push_swap executable. It also compiles the Libft library.
    make clean : Removes all intermediate object files (.o).
    make fclean : Removes object files, the push_swap executable, and the compiled Libft library.
    make re : Performs a complete rebuild (fclean followed by make).

### Execution

The program accepts a list of integers as arguments:

    ./push_swap 4 67 3 87 23

It also accepts multiple numbers inside a single quoted argument:

    ./push_swap "4 67 3 87 23"

The program outputs the sequence of operations required to sort stack A.

### Available Options

The sorting strategy can be selected using the following flags:

    --simple : Uses the Min/Max selection algorithm.
    --medium : Uses the Butterfly Chunk algorithm.
    --complex : Uses the Binary Radix Sort algorithm.
    --adaptive : Automatically selects the sorting strategy based on the initial disorder of the stack.

By default, the program uses the adaptive strategy.

Examples:

    ./push_swap --simple 4 67 3 87 23
    ./push_swap --medium 4 67 3 87 23
    ./push_swap --complex 4 67 3 87 23
    ./push_swap --adaptive 4 67 3 87 23

### Benchmark Mode

The program also provides a benchmark mode to display information about the sorting process.

    --bench : Displays benchmark information after sorting.

Example:

    ./push_swap --bench 4 67 3 87 23
    ./push_swap --adaptive --bench 4 67 3 87 23

The benchmark reports the selected strategy, the initial disorder, the estimated complexity, and the number of operations performed.

### Input Validation

The program checks the input before starting the sorting process.

    - Only valid integers are accepted.
    - Both positive and negative numbers are supported.
    - Values must fit within the INT_MIN and INT_MAX range.
    - Duplicate values are not allowed.
    - Invalid arguments produce an Error message on standard error.

If the input is already sorted, no operations are performed.

---

## Available Operations

The program uses the following operations to manipulate the two stacks:

### Swap

    sa : Swaps the first two elements of stack A.
    sb : Swaps the first two elements of stack B.
    ss : Performs sa and sb simultaneously.

### Push

    pa : Takes the first element of stack B and pushes it onto stack A.
    pb : Takes the first element of stack A and pushes it onto stack B.

### Rotate

    ra : Shifts all elements of stack A up by one position. The first element becomes the last.
    rb : Shifts all elements of stack B up by one position. The first element becomes the last.
    rr : Performs ra and rb simultaneously.

### Reverse Rotate

    rra : Shifts all elements of stack A down by one position. The last element becomes the first.
    rrb : Shifts all elements of stack B down by one position. The last element becomes the first.
    rrr : Performs rra and rrb simultaneously.

---

## Sorting Algorithms

This project implements three different sorting algorithms, combined into four execution strategies. Each algorithm has been designed for a different input size and level of disorder.

### 1. Simple Strategy - Min/Max Selection

Estimated complexity: O(n²)

The simple strategy uses a selection-based approach to sort the elements.

The algorithm repeatedly searches for the minimum and maximum values in stack A and compares the number of rotations required to bring each one to the top.

    1. Find the position of the minimum and maximum elements in stack A.
    2. Calculate the rotation cost for both positions.
    3. Push the element requiring the fewest rotations to stack B.
    4. When pushing a maximum value, rotate stack B to maintain a useful ordering.
    5. Repeat until stack A is empty.
    6. Rotate stack B to bring its maximum element to the top.
    7. Push all elements back to stack A using pa.

By extracting minimum and maximum values according to their rotation costs, this strategy attempts to reduce unnecessary operations.

It is particularly suitable for small input sizes.

### 2. Medium Strategy - Butterfly Chunk Sort

Estimated complexity: O(n√n)

The medium strategy uses a chunk-based sorting approach inspired by the Butterfly algorithm.

Before sorting, each value is assigned an index corresponding to its rank in the sorted sequence.

For example:

    Original values:  40  10  30  20
    Assigned indexes: 3   0   2   1

The algorithm then divides the indexed values into chunks. The chunk size is calculated using the square root of the number of elements.

    chunk_size = √n

The sorting process works as follows:

    1. Assign a sorted index to every element.
    2. Calculate the chunk size.
    3. Iterate through stack A and push elements belonging to the current chunk into stack B.
    4. When an element has an index smaller than or equal to the current chunk boundary, push it to B and rotate B.
    5. Elements belonging to the rest of the current chunk are pushed directly to B.
    6. Elements outside the current chunk are rotated in stack A.
    7. Once all elements have been transferred to B, repeatedly find the maximum index in B.
    8. Rotate B to bring that maximum to the top and push it back to A.

This approach groups elements by their relative position in the sorted sequence, reducing the number of operations compared to a basic selection-based strategy for larger inputs.

### 3. Complex Strategy - Binary Radix Sort

Estimated complexity: O(n log n)

The complex strategy implements a binary Radix Sort algorithm.

Instead of comparing values directly, the algorithm works with their normalized indexes.

Each element is assigned an index representing its position in the sorted order. This allows the algorithm to handle negative values and large integer ranges without directly processing their binary representations.

The algorithm examines the bits of each index, starting with the least significant bit.

For each bit position:

    1. Check the least significant bit currently being processed.
    2. If the bit is 0, push the element from A to B using pb.
    3. If the bit is 1, rotate A using ra.
    4. After processing every element, push all elements from B back to A using pa.
    5. Move to the next bit position.
    6. Repeat until all necessary bits have been processed.

The number of passes depends on the number of bits required to represent the maximum index.

This approach provides predictable performance and is particularly efficient for larger input sizes.

### 4. Adaptive Strategy

The adaptive strategy automatically selects the most appropriate algorithm based on the initial disorder of stack A.

The disorder is calculated before sorting and compared against two predefined thresholds:

    THRESHOLD_LOW  = 2000
    THRESHOLD_HIGH = 5000

The selection process is:

    Disorder < 2000:
        Select Min/Max Selection.
        Estimated complexity: O(n²).

    Disorder < 5000:
        Select Butterfly Chunk Sort.
        Estimated complexity: O(n√n).

    Disorder >= 5000:
        Select Binary Radix Sort.
        Estimated complexity: O(n log n).

The objective is to adapt the sorting algorithm to the initial arrangement of the input instead of always using the same strategy.

This allows the program to choose between different sorting approaches according to the measured disorder.

---

## Technical Choices

### Stack Representation

Both stacks are implemented using dynamically allocated arrays.

Each element is represented by a structure containing:

    typedef struct s_elem
    {
        int             value;
        size_t          index;
    }   t_elem;

The stack structure contains:

    typedef struct s_stack
    {
        t_elem  *data;
        size_t  size;
        size_t  capacity;
    }   t_stack;

This representation provides direct access to elements through array indexes and allows efficient implementation of the required stack operations.

### Indexing

Before executing the Butterfly or Radix algorithms, each element receives a normalized index.

The index corresponds to the number of elements containing a smaller value.

For example:

    Values:  50  10  40  20  30
    Indexes: 4   0   3   1   2

This technique simplifies sorting because the algorithms can operate on indexes instead of the original integer values.

It also allows negative numbers and large integer values to be handled consistently.

### Operation Counting

Every executed operation is counted in the context structure.

This information is used by the benchmark mode to provide statistics about the sorting process.

### Memory Management

Both stacks are allocated dynamically according to the number of input elements.

All allocated memory is released before the program terminates.

The project also relies on the Libft library for utility functions such as string splitting, string comparison, character validation, and memory initialization.

---

## Resources & AI Disclosure

### References

    42 Network - Push_swap subject and project requirements.
    Linux Programmer's Manual (man 3) - Documentation for standard C library functions.
    GeeksforGeeks - Explanations of sorting algorithms, including Radix Sort.
    Wikipedia - Radix Sort and sorting algorithm complexity.
    Open Data Structures - Documentation about arrays, stacks, and algorithmic complexity.
    Koor.fr - C programming documentation and tutorials.

### AI Usage

Artificial Intelligence was used strictly as a conceptual tutor and language assistant:

    Conceptual Learning: Explaining sorting algorithms, including Min/Max Selection, Butterfly Chunk Sort, and Binary Radix Sort, to improve theoretical understanding.

    Algorithm Analysis: Helping understand algorithmic complexity, time complexity, indexing techniques, and the trade-offs between different sorting strategies.

    Documentation: Assisting with the organization, wording, and translation of the README file.

    No project code was generated by AI. All implementation and algorithmic decisions were made and written by the project authors.
