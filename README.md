*This project has been created as part of the 42 curriculum by gearvani.*

# push_swap

## Description

**push_swap** is an algorithmic project from the 42 curriculum focused on sorting data under strict operational constraints. The objective is to sort a stack of unique integers in ascending order using two stacks (**Stack A** and **Stack B**) and a limited set of 11 stack instructions, while minimizing the total number of operations.

At startup, **Stack A** contains the unsorted integers passed via command-line arguments (with the first argument at the top of the stack), and **Stack B** is empty. The program outputs the sequence of instructions to `stdout` that leaves **Stack A** sorted in ascending order and **Stack B** completely empty.

In addition to standard sorting, this implementation measures the initial **disorder** of the input (the ratio of inverted pairs) and dynamically selects an optimal sorting strategy—or lets the user force a specific complexity class via CLI flags—while providing a built-in benchmark mode (`--bench`) to inspect operation counts.

### Allowed Operations

| Operation | Description |
| :--- | :--- |
| `sa` | Swap the first 2 elements at the top of Stack A. |
| `sb` | Swap the first 2 elements at the top of Stack B. |
| `ss` | Execute `sa` and `sb` simultaneously. |
| `pa` | Take the top element of Stack B and put it at the top of Stack A. |
| `pb` | Take the top element of Stack A and put it at the top of Stack B. |
| `ra` | Shift all elements of Stack A up by 1 (first element becomes last). |
| `rb` | Shift all elements of Stack B up by 1 (first element becomes last). |
| `rr` | Execute `ra` and `rb` simultaneously. |
| `rra` | Shift all elements of Stack A down by 1 (last element becomes first). |
| `rrb` | Shift all elements of Stack B down by 1 (last element becomes first). |
| `rrr` | Execute `rra` and `rrb` simultaneously. |

---

## Instructions

### Compilation

Compile the project at the root of the repository using `make`:

```bash
make
```

Additional Makefile rules:

```bash
make clean   # Remove object files (.o)
make fclean  # Remove object files and the push_swap executable
make re      # Recompile the project from scratch
```

### Execution & Usage

Run the binary with a list of space-separated integers or a single quoted string:

```bash
./push_swap [FLAGS] <numbers...>
```

#### Available Flags

Flags can be passed before the list of integers:

* `--adaptive` *(default)*: Automatically selects the best algorithm based on input size and computed disorder.
* `--simple`: Forces an $O(n^2)$ simple sorting strategy (Selection / Bubble Sort).
* `--medium`: Forces an $O(n\sqrt{n})$ chunk-based sorting strategy.
* `--complex`: Forces an $O(n \log n)$ binary LSD Radix Sort.
* `--bench`: Outputs detailed benchmark statistics (total operations and individual instruction counts) to `stderr`.

#### Examples

```bash
# Basic execution
./push_swap 4 67 3 87 23

# Single quoted argument string
./push_swap "4 67 3 87 23"

# Force a specific algorithm and enable benchmark output
./push_swap --medium --bench 4 67 3 87 23

# Count total operations
./push_swap 4 67 3 87 23 | wc -l

# Verify correctness with the 42 checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

### Error Handling

The program displays `Error\n` on `stderr` and exits cleanly if:
* An argument is not a valid integer.
* An integer overflows or underflows `INT_MIN` / `INT_MAX`.
* Duplicate integers are provided.
* Invalid or duplicate flags are passed.

---

## Algorithm & Technical Choices

Rather than relying on a single static method, this project combines **index normalization**, **disorder analysis**, and **four distinct algorithmic modes** to adapt to different input sizes and levels of pre-sortedness.

### 1. Input Normalization & Disorder Metric (`compute_disorder`)
Before sorting, input values are mapped to their normalized ranks ($0$ to $n - 1$). This eliminates issues with negative numbers or large value gaps and enables bitwise and range-based operations.

To evaluate how unsorted Stack A initially is, the program computes a **disorder score** $\in [0.0, 1.0]$ by counting all inversions ($i < j$ where $A[i] > A[j]$) divided by the total number of pairs $\frac{n(n - 1)}{2}$:
* $0.0$ indicates an already sorted stack.
* $1.0$ indicates a completely reverse-sorted stack.

### 2. Implemented Sorting Strategies

* **Simple Strategy (`--simple`) — Selection Sort / Bubble Sort — $O(n^2)$**
  * **How it works:** Selection Sort repeatedly locates the minimum element in Stack A, rotates it to the top via the shortest path (`ra` or `rra`), and pushes it to Stack B (`pb`) until Stack A is empty, before pushing all elements back to Stack A (`pa`). Bubble Sort performs adjacent swaps (`sa`) combined with rotations (`ra`) with an early-exit check once sorted.
  * **Justification:** Ideal for tiny inputs ($n \le 5$) or nearly sorted stacks with very low disorder, where the overhead of partitioning or bit-passes is unnecessary.

* **Medium Strategy (`--medium`) — Square-Root Chunk Sort — $O(n\sqrt{n})$**
  * **How it works:** The normalized range is divided into dynamic chunks of size $\lfloor\sqrt{n}\rfloor$. Elements falling into the current window are pushed to Stack B; smaller values within the window are rotated to the bottom of B (`rb`), forming an hourglass/butterfly distribution in Stack B. Once Stack A is empty, elements are pulled back in descending order (`pa`) by rotating the current maximum in B to the top via the shortest direction (`rb` or `rrb`).
  * **Justification:** Achieves strong operation efficiency for medium-sized datasets (such as 100 integers) by grouping elements locally and minimizing search distances during the push-back phase.

* **Complex Strategy (`--complex`) — Binary LSD Radix Sort — $O(n \log n)$**
  * **How it works:** Processes the normalized indices bit by bit from the least significant bit (LSB) to the most significant bit (MSB). For each bit position $i$, elements with bit `0` are pushed to Stack B (`pb`), while elements with bit `1` stay in Stack A (`ra`). After scanning all $n$ elements, Stack B is emptied back onto Stack A (`pa`).
  * **Justification:** Guarantees strict deterministic $O(n \log_2 n)$ time and operation complexity regardless of initial disorder, making it highly reliable and predictable on large inputs (such as 500 integers).

* **Adaptive Strategy (`--adaptive`, Default)**
  * **How it works:** Combines the disorder metric and stack size to dispatch the input to the most appropriate algorithm automatically—avoiding expensive $O(n \log n)$ passes when disorder is negligible, while scaling smoothly to Chunk or Radix Sort as input size and entropy grow.

---

## Resources

### Classic References
* **42 Subject Documentation:** Official `push_swap` project specification.
* **Knuth, Donald E.:** *The Art of Computer Programming, Volume 3: Sorting and Searching* — foundational analysis of inversion counts, selection, and radix sorting.
* **Push Swap — The Least Amount of Moves with Two Stacks (Medium / 42 Community Articles):** Conceptual breakdowns of stack rotations, index normalization, and chunk partitioning.
* **42 Push Swap Visualizer (`o-reo/push_swap_visualizer`):** Used to visually inspect stack states and verify chunk/radix behavior during development.

### How AI Was Used
AI tools (Gemini) were used strictly as a learning and productivity aid in the following areas:
* **Conceptual Clarification:** Comparing time and operation complexities ($O(n^2)$, $O(n\sqrt{n})$, $O(n \log n)$) and discussing inversion-based disorder metrics.
* **Debugging & Edge Cases:** Reviewing edge cases in argument/flag parsing and verifying integer overflow and duplicate-handling scenarios.
* **Documentation:** Structuring and refining the wording of this `README.md` to ensure clarity and compliance with 42 documentation standards.
