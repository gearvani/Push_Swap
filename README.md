This project has been created as part of the 42 curriculum by gearvani.
push_swap
Description

push_swap is an algorithmic project from the 42 curriculum.
The goal is to sort a stack of unique integers in ascending order using only two stacks (A and B) and a restricted set of 11 operations, while producing the shortest possible sequence of instructions.

You receive a list of integers as arguments. Stack A starts with these values (first argument = top of the stack). Stack B is empty. Your program must output the sequence of operations that will leave Stack A sorted in ascending order and Stack B empty.

The project is graded primarily on the number of operations used:

    3 numbers → ≤ 3 operations
    5 numbers → ≤ 12 operations
    100 numbers → < 700 operations (full marks)
    500 numbers → < 5500 operations (full marks)

It trains students in algorithm design, complexity analysis, data structure manipulation (stacks), and rigorous optimization under strict constraints.
Allowed operations
Operation	Description
sa	Swap the first two elements of stack A
sb	Swap the first two elements of stack B
ss	sa + sb at the same time
pa	Push the top element of B onto A
pb	Push the top element of A onto B
ra	Rotate A (first element becomes last)
rb	Rotate B (first element becomes last)
rr	ra + rb at the same time
rra	Reverse rotate A (last element becomes first)
rrb	Reverse rotate B (last element becomes first)
rrr	rra + rrb at the same time

Instructions
Compilation

make

This produces the push_swap executable.
(If you implemented the bonus checker:)

Usage

./push_swap <numbers...>
# Example
./push_swap 4 67 3 87 23

You can also pass the numbers as a single quoted string (depending on your shell and parsing):

./push_swap "4 67 3 87 23"

To count the number of operations:

./push_swap 4 67 3 87 23 | wc -l

To verify correctness with the official checker (or your own bonus checker):

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

Cleaning

make clean      # remove object files
make fclean     # remove object files + binary
make re         # fclean + make

Error handling

The program prints Error on stderr and exits if:

    Any argument is not a valid integer
    There are duplicate numbers
    The numbers exceed INT_MIN / INT_MAX
    There are no arguments (or only empty input)

Algorithm

The implementation uses different strategies depending on the size of the input, prioritising both correctness and minimal operation count.
Small sizes (≤ 5)

Hard-coded optimal solutions:

    2 elements: one sa if needed.
    3 elements: decision tree covering all 6 permutations (max 2 operations).
    4–5 elements: push a few elements to B, sort the remaining 3, then insert the others back with optimal rotations.

These cases are solved with the absolute minimum number of moves required by the subject.
Larger sizes – Cost-based greedy algorithm (Turk algorithm)

For inputs larger than 5 the program uses a greedy cost-based approach commonly known as the Turk algorithm.
High-level overview

    Index normalisation
    Map every value to its rank in the sorted sequence (0 … n-1). This simplifies all subsequent comparisons.

    Push phase (A → B)
        Push the first two elements to B without cost calculation (to establish a reference).
        While more than 3 elements remain in A:
            For every element still in A, compute the cost of moving it to its correct position in B (so that B stays sorted in descending order).
            Cost considers the four possible rotation combinations:
                ra + rb
                rra + rrb
                ra + rrb
                rra + rb
            Also take advantage of simultaneous rotations (rr / rrr) when both stacks need to move in the same direction.
            Always select and execute the cheapest move.
        Keep only the last three elements in A.

    Sort the remaining three
    Use the hard-coded 3-element sorter.

    Push-back phase (B → A)
        For every element in B, calculate the cheapest way to bring it to the top of B and to bring its target position (the correct insertion point) to the top of A.
        Again use the four rotation combinations + simultaneous moves.
        Push the element with pa.
        Repeat until B is empty.

    Final rotation
    Rotate A so that the smallest element is on top.

Why this algorithm?

    Greedy local optimality with global good results: at every step the cheapest move is chosen, which empirically yields very low total operation counts.
    Exploits simultaneous operations (rr / rrr / ss) that a pure radix or chunk approach often under-uses.
    Predictable performance:
        100 numbers → typically 500–650 operations
        500 numbers → typically 4500–5300 operations
        (well under the full-mark thresholds)
    Flexible: the same cost model works for both the push-to-B and push-to-A phases.
    Easy to reason about and debug compared with more complex LIS or multi-chunk strategies.

Alternative algorithms considered (and reasons they were not chosen as the primary method):

    Radix sort (binary LSD): simple and O(n × bits), but usually produces more operations than the Turk method for the 100/500 benchmarks.
    Chunk / “butterfly” sorting: good results possible, but requires careful tuning of chunk size and still tends to be slightly less efficient than a well-implemented cost model.
    Longest Increasing Subsequence (LIS): can leave a long already-sorted subsequence in A, but the bookkeeping is heavier and the gain is often marginal for the required sizes.

Resources
Official / classic references

    42 subject PDF (push_swap)
    Push Swap – The Least Amount of Moves with Two Stacks (excellent conceptual explanation)
    Visualisers:
        https://github.com/o-reo/push_swap_visualizer
        https://github.com/nort3x/push-swap-gui
    Algorithm discussions and benchmarks on the 42 Discord / Slack / Intra forum

How AI was used

AI (Grok / ChatGPT-style assistants) was used in the following limited ways:

    Clarifying edge cases of the cost calculation (especially simultaneous rotations and target finding).
    Generating test cases and helping write small unit-test helpers.
    Reviewing README wording and structure to match the 42 Chapter VII requirements.
    Explaining the differences between Turk, radix and chunk approaches so an informed choice could be made.

No AI-generated code was copied into the final submission. All algorithms, data structures and Norm-compliant C code were written and debugged by hand.
