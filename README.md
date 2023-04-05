# DBNC_Quiz

This repository contains my answers to the DBNC Group Embedded Software Engineer Quiz.

The solution to question 1 was compiled using GCC `11.3.0`. My solution does not dynamically allocate memory, and I added additional checks to safely handle certain kinds of pathological input.

Output from [question_1.c](question_1.c)
```
Testing square finder:
MAX_SQUARES = 10

n=5, m=6, found 6 squares:
5x5 1x1 1x1 1x1 1x1 1x1 

n=1, m=1, found 1 squares:
1x1 

n=9, m=9, found 1 squares:
9x9 

n=100, m=97, found 10 squares:
Filled the output array, results invalid

n=6, m=5, found -1 squares:
Can't write to a null pointer.

n=0, m=5, found -1 squares:
Input dimension of 0 doesn't make any sense.
```

~~I couldn't answer question 2, but I documented my approach and thought process in [question_2.md](question_2.md).~~

After some extra time thinking about it, I decided to follow a hunch that this was a baseN encoding scheme with a custom cipher. A straightforward genetic algorithm found a custom base-62 cipher, `C7xicPMGvzAZyTNodmwnV5D3B6H0Oup8E21W9sqLQX4YjSeUhIRJgafFtrKlbk`, which successfully converts the input column into the output column.

The code for this is in [question_2.ipynb](question_2.ipynb).
