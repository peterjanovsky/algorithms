#include <limits.h>

/* 
 * @param sortable array to sort
 * @param size size of sortable array
 * @return the sorted array
 */
int *bubble_sort(int sortable[], int size)
{
     // traverse array starting at first position
     for ( int i=0; i < size - 1; i++ ) {

          /* traverse array starting last position stepping backwards
           *
           *  swap cursor value with  value at position proceeding cursor
           *    if cursor value is less than proceeding value
           */
          for ( int j=size-1; j > 0; j-- ) {

               if ( sortable[j] < sortable[j - 1] ) {

                    int value = sortable[j];
                    sortable[j] = sortable[j - 1];
                    sortable[j - 1] = value;
               }
          }
     }

     return sortable;
}
