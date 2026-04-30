# CPP09 — STL in Practice

## Core Concepts

The final module puts the STL to work on three non-trivial problems, each requiring a specific container and a careful algorithmic approach.

**Key topics:**

- **`std::map`** — associative container that stores key-value pairs sorted by key; fast lookup by key (`O(log n)`); used for date-indexed data.
- **`std::stack`** — LIFO adapter; ideal for evaluating postfix (Reverse Polish Notation) expressions.
- **`std::deque` and `std::vector`** — sequence containers with different performance trade-offs; central to the Ford-Johnson merge-insert sort algorithm.
- **File parsing** — reading structured text files, splitting lines, validating format, and converting strings to numeric values.
- **Error handling** — reporting malformed input clearly without crashing.
- **Algorithmic complexity awareness** — choosing the right container to meet performance requirements and understanding `O(n log n)` sorting.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **Bitcoin Exchange** | Reads a CSV price database into `std::map<date, rate>`; evaluates an input file of (date, value) pairs against the closest earlier date in the map. |
| ex01 | **Reverse Polish Notation (RPN)** | Evaluates a postfix arithmetic expression using `std::stack<int>`; handles `+`, `-`, `*`, `/` and error cases. |
| ex02 | **PmergeMe** | Sorts a sequence of positive integers using the Ford-Johnson merge-insert algorithm, implemented twice — once with `std::vector` and once with `std::deque` — and reports execution time for each. |

---

## Building

```bash
cd ex00   # replace with any exercise number
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```

### Example usage

```bash
# ex00 — Bitcoin Exchange
cd ex00
make
./btc input_small.txt

# ex01 — RPN
cd ex01
make
./RPN "3 4 + 2 * 7 /"

# ex02 — PmergeMe
cd ex02
make
./PmergeMe 3 5 9 7 4 1 8 6 2
```
