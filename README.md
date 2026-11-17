# CPP Module 02

The third module of the 42 C++ series, focused on class design and operator overloading.

It covers the Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator and destructor), ad-hoc polymorphism through operator overloading, and the implementation of a fixed-point number class, all compiled with `-Wall -Wextra -Werror -std=c++98`.

> Note: This module is graded with the C++98 standard, and every class must follow the Orthodox Canonical Form. The exercises build on each other, so the `Fixed` class grows from one exercise to the next.
---

<div align="center">
    <br>
    <a href="https://github.com/tdanielsousa/42_School/blob/main/Subjects/cpp02.pdf" target="_blank">
        <img src="https://img.shields.io/badge/View%20Subject-PDF-red?style=for-the-badge&logo=adobe-acrobat-reader&logoColor=white" alt="Subject PDF" height="40">
    </a>
    <p><i>Click on the button above to see the subject's pdf.</i></p>

</div>

---

##  Module Architecture & Concepts

Each exercise lives in its own folder with its own `Makefile`, and each one extends the `Fixed` class from the previous exercise.

### Technical Specifications
* **Language:** C++98.
* **Compiler:** `c++` with `-Wall -Wextra -Werror -std=c++98`.
* **Fixed-Point Representation:** An integer value stores the number, with a **static constant** number of fractional bits (always `8`).
* **Orthodox Canonical Form:** Default constructor, copy constructor, copy assignment operator and destructor in every class.
* **Operator Overloading:** Comparison, arithmetic, increment/decrement and stream insertion operators.
* **Restrictions:** No `printf`, `malloc` or `free`, and no STL containers or algorithms.

---

##  Exercises

### ex00: My First Class in Orthodox Canonical Form
Creates the base `Fixed` class that represents a fixed-point number.

* **Private members:** An integer holding the fixed-point value and a static constant integer for the number of fractional bits (always `8`).
* **Orthodox Canonical Form:** Default constructor (value initialized to `0`), copy constructor, copy assignment operator and destructor.
* **Member functions:** `getRawBits()` returns the raw value and `setRawBits()` sets it.
* **Output:** Each special member function prints a message, which shows when it is called.
* **Concepts:** Orthodox Canonical Form, copy vs assignment, object lifetime.

### ex01: Towards a more useful fixed-point number class
Adds conversions so the class can be built from and turned into regular numbers.

* **New constructors:** One from a constant `int` and one from a constant `float`, both converting the value to fixed-point.
* **Conversions:** `toFloat()` returns the value as a float and `toInt()` returns it as an integer.
* **Stream operator:** An overload of `operator<<` that inserts the float representation into the output stream.
* **Concepts:** Bit shifting, `roundf`, fixed-point vs floating-point, non-member operator overloads.

### ex02: Now we're talking
Turns `Fixed` into a number type that can be used in expressions.

* **Comparison operators:** `>`, `<`, `>=`, `<=`, `==` and `!=`.
* **Arithmetic operators:** `+`, `-`, `*` and `/`.
* **Increment/decrement:** The four variants (pre and post `++` and `--`), which change the value by the smallest representable `epsilon`, so that `1 + epsilon > 1`.
* **Static member functions:** Overloaded `min()` and `max()`, taking two references to either `Fixed` or `const Fixed`, and returning the smallest or largest one.
* **Concepts:** Operator overloading, pre vs post increment, overloaded static functions, `const` correctness.

### ex03: BSP
Uses the `Fixed` class to implement a geometry function.

* **`Point` class:** Orthodox Canonical Form, with constant `Fixed` attributes `x` and `y`, a constructor taking two floats and the usual special member functions.
* **`bsp(a, b, c, point)`:** Returns `true` if the point is **inside** the triangle `abc`, and `false` otherwise. A point on a vertex or an edge counts as outside.
* **Concepts:** Binary space partitioning, triangle area / sign test, `const` attributes and their effect on assignment.

---

## Installation & Run Steps

### 1. System Prerequisites
Make sure you have a C++ compiler and `make` installed. On Debian/Ubuntu:

    sudo apt-get install make clang

### 2. Compile an Exercise
Go into the folder of the exercise and run `make`:

    cd ex02
    make

### 3. Run It
Each exercise generates its own executable:

    ./fixed
    ./fixed
    ./fixed
    ./bsp

---

## Testing

Each exercise has a `main` based on the one from the subject, which is the first thing to check:

    ./fixed

To check for leaks and invalid accesses, use `valgrind`:

    valgrind --leak-check=full ./fixed

Ex03 is best checked by hand with points inside, outside, on an edge and on a vertex of the triangle.

---

## References

* **[C++ reference](https://en.cppreference.com/)**
* **[Fixed-point arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)**
* **[Orthodox Canonical Form](https://www.learncpp.com/)**

---

## AI Usage Declaration

AI tools were used to assist with:

* **Documentation Support:** Structuring and writing this README file.

---
