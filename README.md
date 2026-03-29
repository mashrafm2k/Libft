*This project has been created as part of the 42 curriculum by \<moashraf\>.*

# Libft

## Description

Libft is a custom C library built from scratch as the foundation of the 42 curriculum. Rather than relying on the standard C library, the project requires reimplementing its most essential functions by hand, enforcing a deep understanding of how they work at a low level. The resulting `libft.a` static archive is carried forward and reused throughout all subsequent 42 projects.

> **Note on curriculum version:** This project was completed under an earlier version of the 42 subject, in which the linked list functions (`ft_lst*`) were part of a separate **bonus** section and compiled independently via `make bonus`. The current subject (v19.0) has since reclassified them as a mandatory **Part 3**. The implementation is fully compliant either way — the functions are present and correct — but the Makefile reflects the original structure, keeping the list functions behind the `bonus` rule rather than `all`.

The library is organized into three parts:

### Part 1 — Libc reimplementations

Standard functions rebuilt without any external library, behaving identically to their libc originals. Each is prefixed with `ft_`.

| Category | Functions |
|---|---|
| Memory | `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` `ft_calloc` |
| String | `ft_strlen` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_strlcpy` `ft_strlcat` `ft_strdup` `ft_strstr` `ft_strcat` |
| Character checks | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` |
| Character conversion | `ft_toupper` `ft_tolower` |
| Numeric conversion | `ft_atoi` |

> Character classification functions return `1` on match, `0` otherwise — unlike some libc implementations that return non-zero values.

> **Note:** `ft_strstr` and `ft_strcat` are not required by the current subject (v19.0). They were part of an earlier version of the curriculum and have been kept for completeness and backwards compatibility with older projects.

### Part 2 — Additional utility functions

Tools not found in the standard library but commonly needed in C programs.

- `ft_substr` — extracts a substring from a string given a start index and maximum length
- `ft_strjoin` — concatenates two strings into a newly allocated result
- `ft_strtrim` — removes characters belonging to a given set from both ends of a string
- `ft_split` — splits a string by a delimiter character, returns a NULL-terminated array of substrings
- `ft_itoa` — converts an integer (including negative values) to its string representation
- `ft_strmapi` — applies a function to each character of a string, returning a new string from the results
- `ft_striteri` — same as `ft_strmapi` but modifies the string in place, passing each character by address
- `ft_putchar_fd` — outputs a character to a given file descriptor
- `ft_putstr_fd` — outputs a string to a given file descriptor
- `ft_putendl_fd` — outputs a string followed by a newline to a given file descriptor
- `ft_putnbr_fd` — outputs an integer to a given file descriptor

### Part 3 — Linked list functions

Implements a singly linked list using the `t_list` structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

- `ft_lstnew` — allocates and returns a new node initialized with the given content
- `ft_lstadd_front` — inserts a node at the beginning of a list
- `ft_lstadd_back` — inserts a node at the end of a list
- `ft_lstsize` — counts and returns the number of nodes
- `ft_lstlast` — returns the last node
- `ft_lstdelone` — frees a node's content via a `del` function, then frees the node (does not touch the next node)
- `ft_lstclear` — calls `ft_lstdelone` on every node and sets the list pointer to NULL
- `ft_lstiter` — applies a function to the content of every node
- `ft_lstmap` — produces a new list by applying a function to each node's content; uses a `del` function to clean up on allocation failure

## Instructions

### Compilation

Build the library (Parts 1 and 2):
```bash
make
```

Include the linked list functions (Part 3):
```bash
make bonus
```

Remove object files:
```bash
make clean
```

Remove object files and `libft.a`:
```bash
make fclean
```

Full rebuild:
```bash
make re
```

### Using libft in another project

Copy the `libft/` folder into your project root, then add the following to your Makefile:

```makefile
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
```

Include the header in any source file that needs it:

```c
#include "libft/libft.h"
```

## Resources

- `man 3 string` — standard string function specifications
- `man 3 stdlib` — standard library function specifications
- `man 3 ctype` — character classification and conversion
- [C Standard Library reference (cppreference)](https://en.cppreference.com/w/c) — detailed documentation for all reimplemented functions
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) — memory management and pointers reference
