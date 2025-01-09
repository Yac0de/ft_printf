# ft\_printf

## Table of Contents

1. [Overview](#overview)
2. [Key Features](#key-features)
3. [Variadic Functions](#variadic-functions)
   - [Key Macros](#key-macros)
   - [Example of Variadic Functions](#example-of-variadic-functions)
   - [How it Relates to ft\_printf](#how-it-relates-to-ft_printf)
4. [Usage](#usage)
   - [Building the Library](#building-the-library)
   - [Testing with Makefile](#testing-with-makefile)
   - [Manual Testing](#manual-testing)

## Overview

**ft\_printf** is a custom implementation of the `printf` function in C. This project helps to understand the detailed inner workings of `printf`, including variadic functions, string handling, and formatted output processing.

## Key Features

- Supports standard conversions:
  - `%c`: Print a single character.
  - `%s`: Print a string.
  - `%p`: Print a pointer address in hexadecimal format.
  - `%d`/`%i`: Print a signed decimal integer.
  - `%u`: Print an unsigned decimal integer.
  - `%x`/`%X`: Print a hexadecimal number (lowercase/uppercase).
  - `%%`: Print a literal percent sign.
- Bonus features include:
  - Handling flags:
    - `-`: Left-justify the output within the given field width.
    - `0`: Pad the output with zeros instead of spaces.
    - `.`: Specify precision for numbers and strings.
    - Field width: Define the minimum width of the output.
    - `#`: Alternate form for certain conversions (e.g., `0x` for `%x`).
    - `+`: Always display the sign of a number.
    - ` ` (space): Insert a space before positive numbers.

## Variadic Functions

Variadic functions are a key feature of **ft\_printf**, allowing it to handle a variable number of arguments. These functions use macros from `<stdarg.h>` to process arguments dynamically.

### Key Macros:

- `va_list`: A type to hold the information about the variable arguments.
- `va_start`: Initializes a `va_list` variable to retrieve arguments.
- `va_arg`: Accesses the next argument in the list.
- `va_end`: Cleans up the `va_list` after processing.

### Example of Variadic Functions:

```c
#include <stdarg.h>
#include <stdio.h>

void print_numbers(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        printf("%d ", num);
    }
    va_end(args);
}

int main() {
    print_numbers(3, 10, 20, 30);
    return 0;
}
```

In this example, `print_numbers` takes a variable number of integer arguments and prints them sequentially.

### How it Relates to ft\_printf:

In `ft_printf`, variadic functions are used to process format specifiers and dynamically retrieve corresponding arguments. For example, if the format string is `"%d %s"`, the variadic logic retrieves an integer and a string from the argument list, formatting them accordingly.

## Usage

### Building the Library

Run the following to compile the library:

```bash
# For mandatory part
make

# For bonus features
make bonus
```

This generates `libftprintf.a`, which can be linked to your C projects.

### Testing with Makefile

To test your implementation, uncomment the following lines in the `Makefile`:

```makefile
# TEST_FILE =            test.c
# TEST_EXEC =            test.out

# test: $(NAME)
# 	@echo "$(CYAN)Compiling test program...$(RESET)"
# 	@$(CC) $(FLAGS) $(INCLUDES) $(TEST_FILE) -L. -lftprintf -o $(TEST_EXEC)
# 	@echo "$(CYAN)Running test program...$(RESET)"
# 	@./$(TEST_EXEC)
```

Then create a simple `test.c` file to test specific scenarios, for example:

```c
#include "ft_printf.h"
#include "stdio.h"

int main() {
    int count = 0;

    printf("ACTUAL:\n");
    count = ft_printf("Integer:|%d|\nString:|%s|\nPointer:|%p|\n", 42, "Hello", &main);
    printf("count = %d\n\n", count);

    count = 0;

    printf("EXPECTED:\n");
    count = printf("Integer:|%d|\nString:|%s|\nPointer:|%p|\n", 42, "Hello", &main);
    printf("count = %d\n", count);

    return 0;
}
```

Run the test with:

```bash
make test
```

### Manual Testing

Alternatively, compile manually

```bash
cc -Wall -Wextra -Werror -o test test.c libftprintf.a
./test
```

