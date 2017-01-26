#include <stdlib.h>
#include <string.h>

#define ones      1
#define tens      10
#define hundreds  100

/*
 * Function: counting_sort
 * -----------------------
 * see "counting_sort.c" for explanation. this function is a duplciate specific
 * to sorting an array of integers from least significant to most significant
 * digit
 *
 * a: input array to sort ( signed integers )
 * b: sorted input array ( signed integers )
 * size: size of sortable array
 * k: range maximum
 * unit: digit significance (ones, tens, hundreds, etc)
 *
 * returns: nothing (sorted array is a pointer)
 */
void counting_sort(int a[], int *b, int size, int k, int unit)
{
    // temporary (working) storage
    int *c;
    c = (int *)malloc(sizeof(int) * size);
    memset(c, 0, (sizeof(int) * size));

    /* traverse the array to be sorted, counting the number of occurrences of
     * the value at the cursor's current offset. use the value at the cursor's
     * current offset as the offset into the temporary array
     *
     * array to be sorted
     *          ---------------------------------
     * offset   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
     *          ---------------------------------
     * value    | 2 | 5 | 3 | 0 | 2 | 3 | 0 | 3 | 
     *          ---------------------------------
     *
     * temporary array containing number of occurrences of values from the
     * array to be sorted
     *          -------------------------
     * offset   | 0 | 1 | 2 | 3 | 4 | 5 |
     *          -------------------------
     * value    | 2 | 0 | 2 | 3 | 0 | 1 |
     *          -------------------------
     */
    for ( int j=0; j < size; j++ ) {
        int offset = (a[j] / unit) % 10;
        c[offset] = c[offset] + 1;
    }

    /* traverse the temporary array, modifying the value at the cursor's current
     * offset by assigning it the result of adding itself to the value at the
     * previous offset.
     *
     * temporary array containing number of occurrences of values from the
     * array to be sorted
     *          -------------------------
     * offset   | 0 | 1 | 2 | 3 | 4 | 5 |
     *          -------------------------
     * value    | 2 | 0 | 2 | 3 | 0 | 1 |
     *          -------------------------
     *
     * temporary array after applying addition calculation
     *          -------------------------
     * offset   | 0 | 1 | 2 | 3 | 4 | 5 |
     *          -------------------------
     * value    | 2 | 2 | 4 | 7 | 7 | 8 |
     *          -------------------------
     */
    for ( int i=1; i <= k; i++ ) {
        c[i] = c[i] + c[(i - 1)];
    }

    for ( int j=(size - 1); j >= 0; j-- ) {
        // subtract one as array uses zero-based numbering. we should enforce
        // array lower bound constraint in the future
        int offset = (a[j] / unit) % 10;
        b[(c[offset] - 1)] = a[j];
        c[offset] = c[offset] - 1;
    }

    free(c);
}

/*
 * Function: radix_sort
 * --------------------
 * leverages two loops traversing in opposite directions, where the outer loop
 * traverses from the beginning of the array to its end and the inner loop traverses
 * from the end of the array to its beginning. smaller values bubble to the
 * beginning of the array
 *
 * a: input array to sort ( signed integers )
 * b: sorted input array ( signed integers )
 * size: size of sortable array
 *
 * returns: nothing (sorted array is a pointer)
 */
void radix_sort(int a[], int *b, int size, int max)
{
    for ( int unit=1; (max / unit) > 0; unit *= 10 ) {
        if (unit == ones) {
            counting_sort( a, b, size, max, unit );
        }
        else {
            int temp[size];
            for ( int i=0; i < size; i++ ) temp[i] = b[i];
            counting_sort( temp, b, size, max, unit );
        }
    }
}
