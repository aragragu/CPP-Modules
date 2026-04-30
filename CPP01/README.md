# CPP01 — Memory Allocation, References & Pointers

## Core Concepts

This module digs into how C++ manages memory and how references differ from pointers. It also introduces pointers to member functions and file I/O.

**Key topics:**

- **Heap vs. stack allocation** — using `new` and `delete` (and `new[]` / `delete[]`) to allocate objects at runtime, versus automatic stack allocation.
- **Pointers to objects** — storing and manipulating objects through raw pointers.
- **References** — aliases to existing variables; compared and contrasted with pointers (no null, no reassignment).
- **References inside classes** — when to use a reference member vs. a pointer member.
- **File I/O** — reading and writing files with `std::ifstream` / `std::ofstream`.
- **Pointers to member functions** — storing and calling class methods through function pointers.
- **`switch` statement** — using `switch` as a dispatch mechanism.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **BraiiiiiiinnnzzzZ** | Stack vs. heap object creation; `new` / `delete`. |
| ex01 | **Moar brainz!** | Allocating arrays of objects with `new[]` / `delete[]`. |
| ex02 | **HI THIS IS BRAIN** | Pointers vs. references — printing addresses and values. |
| ex03 | **Unnecessary violence** | Reference member vs. pointer member inside a class. |
| ex04 | **Sed is for losers** | File reading/writing; string replacement without `std::string::replace`. |
| ex05 | **Harl 2.0** | Pointers to member functions as a dispatch table. |
| ex06 | **Harl filter** | `switch` statement used as a level-filter dispatcher. |

---

## Building

```bash
cd ex00   # replace with any exercise number
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```
