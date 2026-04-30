# CPP02 — Ad-hoc Polymorphism, Operator Overloading & Fixed-Point Numbers

## Core Concepts

This module introduces the Orthodox Canonical Class Form and operator overloading, using a fixed-point number type as a running example.

**Key topics:**

- **Orthodox Canonical Class Form (OCCF)** — the four special member functions every class should define:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor
- **Operator overloading** — implementing `+`, `-`, `*`, `/`, comparison operators (`<`, `>`, `==`, …), and stream insertion (`<<`) for custom types.
- **Increment / decrement operators** — pre-increment (`++x`) vs. post-increment (`x++`).
- **Fixed-point arithmetic** — representing fractional numbers without floating-point hardware, using an integer with a fixed number of fractional bits.
- **`static` member functions** — class-level utilities such as `min()` and `max()`.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **My First Class in Orthodox Canonical Form** | Implementing OCCF; basic fixed-point class with integer storage. |
| ex01 | **Towards a more useful fixed-point number class** | Converting between `int`/`float` and fixed-point; overloading `<<`. |
| ex02 | **Now we're talking** | Full operator overloading (arithmetic, comparison, increment/decrement); `static min`/`max`. |

---

## Building

```bash
cd ex00   # replace with any exercise number
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```
