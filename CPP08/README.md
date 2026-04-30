# CPP08 — Templated Containers, Iterators & Algorithms

## Core Concepts

This module applies templates to work with the C++ Standard Template Library (STL): containers that store data, iterators that traverse them, and algorithms that operate on them generically.

**Key topics:**

- **STL containers** — `std::vector`, `std::list`, `std::deque`, `std::stack`, and others; understanding when to choose each one.
- **Iterators** — the abstraction that decouples algorithms from containers; iterator categories (input, forward, bidirectional, random-access).
- **STL algorithms** — generic functions in `<algorithm>` such as `std::find`, `std::sort`, `std::distance`, `std::min_element`, `std::max_element`.
- **Template function with container parameter** — writing a function that accepts any container type via iterators or a template parameter.
- **Container adapters** — `std::stack` wraps an underlying container and restricts access to LIFO operations; extending it to expose iterators.
- **Range insertion** — using `insert` with a pair of iterators to fill a container from another range efficiently.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **Easy find** | `easyfind` function template: searches any sequence container for a value using `std::find`; throws an exception if not found. |
| ex01 | **Span** | `Span` class: stores up to N integers; `addNumber`, `addRange` (with iterators), `shortestSpan`, `longestSpan` using STL algorithms. |
| ex02 | **Mutated abomination** | `MutantStack<T>` inherits `std::stack<T>` and adds iterator support by exposing `begin()`/`end()` from the underlying container. |

---

## Building

```bash
cd ex00   # replace with any exercise number
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```
