# CPP06 — C++ Casts

## Core Concepts

C++ provides four named cast operators that replace the unsafe C-style cast. This module explores three of them and the situations where each is appropriate.

**Key topics:**

- **`static_cast`** — compile-time cast for well-defined conversions between related types (e.g., `int` ↔ `double`, base ↔ derived when the relationship is known). Used for scalar type conversions.
- **`reinterpret_cast`** — reinterprets the bit pattern of a value as a different type (e.g., converting a pointer to an integer and back). Use with caution; bypasses type safety.
- **`dynamic_cast`** — runtime cast that checks the actual type of a polymorphic object. Returns `nullptr` (for pointers) or throws `std::bad_cast` (for references) if the cast is invalid. Requires at least one virtual function in the hierarchy.
- **Run-Time Type Information (RTTI)** — the mechanism behind `dynamic_cast` and `typeid`; lets you query an object's actual type at runtime.
- **Scalar type literals** — recognising and converting between `char`, `int`, `float`, and `double` from a string representation.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **Conversion of scalar types** | `ScalarConverter` class using `static_cast` to convert a string literal to `char`, `int`, `float`, and `double`. Handles special values (`nan`, `inf`, …). |
| ex01 | **Serialization** | `Serializer` class using `reinterpret_cast` to convert a pointer to `uintptr_t` and back without data loss. |
| ex02 | **Identify real type** | `Base`, `A`, `B`, `C` hierarchy; using `dynamic_cast` to identify the concrete type of an object at runtime through a base pointer or reference. |

---

## Building

```bash
cd ex00   # replace with any exercise number
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```
