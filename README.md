# 42 C++ Modules

A progression through 10 C++ modules (CPP00–CPP09) from the 42 school curriculum. Each module introduces key C++ concepts, building from basic object-oriented programming all the way to the Standard Template Library (STL).

---

## Repository Structure

```
CPP-Modules/
├── CPP00/          # Namespaces, classes, basic I/O
├── CPP01/          # Memory allocation, references, pointers
├── CPP02/          # Operator overloading, Orthodox Canonical Form
├── CPP03/          # Inheritance
├── CPP04/          # Polymorphism, abstract classes, interfaces
├── CPP05/          # Exceptions
├── CPP06/          # C++ casts
├── CPP07/          # Templates
├── CPP08/          # Templated containers, iterators, algorithms
└── CPP09/          # STL in practice
```

Each module folder contains numbered exercise sub-folders (`ex00`, `ex01`, …), each with its own `Makefile` and source files.

---

## Building & Running Exercises

Navigate to any exercise directory and use the following `make` targets:

```bash
cd CPP0X/exYY

make          # Compile the exercise (produces the binary)
make re       # Force full recompilation (fclean + all)
make clean    # Remove compiled object files (.o)
make fclean   # Remove object files and the compiled binary
```

**Example — build and run CPP00 ex00:**

```bash
cd CPP00/ex00
make
./megaphone "hello world"
```

> All exercises are compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

---

## Module Overview

| Module | Core Concepts |
|--------|--------------|
| [CPP00](./CPP00/README.md) | Namespaces, classes, member functions, basic I/O |
| [CPP01](./CPP01/README.md) | Memory allocation (`new`/`delete`), pointers, references |
| [CPP02](./CPP02/README.md) | Operator overloading, Orthodox Canonical Form, fixed-point numbers |
| [CPP03](./CPP03/README.md) | Inheritance (single & multiple, diamond problem) |
| [CPP04](./CPP04/README.md) | Subtype polymorphism, abstract classes, interfaces |
| [CPP05](./CPP05/README.md) | Exception handling (`try`/`catch`/`throw`) |
| [CPP06](./CPP06/README.md) | C++ casts (`static_cast`, `reinterpret_cast`, `dynamic_cast`) |
| [CPP07](./CPP07/README.md) | Function and class templates |
| [CPP08](./CPP08/README.md) | STL containers, iterators, algorithms |
| [CPP09](./CPP09/README.md) | STL in practice (map, stack, deque, Ford-Johnson sort) |

---

## Navigating the Exercises

Each module's `README.md` lists the exercises and the concept each one focuses on. A typical workflow:

1. Read the module `README.md` for context.
2. Enter the exercise directory (`cd CPP0X/exYY`).
3. Study the source files, then `make` and run the binary.
4. Use `make fclean` before moving to the next exercise.
