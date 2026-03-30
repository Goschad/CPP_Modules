# CPP Modules

A series of 10 modules from 42 School introducing **C++ programming** from the ground up, covering the core concepts of the language and object-oriented programming.

All modules are compiled with `-std=c++98`.

---

## Scores

| Module | Score |
|---|---|
| CPP 00 | 80 / 100 |
| CPP 01 | 80 / 100 |
| CPP 02 | 80 / 100 |
| CPP 03 | 80 / 100 |
| CPP 04 | 80 / 100 |
| CPP 05 | 100 / 100 |
| CPP 06 | 100 / 100 |
| CPP 07 | 100 / 100 |
| CPP 08 | 100 / 100 |
| CPP 09 | 100 / 100 |

---

## Modules Overview

### CPP 00 — Introduction to C++
Namespaces, classes, member functions, `stdio` streams, initialization lists, `static` and `const` keywords.

### CPP 01 — Memory Allocation, References, Pointers to Members
Heap vs stack allocation with `new` / `delete`, references, pointers to class members, file streams.

### CPP 02 — Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Form
The Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, destructor), operator overloading, fixed-point numbers.

### CPP 03 — Inheritance
Class inheritance, access specifiers, constructor chaining, diamond problem and virtual inheritance.

### CPP 04 — Subtype Polymorphism, Abstract Classes, Interfaces
Virtual functions, pure virtual functions, abstract classes, interfaces, deep copy with polymorphic objects.

### CPP 05 — Repetition and Exceptions
`try` / `catch` / `throw`, custom exception classes, nested classes, bureaucratic hierarchy exercise.

### CPP 06 — C++ Casts
`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`, serialization and type identification.

### CPP 07 — Templates
Function templates, class templates, template specialization, generic algorithms.

### CPP 08 — Templated Containers, Iterators, Algorithms
STL containers (`vector`, `list`, `map`, `stack`), iterators, STL algorithms, `<algorithm>` header.

### CPP 09 — STL
Advanced STL usage: `map`, `stack`, `vector` applied to real algorithmic problems (Bitcoin exchange, RPN calculator, PmergeMe sort).

---

## Usage

Each module contains one or more exercises. Navigate to the exercise directory and compile with:

```bash
make
```

Then run the resulting binary:

```bash
./program_name
```

---

## Compilation Flags

All projects are compiled with:

```
c++ -Wall -Wextra -Werror -std=c++98
```