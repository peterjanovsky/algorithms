/*
 * Function: insertion_sort
 * ------------------------
 * sorts an array by traversing in opposing directions, transposing the value
 * at the offset of the loop advancing towards the end of the array with the
 * value at the offset of the loop advancing towards the beginning of the array
 * if it greater than the value to which it is being compared
 *
 * time complexity
 *   c1 n squared
 *     where c1 is a constant that does not depend on n
 *     takes time roughly proportional to n squared
 *
 * sortable: array to sort ( signed integers )
 * size: size of sortable array
 *
 * returns: the sorted array
 */
int *insertion_sort(int sortable[], int size)
{
     int key;

     // taverse array starting at second position
     for ( int j=1; j < size; j++ ) {

          // assign current value to temporary variable
          key = sortable[j];

          /* traverse array starting at cursor's previous position
           *
           *  if value at position is greater than current value
           *    move value one position to the right
           *    decrement cursor
           *  assign current value to position of cursor after traversing array
           *  from right-to-left
           */
          int i = j - 1;
          while ( (i > -1) && (sortable[i] > key) ) {

               sortable[i + 1] = sortable[i];
               i = i - 1;
          }

          sortable[i + 1] = key;
     }

     return sortable;
}
