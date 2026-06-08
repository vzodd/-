*This project has been created as part of the 42 curriculum by alvespin and jorvilch.*

# push_swap.a

### Description

The fourth project of the 42 Commom Core curriculum. The objective is to create a program that allows the sorting of a stack of numbers with different approaches, as well as analysing the differences between those approaches and their complexities.

### Instructions

```bash
# Create the library.
make
# Delete the object files.
make clean
# Delete the object files and the library.
make fclean
# Delete the object files and the library to create it again.
make re
# Create the program with the library.
cc -Wall -Werror -Wextra -lm push_swap.c push_swap.a -o push_swap
```

### Resources

In the making of this project we've made use of different webpages, such as GeeksforGeeks, cppreference and Linux man pages; and forums such Reddit and StackOverflow. Tools like GDB and LLDB have been used for debugging.

### Contents

#### Contributions by each member

alvespin
- ft_printf, ft_putchar, ft_strchr, ft_strncmp, ft_split (imported)
- ft_exit
- stack_ops
- stack_utils
- op_swap
- op_rotate
- push_swap
- parse_nums
- parse_nums_utils
- sort_simple: BubbleSort
- sort_compex: QuickSort

jorvilch
- ft_atoi (imported)
- ft_is_int
- op_push
- op_reverse_rotate
- compute_disorder
- normalize_stack
- sort_medium: ChunkSort
- sort_adaptive
- bench
- bench_utils
