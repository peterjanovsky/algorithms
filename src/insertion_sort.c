/** time complexity
  *   c1 n squared
  *     where c1 is a constant that does not depend on n
  *     takes time roughly proportional to n squared
  */
int *insertion_sort(int sortable[], int size)
{
    int key;

    /** taverse array starting at second position
      */
    for ( int j = 1; j < size; j++ ) {

        // assign current value to temporary variable
        key = sortable[j];

        /** traverse array starting at cursor's previous position
          *   if value at position is greater than current value
          *     move value one position to the right
          *     decrement cursor
          *   assign current value to position of cursor after traversing array
          *   from right-to-left
          */
        int i = j - 1;
        while ( i > -1 && sortable[i] > key ) {

            sortable[i + 1] = sortable[i];
            i = i - 1;
        }

        sortable[i + 1] = key;
    }

    return sortable;
}
