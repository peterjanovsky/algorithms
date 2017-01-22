#include <limits.h>

/*
 * Function: bubble_sort
 * ---------------------
 * leverages two loops traversing in opposite directions, where the outer loop
 * traverses from the beginning of the array to its end and the inner loop traverses
 * from the end of the array to its beginning. smaller values bubble to the
 * beginning of the array
 *
 * sortable: array to sort ( signed integers )
 * size: size of sortable array
 *
 * returns: the sorted array
 */
int *bubble_sort(int sortable[], int size)
{
     // traverse array starting at first position
     for ( int i=0; i < size - 1; i++ ) {

          /* traverse array starting last position stepping backwards
           *
           *  swap cursor value with value at position proceeding cursor if
           *  cursor value is less than proceeding value
           */
          for ( int j=size-1; j > i; j-- ) {

               if ( sortable[j] < sortable[j - 1] ) {

                    int value = sortable[j];
                    sortable[j] = sortable[j - 1];
                    sortable[j - 1] = value;
               }
          }
     }

     return sortable;
}
