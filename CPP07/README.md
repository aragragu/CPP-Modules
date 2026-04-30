# CPP07 — C++ Templates

## Core Concepts

Templates allow writing generic, type-independent code that the compiler instantiates for each concrete type used. This module covers both function templates and class templates.

**Key topics:**

- **Function templates** — writing a single function definition that works for any type (`template <typename T>`); the compiler generates a specialisation for each type it is called with.
- **Template specialisation** — providing a custom implementation for a specific type when the generic version is not appropriate.
- **Template with function pointers** — passing a function as a parameter to a template function, enabling algorithms that operate on arbitrary arrays with a user-supplied operation.
- **Class templates** — parameterising an entire class by one or more types; separating declaration (`.hpp`) from implementation (`.tpp` or inline in the header).
- **Template member functions** — methods of a class template that are themselves templated.
- **Bounds checking** — adding runtime validation in a templated container to guard against out-of-range access.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **Start with a few functions** | Function templates: `swap`, `min`, and `max` that work on any comparable type. |
| ex01 | **Iter** | `iter` function template that applies a function to every element of an array, regardless of type or size. |
| ex02 | **Array** | Class template `Array<T>`: dynamic array with bounds-checked access via `operator[]`, copy semantics, and a `size()` method. |

---

## Building

```bash
cd ex00   # replace with any exercise number
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```
