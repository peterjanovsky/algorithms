/*
 * Function: counting_sort
 * -----------------------
 * sorts numbers within the provided range 0 to n, where n is specified by the
 * function parameter "k". the algorithm counts the number of occurrences of
 * each unique integer within the specific range storing the result within a
 * temporary array. this value is used as the offset within the final sorted
 * array for the underlying value which it represents
 *
 * a: input array to sort ( signed integers )
 * b: sorted input array ( signed integers )
 * size: size of sortable array
 * k: range maximum
 *
 * returns: nothing (sorted array is a pointer)
 */
void counting_sort(int a[], int *b, int size, int k)
{
    // temporary (working) storage
    int c[(size + 1)];

    // initialize memory block
    memset(c, 0, (size + 1));

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
        c[a[j]] = c[a[j]] + 1;
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

    /* assign the value at the cursor's current offset to the ofset specified
     * by the 
     *
     * obtain the offset within the sorted array from the temporary array for
     * the value at the cursor's offset within the input array
     *
     * array to be sorted
     *          ---------------------------------
     * offset   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
     *          ---------------------------------
     * value    | 2 | 5 | 3 | 0 | 2 | 3 | 0 | 3 | 
     *          ---------------------------------
     *
     * temporary array after applying addition calculation
     *          -------------------------
     * offset   | 0 | 1 | 2 | 3 | 4 | 5 |
     *          -------------------------
     * value    | 2 | 2 | 4 | 7 | 7 | 8 |
     *          -------------------------
     *
     * sorted array
     *    for the value of 3 at index 7 within the array to be sorted we obtain
     *    its index (7) within the sorted array. as the array utilizes zero-based
     *    numbering the value of one (1) is subtracted from the previously
     *    acquired index
     *
     *    the array to be sorted might contain duplicate values, thus we
     *    decrement the value within the temporary array causing the next
     *    duplicate value to be placed in the position immediately before this
     *    element
     *
     *          ---------------------------------
     * offset   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
     *          ---------------------------------
     * value    |   |   |   |   |   |   | 3 |   | 
     *          ---------------------------------
     */
    for ( int j=(size - 1); j >= 0; j-- ) {
        // subtract one as array uses zero-based numbering. we should enforce
        // array lower bound constraint in the future
        b[(c[a[j]] - 1)] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }
}
