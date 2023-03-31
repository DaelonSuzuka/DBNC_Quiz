#include <stdint.h>
#include <stdio.h>

/*  get all the squares that fit inside the given rectangle
    returns the number of squares identified
    if return value == len, then the output array was filled
    if return value == -1, then some other error occured

    uint32_t n, m: rectangle dimensions
    uint32_t *squares: the array to write the squares to
    size_t len: the size of the output array
*/
size_t get_squares(uint32_t n, uint32_t m, uint32_t *squares, size_t len) {
    uint32_t i = 0;

    if (!squares || n == 0 || m == 0) {
        return -1;
    }

    while (1) {
        if (i == len) {
            return len;
        }
        if (n == m) {
            squares[i++] = n;
            break;
        } else if (n > m) {
            n -= m;
            squares[i++] = m;
        } else if (m > n) {
            m -= n;
            squares[i++] = n;
        }
    }
    return i;
}

// print all the squares from the given array
void print_squares(uint32_t *squares, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%ux%u", squares[i], squares[i]);
        if (i < len) {
            printf(" ");
        }
    }
    printf("\n");
}

#define MAX_SQUARES 10u

int main(void) {
    printf("Testing square finder:\n");
    printf("MAX_SQUARES = %u\n\n", MAX_SQUARES);

    // only need one dimension to represent a square, so we can store
    // them as an array of u32s
    uint32_t squares[MAX_SQUARES] = {};
    size_t squaresFound;

    squaresFound = get_squares(6, 5, squares, MAX_SQUARES);
    printf("n=5, m=6, found %ld squares:\n", squaresFound);
    print_squares(squares, squaresFound); // Output: 5x5 1x1 1x1 1x1 1x1 1x1
    printf("\n");

    squaresFound = get_squares(1, 1, squares, MAX_SQUARES);
    printf("n=1, m=1, found %ld squares:\n", squaresFound);
    print_squares(squares, squaresFound); // Output: 1x1
    printf("\n");

    squaresFound = get_squares(9, 9, squares, MAX_SQUARES);
    printf("n=9, m=9, found %ld squares:\n", squaresFound);
    print_squares(squares, squaresFound); // Output: 9x9
    printf("\n");

    squaresFound = get_squares(100, 97, squares, MAX_SQUARES);
    printf("n=100, m=97, found %ld squares:\n", squaresFound);
    if (squaresFound == MAX_SQUARES) {
        printf("Filled the output array, results invalid\r\n");
    }
    printf("\n");

    squaresFound = get_squares(6, 5, NULL, MAX_SQUARES);
    printf("n=6, m=5, found %ld squares:\n", squaresFound);
    if (squaresFound == -1) {
        printf("Can't write to a null pointer.\r\n");
    }
    printf("\n");

    squaresFound = get_squares(0, 5, squares, MAX_SQUARES);
    printf("n=0, m=5, found %ld squares:\n", squaresFound);
    if (squaresFound == -1) {
        printf("Input dimension of 0 doesn't make any sense.\r\n");
    }
    printf("\n");

    return 0;
}
