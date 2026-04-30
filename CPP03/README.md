# CPP03 — Inheritance

## Core Concepts

This module covers single and multiple inheritance in C++, using a chain of robot-combat classes to illustrate how derived classes extend base classes.

**Key topics:**

- **Single inheritance** — a derived class inherits attributes and methods from one base class; using `public` inheritance.
- **Constructor/destructor chaining** — how base-class constructors are called from derived constructors, and how destructors unwind in reverse order.
- **Method overriding** — redefining a base-class function in a derived class.
- **Access control in inheritance** — which base members are accessible in a derived class depending on `public` / `protected` / `private` inheritance.
- **Multiple inheritance** — a class that derives from more than one base class simultaneously.
- **Diamond problem** — when two base classes share a common ancestor, causing ambiguity; solved with `virtual` base classes.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **ClapTrap** | Base class design: constructors, destructor, basic member functions. |
| ex01 | **Serena, my love** | `ScavTrap` inherits `ClapTrap`; constructor/destructor chaining, method override. |
| ex02 | **Repetitive work** | `FragTrap` also inherits `ClapTrap`; parallel single-inheritance hierarchy. |
| ex03 | **Now it's weird!** | `DiamondTrap` inherits both `ScavTrap` and `FragTrap`; virtual base classes to resolve the diamond problem. |

---

## Building

```bash
cd ex00   # replace with any exercise number
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```
