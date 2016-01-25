#include <limits.h>

/* 
 * divide-and-conquer
 *
 * time complexity
 *   c2n lg n
 *     lg n stands for log2 n
 *     c2 is a constant which does not depend on n
 *
 * @param sortable array to sort ( signed integers )
 * @param p beginning offset for first subarray
 * @param q ending offset for first subarray and beginning offset for second subarray
 * @param r ending offset for second subarray
 * @return the sorted array
 */
int *merge_sort(int sortable[], int p, int q, int r)
{
     // assign size of left and right arrays
     int leftLength = q - p + 1;
     int rightLength = r - q;

     // declare left and right arrays
     int leftArray[leftLength + 1];
     int rightArray[rightLength + 1];

     // fill left and right arrays
     int i;
     for ( i=0; i < leftLength; i++ ) { leftArray[i] = sortable[p + i]; }

     int j;
     for ( j=0; j < rightLength; j++ ) { rightArray[j] = sortable[q + j + 1]; }

     /*
      * insert sentinels at end of arrays
      *    sentinel is a unique value outside of the range of sortable
      */
     leftArray[leftLength] = INT_MAX;
     rightArray[rightLength] = INT_MAX;

     i = 0;
     j = 0;

     /*
      * traverse array starting at the beginning offset for the first subarray
      *    if left array value is less than or equal to right array value
      *      insert left value into array
      *    else
      *      insert right value into array
      */
     for ( int k=p; k <= r; k++ ) {

          if ( leftArray[i] <= rightArray[j] ) {

               sortable[k] = leftArray[i];
               i = i + 1;

          } else {

               sortable[k] = rightArray[j];
               j = j + 1;
          }
     }

     return sortable;
}
