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
