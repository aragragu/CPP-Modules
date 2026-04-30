# CPP04 — Subtype Polymorphism, Abstract Classes & Interfaces

## Core Concepts

This module explores runtime polymorphism — the ability to call the correct method on an object through a base-class pointer or reference — along with abstract classes and interface-like design in C++.

**Key topics:**

- **Virtual functions** — declaring a function `virtual` in the base class so that the derived-class override is called at runtime (dynamic dispatch).
- **Virtual destructor** — why a base class destructor must be `virtual` when deleting through a base pointer, to ensure proper cleanup.
- **Deep copy** — correctly implementing copy constructor and assignment operator when a class owns heap-allocated resources (vs. shallow copy).
- **Pure virtual functions** — declaring a function as `= 0` to make a class abstract; abstract classes cannot be instantiated.
- **Interfaces** — a class that contains only pure virtual functions acts as an interface, defining a contract that concrete classes must fulfill.
- **Subtype polymorphism** — treating different concrete objects uniformly through a common base-class pointer.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **Polymorphism** | Virtual functions, virtual destructor; contrasting `Animal`/`Dog`/`Cat` with non-virtual `WrongAnimal`/`WrongCat`. |
| ex01 | **I don't want to set the world on fire** | `Brain` class owned by `Dog` and `Cat`; deep copy vs. shallow copy. |
| ex02 | **Abstract class** | Making `Animal` abstract with a pure virtual function; preventing direct instantiation. |
| ex03 | **Interface & recap** | `ICharacter` and `IMateriaSource` pure-virtual interfaces; `AMateria` abstract base; concrete implementations. |

---

## Building

```bash
cd ex00   # replace with any exercise number
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```
