# CPP00 — Introduction to C++

## Core Concepts

This module is the entry point to C++ after C. It covers the fundamental building blocks of object-oriented programming in C++ while staying within the C++98 standard.

**Key topics:**

- **Namespaces** — grouping related identifiers to avoid name collisions (`std::`, custom namespaces).
- **Classes and objects** — declaring classes, creating instances, separating declaration (`.hpp`) from implementation (`.cpp`).
- **Member functions** — defining methods inside a class, understanding `this` pointer.
- **Access specifiers** — `public`, `private`, `protected` and why encapsulation matters.
- **Initialization lists** — initializing member variables in constructors efficiently.
- **`static` members** — class-level data and functions shared across all instances.
- **`const` correctness** — marking functions and variables that must not modify state.
- **Standard I/O streams** — using `std::cout`, `std::cin`, `std::cerr` instead of `printf`/`scanf`.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **Megaphone** | Basic string manipulation and `std::cout`; converting input to uppercase. |
| ex01 | **My Awesome PhoneBook** | Designing classes (`PhoneBook`, `Contact`), member functions, user input with `std::cin`, formatting output. |

---

## Building

```bash
cd ex00   # or ex01
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```
