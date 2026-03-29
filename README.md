*This project has been created as part of the 42 curriculum by \<moashraf\>.*

# Libft

## Description

Libft is a custom C library built from scratch as the foundation of the 42 curriculum. Rather than relying on the standard C library, the project requires reimplementing its most essential functions by hand, enforcing a deep understanding of how they work at a low level. The resulting `libft.a` static archive is carried forward and reused throughout all subsequent 42 projects.

> **Note on curriculum version:** This project was completed under an earlier version of the 42 subject, in which the linked list functions (`ft_lst*`) were part of a separate **bonus** section and compiled independently via `make bonus`. The current subject (v19.0) has since reclassified them as a mandatory **Part 3**. The implementation is fully compliant either way — the functions are present and correct — but the Makefile reflects the original structure, keeping the list functions behind the `bonus` rule rather than `all`.

The library is organized into three parts:

**Part 1 — Libc reimplementations** covers standard functions that every C programmer relies on, rebuilt without using any external library. These include memory manipulation (`ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_bzero`), string operations (`ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`), character classification (`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`), character conversion (`ft_toupper`, `ft_tolower`), numeric conversion (`ft_atoi`), and allocation (`ft_calloc`). All functions behave identically to their libc originals as described in their respective man pages, with the `ft_` prefix added to each name.

**Part 2 — Additional utility functions** provides tools not found in the standard library but commonly needed in C programs. `ft_substr` extracts a substring from a string given a start index and maximum length. `ft_strjoin` concatenates two strings into a newly allocated result. `ft_strtrim` removes characters belonging to a given set from both ends of a string. `ft_split` splits a string by a delimiter character and returns a NULL-terminated array of substrings. `ft_itoa` converts an integer (including negative values) to its string representation. `ft_strmapi` applies a function to each character of a string, producing a new string from the results. `ft_striteri` does the same but modifies the string in place by passing each character by address. The file descriptor output functions — `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, and `ft_putnbr_fd` — write a character, string, string followed by a newline, or integer to a given file descriptor respectively.

**Part 3 — Linked list functions** implements a singly linked list using the `t_list` structure, which holds a `void *content` pointer and a `*next` pointer. `ft_lstnew` allocates and returns a new node initialized with the given content. `ft_lstadd_front` and `ft_lstadd_back` insert a node at the front or back of a list. `ft_lstsize` counts the number of nodes. `ft_lstlast` returns the last node. `ft_lstdelone` frees a single node's content using a provided `del` function and then frees the node itself, without touching its successor. `ft_lstclear` calls `ft_lstdelone` on every node in the list and sets the list pointer to NULL. `ft_lstiter` applies a function to the content of every node. `ft_lstmap` produces a new list by applying a function to each node's content, using a `del` function to clean up on allocation failure.

## Instructions

### Compilation

```bash
make        # builds libft.a (Parts 1 and 2)
make bonus  # rebuilds libft.a including the ft_lst* functions (Part 3)
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # fclean + all
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

### Function reference

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` |
| Character conversion | `ft_toupper` `ft_tolower` |
| String | `ft_strlen` `ft_strlcpy` `ft_strlcat` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_strdup` `ft_substr` `ft_strjoin` `ft_strtrim` `ft_split` `ft_strmapi` `ft_striteri` |
| Memory | `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` `ft_calloc` |
| Conversion | `ft_atoi` `ft_itoa` |
| File descriptors | `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd` |
| Linked list | `ft_lstnew` `ft_lstadd_front` `ft_lstsize` `ft_lstlast` `ft_lstadd_back` `ft_lstdelone` `ft_lstclear` `ft_lstiter` `ft_lstmap` |

## Resources

- `man 3 string` — standard string function specifications
- `man 3 stdlib` — standard library function specifications
- `man 3 ctype` — character classification and conversion
- [C Standard Library reference (cppreference)](https://en.cppreference.com/w/c) — detailed documentation for all reimplemented functions
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) — memory management and pointers reference

## Author

**42 student:** `moashraf`.
Part of the **42 Abu Dhabi** curriculum