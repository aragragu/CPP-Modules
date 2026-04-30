# CPP05 — Exceptions

## Core Concepts

This module introduces C++ exception handling: the mechanism for signalling and recovering from error conditions without relying on return codes.

**Key topics:**

- **`throw`** — raising an exception object when an error condition is detected.
- **`try` / `catch`** — wrapping code that may throw in a `try` block, and handling specific exception types in `catch` blocks.
- **Standard exception hierarchy** — deriving custom exception classes from `std::exception` and overriding `what()`.
- **Exception safety** — ensuring that objects remain in a valid state even when an exception is thrown.
- **Abstract base classes revisited** — using an abstract `AForm` to enforce a contract across concrete form types.
- **Factory pattern** — the `Intern` class creates form objects by name, introducing a simple creational pattern.

---

## Exercises

| Exercise | Name | What it practises |
|----------|------|-------------------|
| ex00 | **Bureaucrat** | `Bureaucrat` class with grade validation; custom exceptions (`GradeTooHighException`, `GradeTooLowException`). |
| ex01 | **Form up, maggot!** | `Form` class that checks bureaucrat grade before signing; throwing exceptions on invalid operations. |
| ex02 | **No, you need form 28B, not 28C** | Abstract `AForm` with concrete forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`); `execute()` and its preconditions. |
| ex03 | **At least this is better than C** | `Intern` class that creates form objects by string name; reducing switch/if chains with a lookup approach. |

---

## Building

```bash
cd ex00   # replace with any exercise number
make          # compile
make re       # recompile from scratch
make clean    # remove .o files
make fclean   # remove .o files + binary
```
