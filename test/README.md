 Fundamental Data Types 
 Felix Okoronkwo 20/10/23 

 Introduction to fundumental data types  
==========================================
When a proram executes, specific memory is assigned to the program from the ram to take care of
data handling, storage and manipulation during the lifetime of the program, this data to be imposed on the ram
for either storage, manipulation or what-not are stored at memory addresses of the ram.

The size of data stored span from the memory address the data was allocated to and end at the memory address arithmetically equal
to the displacement sum, of the size of the data to be handeled, from the beginning memory address the data was assigned to.

A single memory address holds one byte of data

byte is a group of bits that are operated on singularly, modern standard byte consists of bits

bits or binary storage are smallest piece of memory storage, they can only store either 1 or 0, you can think of them as
on or off switches.

List of primitive data-types
----------------------------
| Types                                      |    Category    |                 Meaning                 | Example |
|--------------------------------------------|----------------|-----------------------------------------|---------|
| float, double, long double                 | Floating point |      a number with fractional part      | 3.14159 |
| bool                                       |    Boolean     |              true or false              |  true   |
| char, wchar_t, char8_t, char16_t, char32_t |   character    |        single character of text         |   'c'   |
| short int, int, long int, long long int    |    integer     | postive and negative numbers incluing 0 |   64    |
| std::nullptr_t (c++11)                     |  Null pointer  |             a null pointer              | nullptr |
| void                                       |      Void      |                 no type                 |   n/a   |

The _t suffix
-------------
the `_t` suffix is used to denote that a data-type, its a popular nomenclature used in modern data-types
its not a consistently applied rule of thumb but its worth noting.


 Void 
=======
Void is an imcomplete type that has no datatype

Incomplete type
---------------
Incomplete types are dataypes that have been decalred but not defined, the compiler knows of the existence of such types
but since its not defined not enough information is there for the compiler to know what amount of memory to allocate for
an object of that type.

Incomplete types cannot be instatiated:
```cpp
  void value;     // wont work because void is an incomplete datatype.
```

Void use cases:
- for defining functions that do not need to return anything
- for defining functions that do not need an argument in C/C++ (deprecated in c++)

 Object sizes and the sizeof operator 
=======================================
To generalize an object with `n` bits can hold up to `2 exponent n` unique values

sizeof operator
---------------
- its a unirary operator that takes in a datatype and returns the size of the dataype in in bytes
- Sizeof opertor do not work well with incomplete types and results in compilation error
- you can also use it on varible names
- it does not include dynamically alloctes memory used by an object

 Signed Numbers 
=================
An integer is an integral type that can represent a poitive number, negative number and the nuber zero.

types of integrs:

| Type          | Minimum size | Note                                     |
|---------------|--------------|------------------------------------------|
| short int     | 16 bits      |                                          |
| int           | 16 bits      | typically 32 bits in modern architecture |
| long int      | 32 bits      |                                          |
| long long int | 64 bits      |                                          |

the key diff, between varying integers is that they have varying sizes

Note:
- C++ only guarantees that a dataypes will have a minimum size, not that they will have a specific size
- bool and char are considered to be integral datatypes becuase they store their values as integers


signed integers
---------------
- By default integers are signed meaning they, store the signed state og their numbers,
 so they can either represent positive or negative numbers and even the number zero.

- unsigned intgers are integers thay are only capable of storing non-negative numbers

- a single bit known as the sign bit is used tp store the sign of a number
  non-sign bits are known as magnitude bits.

ways to define signed integers:
```cpp
  short s;      // prefer "short" instead of "short int"
  int i;
  long l;       // prefer "long" instead of "long int"
  long long ll; // prefer "long long" instead of "long long int"
```

- you can also use the signed keyword to depict that a data-type is signed, but the keyword should'nt
  be used as it is redundant.
- as we have learnt the varible with `n bits` can hold `2^n` bits. but the specfic values it can hold is known
  as its range, its determined by 2 factors its size in bits and whether it is sized or not.
  therefore the range of an int is `-2^31 < 0 < 2^31 - 1`, because signed int holds both positive and negative
  numbers, and one bit holds the signed or unsigned propert of the int
- `n bit` signed datatyped posses a range of `-2^(n-1) < 0 < ( 2^(n-1) -1 )`
- when a value outside the range of a type is assigned to variable of that type `Overflow` will take place
- `Overflows` kead to undefined behaviours.
- when an arithmetic operation attempts to create a value oustide the range of the type its operting on, `integer` or
  `arithmetic overflow` takes place.
- Integer division leaves its fractional part from its result, as expected becus integers can only hold a specific range
  anything other than that can be morphed into something that it can accept as a value.

 Unsigned integers, and why to avoid them 
===========================================
Unsigned Int
------------
This datatype can only hold non-negative numbers, to define an unsigned integer we use the unsigned keyword.

```cpp
  unsigned short us;
  unsigned int ui;
  unsigned long ul;
  unsigned long long ull;
```

- unsigned int can hold twice the positive values that a normal signed int can

modulo wrapping
---------------
When value greater than an `unsigned int` type is tried to be stored in a variable of that type, modulo wrapping occurs
how modulo wrapping works is that it takes the largest number that type can store adds 1 to it and then the result
is used to divide the overflowing value, whatever the remainder is, is stored in the variable.

```cpp
  #include <iostream>

  int main()
  {
    unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    return 0;
  }
```

negative modulo wrap-around
---------------------------
when a negative number is assigned to an unsigned int the value wraps iteslf to the largest value of that int
and then stores the absolute difference between the negative number and the largest number that that type
can hold

It’s possible to wrap around the other direction as well. 0 is representable in a 2-byte unsigned integer,
so that’s fine. -1 is not representable, so it wraps around to the top of the range, producing the value 65535.
-2 wraps around to 65534. And so forth.

NOte
----
Many bugs in the video game industry has happend due to warp around behavuiour with unsigned integers

Controversy over signed integers
--------------------------------
many develping companies including google believe that unsigned int should not be due to how easily compared to signed
integers to overflow, since overflowing can easily happen when the value goes under 0, unlike signed in which overflowing
happen at a largely considerable range far away from 0 both on the negative and positive direction.

When to use unsigned numbers
----------------------------
There are still a few cases in C++ where it’s okay / necessary to use unsigned numbers.

First, unsigned numbers are preferred when dealing with bit manipulation (covered in chapter O -- that’s a capital
‘o’, not a ‘0’).
They are also useful when well-defined wrap-around behavior is required (useful in some algorithms like encryption and random number generation).

Second, use of unsigned numbers is still unavoidable in some cases, mainly those having to do with array indexing.
We’ll talk more about this in the lessons on arrays and array indexing.

Also note that if you’re developing for an embedded system (e.g. an Arduino) or some other
processor/memory limited context, use of unsigned numbers is more common and accepted (and in some cases, unavoidable)
for performance reasons.

 Fixed-width integers and size_t 
==================================
The dynamic nature of integers size date back in C, when computers where slow and performance was an issue, C left
the size of integers open so that the compliler implementers could choose what size was efficient for the architecture
the program would run on.

Fixed width integers
--------------------
To address the issues of dynamic integers sizes on differrn machines, C99 came up with `fixed width intgers` in the
`<cstdint>` header, that is guaranteed to be the same size on any architecture.

```cpp
  #include <cstdint>
  #include <iostream>

  int main()
  {
    std::int16_t i{ 5 };
    std::cout << i << "\n";
    return 0;
  }
```

Downsides of fixed-width integers:
----------------------------------
- they are not guaranteed to be defined on all architectures. they only exits on systems with theri fundamental type
  matchin their types and with similar binary representations.
  your program will fail to compile on any architecture that does not support a fixed width type integer your
  program is using.
- A fixed width integer maybe slower than some wider types in on some architectures, your program might be using a fixed
  width type of 32 bits when the case is that your CPU processes 64 bit integers faster than 32 bits, but this also
  might not be a threat to efficiency because, most programs are memory constrained meaning that though your CPU might
  be faster in processing a wider sized integer type, sometimes larger memory footorints quickly slow
  your computer down faster than your CPU processes the wider, more memory consuming, sized integer types.

fast and least integers
-----------------------
the `<cstdint>` headers also contain 2 more variants of integral types

1) least type: this are intgeral types with at least the specified number of bits needed
2) fastest type: this are intgeral types that contain at least the number of bits needed for a computation
  that will be processed faster considering your systems architecture.

size_t
------
This is an unsigned integral type that is used mainly for counting or determining the size of objects in bytes.

Notes:
- `std::size_t` is returned by the `sizeof()` operator not an `int`
- the `sizeof(std::size_t)` compiled on a system tells the largest size of bytes that your system can process at most.
  which is usually the number of bits your systems architecture was designed on.
- it belongs to the `<cstddef>` header.


 Introduction to scientific notation 
======================================
in cpp precise numbers can be expressed in scientific notation using the `e` symbol with numbers,
where digits before the `e` sign is the `significand` while digits after it is the `exponent`.

```cpp
  double positive_sci_notation { 3.142e10 };             // equivalent to 3.142 * 10^10
  double negative_sci_notation { 3.142e-10 };            // equivalent to 3.142 * 10^-10
```


 Floating points numbers 
==========================
Flaoting point numbers are numbers that can hold fractional part, they are always signed, they are of 3 types
`float, double and long double`.

| Category       | type        | minimum size | typical size      |
|----------------|-------------|--------------|-------------------|
| floating point | float       | 4 bytes      | 4 bytes           |
|                | double      | 8 bytes      | 8 bytes           |
|                | long double | 8 bytes      | 8, 12 or 16 bytes |

Note:
- when making floating point literals include at least on decimal place even if the decimal place is `.0`
  this helps the compiler understand that this number is not an integer but a float.
- by default flaoting point literals default to doubles, using the `f` suffix to the literal makes sure the number
  is stored as a `float`

```cpp
 int x {5};                       // integer
 double y {5.0};                  // float
 float z {5.0f};                  // f suffix is used to declare as a float
```

printing floating numbers
-------------------------
- `std::cout` foes not print the fractional part of a float is the fractional part is `.0`
- if a float number is a precice number os justifyable quantity, it would be printed in scientific notation.

floating point range
--------------------
blah blah blah, did'nt read this section

Floating point precision
------------------------
the precision of a floating number is the number of signifivan t figures it can represent without information loss.

when outputing floating points `std::cout` has a precision value of 6 , that means prinying any float with any
significant number greater than 6 digits the remaining digiys would be truncated.

the precision value of `std::cout` can be modifyed from its default using `std::setprecision()`
from the `<iomanip>` header.

```cpp
  #include <iomanip>
  #include <iostream>

  int main()
  {
    std::cout << std::setprecision(15);
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

    return 0;
  }
```

floats have less precison than doubles.

Floating point range
--------------------
check here [[www.learncpp.com/cpp-tutorial/floating-point-numbers]]
Flaoting point range section

output manipulators
-------------------
They alter how data is output, they are defined in the `<iomanip>` header, the `std::setprecision()` function
sets the precison intgeral of the `std::cout` instance and is an output manipulator.

Note:
- output manipulators and input manipulators are sticky, meaning if you set they they remain set.
- favour doubles to floats if space is at premium, as the lack of precision in float can lead to inacuracies.

Rounding errors make floating point comparisons tricky
------------------------------------------------------
floating point numbers result to arithmetic errors due to the differences in hpw we percieve numbers and how binary works
for example if we wanted to represent the number `0,1`, the fraction of `1/10` figuratively its easy, its `0.1` but in
binary the `0.1` is represented as the sequence `0.00011001100110011...` that goes on to infinity and due to the limitaions of
the floats and doubles that only ensure a specific digits of presicion, rounding ups occur that can lead larger margins of
error as layers of arithmetic operations increases.

since doubles ensure 18 digits of precision, assigning 0.1 to a double and printing the result with `std::setprecision(17)`, thats
1 digit above the the guaranteed digits of precision a double posses, running the code below:

```cpp
 #include <iomanip>
 #include <iostream>

 int main()
 {
  double x {0.1};
  std::cout << std::setprecision(17);
  std::cout << x << '\n';
 }
```

we would notice that executable would print:
`0.10000000000000001`

notice after the 16th digit, an error in value is introduced, the `1`.

this result is close to `0,1` but is not precisely, `0.1`, the error margin might look negligible but layers ot arithemetics
with this occuring at every layer of computation, continuisly, can lead to incredibly larger, buggier errors.
Rounding errors may make a number either slightly smaller or slightly larger, depending on where the truncation happens.

due to the fact that floating numbers are inexact, computations that deal with comparison of floating numbers are often
doomed to be error proned.

for example:

```cpp
 #include <iomanip>
 #include <iostream>
 int main()
 {
  std::cout << std::setprecision(17);
  double x { 1.0 };
  std::cout << x << '\n';
  double y { 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };         // 0.1 added 10 times which should result to 1
  std::cout << y << '\n';
 }
```

compiling and running this it is noticed that the second print statement prints:
`0.99999999999999989`
which is a rounding error raised by the inexact nature of floats, and a comparison computaion that
tries to compare x and y equality would be false, even though logically it should be true.

comparing floating numbers is generally problematic.
The solution to this problem will be explained later, according to wetin i dey read.

Note:
- never assume flaoting numbers are exact, this si not an exception, its a rule
- rounding errors in floating numbers generally occur due to the inability of floating numbers to store some numbers precisely
  due to thier limitaion in memory.

NaN and Inf
-----------
there are two special categories for floating numbers, which are `NaN` and `Inf`,

1) Nan - Not a number, represents mathematically invalid values.
2) Inf - represents infinity can be poitive or negative infinty.

NOte:
Avoid division by zero


 Boolean values 
=================
Boolean variables are variables that only have only two possible values, `true` or `false`
they are declared using the `bool` keyword.

```cpp
  bool b1 { true };
  bool b2 { false };
  b1 = false;
  b2 = !false;
  bool b3 { !false };
  bool b4 {};                 // defaultly initialized to false.
```

Printing boolean values
-----------------------
Due to the fact that boolean types are basically just integral datatypes that hold either 1 or 0, for true and false.
printing them just prints either 1 or 0.

to make bools print `true` or `false`, pass the `std::boolalpha` into the `std::cout`.

```cpp
  #include <iostream>

  int main()
  {
    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::boolalpha;

    std::cout << true << '\n';
    std::cout << false << '\n';
  }
```

 Introduction to if statements 
================================
If statements are conditional statements that determines what to execute, depending on the resolution of a conditional.

if statement syntaxes:
```cpp

  // syntax design one
  if condition
    single_statement;

  // syntax design two
  if condition_1
    true_statement_handler;
  else
    false_statement_handler;

  // syntax design 3
  if (x > 0)
    std::cout << "The value is positive\n";
  if else (x < 0)
    std::cout << "The value is negative\n";
  else
    std::cout << "the value is zero";

```

single statemnt return condition
--------------------------------
if there ever comes a need to write a syntax with this format:

```cpp
  if (condition)
    return true;
  else
    return false;
```

it can be replaced with a return condition, making the code shorter and perfrom the same task

```cpp
  return (condition);
```


 Chars 
========
A char datatype was designed to hold a single character.

a char dataype is an integral type, maeanng the underlying values are stored as integers. similar to ow boolean type
stores 1 and 0 to be reprensented as true and false, chars store integers that are mapped to ASCII characters.

range of ASCII cahracters `0 to 127`.
characters are always represented in single quotes.

`0-31` unprintable characters, `32-127` printable characters.

Initializing characters
-----------------------
```cpp
  char ch1 {'d'};               // best practice
  char ch2 {97};                // initialize with integer 97 'a' in the ascii format (not preferred)
```

Printing chars
--------------
when printing a char `std::cout` prints it out as an ascii character.

Inputing char
-------------
the `std:cin` accepts char input to be stored into a char dataype
if more than one char was inputed on;y the forst string is stored into the char, the rest is kept in the
`std::cin`, buffer and is flushed and printed one character at a time with subsequent calls to `std::cin`.


 Introduction to type conversion and static_cast 
==================================================
Cpp, in mpst cases, allows us to convert a type from one fundamental type to another, this is known as type
conversion, wehn he compiler does this on our behalf without us asking this is known as `Implicit type Conversion`.

Type conversion produces a new value
------------------------------------
Type conversion does not actually change the value or type of the value being converted instead. the value
to be converted as used as input, and conversion results to a new value of the target type (via direct initialization).

Npte:
- one of the reasona that brace initialization is preferref is because it would not allow us initialize a variable
  with am initializer that would loose value when its implicitly type converted.


 An introduction to explicit type conversion via the static_cast operator 
===========================================================================
Explicit type conversion occurs when the progrommer explicitly tells the compiler to convert a type from one
form to another saying we bear full responsibilities for any loss in data that might occur.

to perform type conversion we use the `static_cast` operator.

syntax for explicit type conversion:
```cpp
  static_cast<new_type> (expression);
```

Note:
- whenever a `<>` appears in cpp, the content in the brackets is usually a type.

```cpp

  #include <iostream>

  void print(int x)
  {
    std::cout << x << '\n';
  }

  int main()
  {
    double x {5.6};
    print( static_cast<int> x );

    return (0);
  }

```

The above snippet is an example of explicit type conversion using `static_cast`.


 Using static_cast to convert char to int 
===========================================
```cpp
  int ascii_value_of_c = static_cast<int> 'c';
```

 Converting unsigned numbers to signed numbers 
================================================
```cpp
  int main()
  {
    unsigned int x {6};
    int y { static_cast<int> x };

    return (0);
  }
```

`static_cast` does not perform value range checking, therefore, in the above snippet, if the value of x is
greater than the range an int can handle asn its type converted using `ststic_cast` undefined behaviour might
occur.

 std::int8_t and std::uint8_t likely behave like chars instead of integers 
============================================================================
on some architectures `std::int8_t`, `std::uint8_t` or any 8 bit fixed-width integral type in the `<cstdint>`
header, are treated as chars. this can be prevented by explicit type conversion to int.

in this snippet:

```cpp
  #include <cstdint>
  #include <iostream>

  int main()
  {
    std::cout << "Enter a number between 10 and 127: ";
    std::int8_t number{};
    std::cin >> number;

    std::cout << "you inputed " << static_cast<int> (number) << '\n';
    return 0;
  }
```

if you inputed 35 you might be expecting 35, but the result would be 51, this is because
`std::int8_t` is treated as a char so it treats the content of the input stream as a buffer of characters
and its strips and stores the first character it encouters, shich in this case is `3`, which has the ascii
value `51`, thus the result from running the executable.

 Const variables and symbolic constants 
=========================================
```cpp
  const double gravity {9.8};
```

lost my notes here, oh well

- prefer const variables to object-like macros for symbolic constants.
- const variables must be initialized.
- const variables values cannot be changed.

 Compile-time constants, constant expressions, and constexpr 
==============================================================
- Constant expression are expressions that can be evaluated by the compiler at compile time.
- Compile-time constants: this are constants that their values are known at compile time. eg, literals
- A const variable is a compile time constant if its initializer is a constant expression.
- Runtime const:  this are constant variables that its initialization values are not known untill runtime.

```cpp
  #include <iostream>

  int getNumber()
  {
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;

    return y;
  }

  int main()
  {
    const int x{ 3 };           // x is a compile time constant

    const int y{ getNumber() }; // y is a runtime constant

    const int z{ x + y };       // x + y is a runtime expression and z is a runtime const

    return 0;
  }
```

The constexpr keyword
---------------------
When a const variable is declared te compiler is not aware of its a runtime or compile-time constant, so it implicitly tracks it.
to declare a compile time constant that would raise an error when placed in a state of runtime dependency,
the `constexpr` keyword is used. this is efficient for maxing optimizations.

the `constsxpr` variable can only be initialized with compile-time values, if not the compiler would throw an error

```cpp
  constexpr double earth_gravity { 9.8 };
```

any variable that should not be modifiable after its initization and its initializer is known at `compile-time`, should be
declared as a `constexpr` variable.

any variabke that should not be modifiable after it initialization and its initializer is known at `runtime`, should be
declared as a `const` variable.

- because `constexpr` objects must be initialized upon declaration (with a compile time constant), they can not be used
  as function parameters.

When are constant expressions actually evaluated?
-------------------------------------------------
C++ is designed to always evaluate constant exoressions at compile time in contexts that require constant expressions,
(such as initilizer of a compile time contant.)

in a situation that a compile time constant is not required, the compiler can choose to evaluate either at compile time or runtime.

```cpp
  constexpr int x { 4 + 5 }           // compile tiee evaluation
  const int y { 999 };                // compile time evaluation

  int z { 6 + 9 };                    // either runtime or compile time.
```

Constant folding for constant subexpressions
--------------------------------------------
in the following example:

```cpp
  int main()
  {
    constexpr int x { 4 + 3 };          // constant exoression
    std::cout << x << '\n';             // runtime expression
  }
```

this snippet can be narrowed into a more optimized version:

```cpp
  int main()
  {
    std::cout << 4 + 3 << '\n';         // this is a runtime expression.
  }
```

The second snippet is a `constant sub-expression`, which compilers have been designed to execute optimally,
than whatevers going on in the first snippet.

This optimization is known as `constant folding`, where instead of creating a constant variable to hold a value
that another statement would depend on to execute, the value the statement is depending on, would be placed in the statement
itself.

like above.


 Literals 
===========
Literals are values inserted directly into the code.

Examples:
```cpp
  return 5;                     // 5 is an integer literal
  bool myNameIsAlex { true };   // true is a boolean literal
  double d { 3.4 };             // 3.4 is a double literal
  std::cout << "Hello, world!"; // "Hello, world!" is a C-style string literal
```

literal types
-------------
| Literal Value       | Examples       | Default literal type | Note           |
|---------------------|----------------|----------------------|----------------|
| integer value       | 5, 0, -3       | int                  |                |
| boolean value       | true, false    | bool                 |                |
| flaoting point type | 1.2, 0.0, 3.4  | double (not float!)  |                |
| character           | 'a', '\n'      | char                 |                |
| C-style string      | "Hello World!" | const char[14]       | C style string |
|                     |                |                      |                |

Note:
- if the default type of a literal is not desired, you can change the type of the literal with a suffix. 
  check [[www.learncpp.com/cpp-tutorial/literals/]], literal suffix section ofr list of suffixes.
- By default, floating point literals have a type of double. To make them float literals instead, the f (or F) suffix should be used
- C -style string literals are null byte, terminated (obviously).
- A magic number is a literal (usually a number) that either has an unclear meaning or may need to be changed later.
- Using magic numbers is generally considered bad practice, this can be fixed by using symnolic constants.

EXAMPLE:

this should be done:
```cpp
  int main()
  {
    constexpr int maxStudentsPerClass { 30 };
    constexpr int totalStudents{ numClassrooms * maxStudentsPerClass }; // now obvious what this 30 means

    constexpr int maxNameLength{ 30 };
    setMax(maxNameLength); // now obvious this 30 is used in a different context
  }
```

instead of:
```cpp
  int main()
  {
    constexpr int totalStudent(numClassrooms * 30);  // in this code 30 acts as a magic number,
    setMax(30);                                      // also here, its meaning can be guessed but ultimately, its ambigious
  }
```

- magic numbers are'nt always numbers, they are literals of any type that its meaning in a codebase is hard to tell.
  avoid them.


 Numeral systems (decimal, binary, hexadecimal, and octal 
===========================================================
prefixes fro differnt number sytem literals:

| Number system             | base | prefix   |
|---------------------------|------|----------|
| octal number system       | 8    | 0 (zero) |
| hexadecimal number system | 16   | 0x       |
| binary number sytem       | 2    | 0b       |
|                           |      |          |

Digit seperators
----------------
Because long literals can be hard to read c++14 introduced digit seperators. `'`, a singe quatation mark.

```cpp
  int bin { 0b1001'1010 };
  long value { 2'113'233'478 };         //easiser to read.
```

- Digit separators are purely visual and do not impact the literal value in any way.

Outputting values in decimal, octal, or hexadecimal
---------------------------------------------------
this is done using io manipulators `std::hex`, `std::bin`, `std::oct`, rememeber once set its stays sets unless
explicitly changed.

```cpp
  int value { 12 };

  std::cout << x << '\n';
  std::cout << std::hex << x << '\n';
  std::cout << std::oct << x << '\n';
  std::cout << std::bin << x << '\n';
  std::cout << std::dec << x << '\n';
  std::cout << x << '\n';
```

Outputting values in binary
---------------------------
outputing binary is a bit complex for `std::cout` so to solve this, c++ has a special type that stores desired number of bits,
`std::bitset<n>`, where n is the number of bits to be stored.

it is contained in the `<bitset>` header, it us used to create `bitset` objects that only stores the specified number of bits
you want to store, and its efficient for outputing bits. the number of bits must be a compile-time constant.

```cpp
  #include <bitset>
  #include <iostream>

  int main()
  {
    std::bitset<8> x { 0b1001'1011 };
    std::bitset<8> y { 0xC5 };              // the bitset type accepts integral initializer of any number system.

    std::cout << x << '\n' << y << '\n';
    std::cout << std::bitset<4> { 0b1010 } << '\n';       // a temporary anonymous object with 4 bits of size was created here.
    // it would be discarded after usage
  }
```

The format library can also be used.

```cpp
  #include <format>
  #include <iostream>
  #include <print>

  int main()
  {
    std::cout << std::format("{:b}\n", 0b1001);
    std::cout << std::format("{:#b}\n", 0b1111);

    std::print("{:b} {:#b}\n", 0b1010, 0b1110);
  }
```

this prints:
`1001
0b1111
1010 0b1110`


 Introduction to std::string 
==============================
introducing std::string
-----------------------
the easiest way to work with string objects is with `std::string` type in the `<string>` header.
just like normal objects they can be  initilized and assigned values

```cpp
  #include <string>

  int main()
  {
    std::string name {};
    std::string name_2 { "jacob" };
    name_2 = "calliope";

    return 0;
  }
```

- they output as expected using `std::cout`, empty strings peint nothing
- they can handle strings of different length. this is one of the reasons that std::string is so powerful.
```cpp
  std::string name { "calliope" };
  name = "Gaia";
  name = "hectaconchires";                      // all this pose no error. unlile in C with C-style strings.
```


The conditional operator
=========================
considtional operator `?:`, can help us reduce the code needed to write conditional statements of this format:
```cpp
  if (condition)
    value = statement_1;
  else
    value = statement_2;
```

into:
```cpp
  value = (condition) ? statement_1 : statement_2;
```

- the conditional operator helps to compact code without losing readablity.
- the conditional operator evaluates to an expression. so it can be used as an initilizer or value

```cpp
  #include <iostream>

  int main()
  {
    constexpr bool classIsBig{ false };
    constexpr int size { classIsBig ? 30 : 10 };
    std::cout << "the class size is " << size << '\n';

    return 0;
  }
```

- The type of expression should match or be convertible.

Example:
```cpp
  #include <iostream>

  int main()
  {
    constexpr int x { 5 };
    std::cout << (x != 5 ? x : "x is five") << '\n';        // this wont compile.
  }
```

The above snippet wont compile because in the conditional statement the types of object to be evaluated on the condition,
`(x != 5)`, are not the same and cannot even be converted to the same type, thus the compiler throws an error.

- Prefer to avoid the conditional operator in complicated expressions.

<!--TODO: Come back to this when your less sick.-->
 Inline functions and variables 
=================================
- Inline expansion is a case where function call replaced by the code in the called function defination.
- Inline function can reduce cpu overhead and act as an optimization
- but if the function is too large it can pose a problem, because longer code tend to result to larger executables when compiled
  and larger executables are usually slower (due to not being able to fit into memory caches.)

<!--NOTE: Inline expansion could result in performance improvements, performance reductions, or no change to performance
    at all, depending on the relative cost of a function call, the size of the function, and what other optimizations
    can be performed.-->

- inline functions are suited for simple and short functions. especially where the function can be executed more than once.

when inline function occurs there are 2 results:
1) may be expanded (most functions are in this category)
2) cant be exapanded.

```cpp
  inline int min(int x, int y) // inline keyword means this function is an inline function
  {
    return (x < y) ? x : y;
  }
```

<!--NOTE: BEST PRACTICE: Do not use the inline keyword to request inline expansion for your functions.-->

Inline Variables
----------------
These are variables that are allowed to be defined in multiple files.

- In modern c++ inline has evolved to mean multiple definations allowed.

Inline functiona and variables have 2 requirements:
1) must have full defination (not just forward declarations)
2) although multiple definations are allowed they must all be identical otherwise UB.

- a linker will consolidate all inline functions or inline variable definations for an identifier into one single
  defination, therefore still resppecting the one defination rule.
- inline functiona and variables are basically defined in header files. this are benenfecial for header only libraries
  (no .cpp files are included).
- for most times you should define inline function and variables in header files.


 Constexpr and consteval functions 
====================================
- constexpr functions can evaluate bothn runtime or comple time depending on their calling context
- consteval functions only execute on compile time the keyword is: `consteval`
- both consteval and constexpr are both implicitly inline functions
- consteval functions shoould be defined in header files
- you can define how constexpr function would handle runtime or compile-time contexts with a `std::is_constant_evaluated()`
  conditional, this function is defined in the `<type_traits>`

```cpp
  #include <type_traits>

  constexpr int run_this()
  {
    if (std::is_constant_evaluated())
      // statements for compile-time evaluation goes here
    else
      // statements for run-time evaluation goes here
  }
```

- you can use contsteval functions to force constexpr functions to evaluate at compile-time, with the helper function below
```cpp
  #include <iostream>

  // NOTE: the auto keyword is a return type that makes a function work with any type.

  consteval auto CompileTime(auto value)
  {
    return value;
  }

  constexpr int greater(int x, int y)
  {
    return (x > y ? x : y);
  }

  int main()
  {
    std::cout << greater(7, 2) << '\n';                   // may not evaluate on comile time.
    std:: cout << CompileTime(greater(7, 2)) << '\n';     // would evaluate on runtime.
    return 0;
  }
```

- the above snippet porves that consteval functions can be used to force constexpr functon to run at compile time
  even in context where a constant expression is not required.

- const* functions do not allow const* parameters but their arguments can be const.
- constexpr functions can call non-constexpr functions (becuase they can be evalauated in both runtime and compile time)
  but this practice is best avoided.
- The compiler must be able to see the full definition of a constexpr or consteval function, not just a forward declaration.
  this is why its recommended to place them in header files and include them when needed. so as to make then visible
  to the compiler no matter the translation unit.
- consteval function are called immediate functions, because they are always evaluated at compile time.
  and because of this their argument context and all must be constant based.

<!--NOTE: const* stand for constexpr/consteval not const-->


 std::string_view 
===================
<!---->
