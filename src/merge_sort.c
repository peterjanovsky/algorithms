#include <limits.h>

/*
 * Function: merge
 * ---------------
 * create two temporary arrays with sentinel values in the last position using
 * the provided array offsets to extract values from the original array. next
 * sort the original array by comparing the values in the temporary arrays. if
 * the element in the left array is less than or equal to the element in the
 * right array then assign the element in the left array to array being
 * returned, otherwise assign the value from the right array.
 *
 * a: array to sort ( signed integers )
 * p: beginning offset for first subarray
 * q: ending offset for first subarray and beginning offset for second subarray
 * r: ending offset for second subarray
 *
 * returns: the sorted array
 */
int *merge(int a[], int p, int q, int r, char *text)
{
     // assign size of left and right arrays
     int leftLength = q - p + 1;
     int rightLength = r - q;

     // declare left and right arrays
     int leftArray[leftLength + 1];
     int rightArray[rightLength + 1];

     // fill left and right arrays
     int i;
     for ( i=0; i < leftLength; i++ ) { leftArray[i] = a[p + i]; }

     int j;
     for ( j=0; j < rightLength; j++ ) { rightArray[j] = a[q + j + 1]; }

     /*
      * insert sentinels at end of arrays
      *    sentinel is a unique value outside of the range of sortable array
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

               a[k] = leftArray[i];
               i = i + 1;

          } else {

               a[k] = rightArray[j];
               j = j + 1;
          }
     }

     return a;
}

/*
 * Function: merge_sort
 * --------------------
 * sorts an array by recursively splitting the array in two (divide-and-conquer)
 * and merging
 *
 * time complexity
 *   c2n lg n
 *     lg n stands for log2 n
 *     c2 is a constant which does not depend on n
 *
 * a: array to sort ( signed integers )
 * p: beginning array offset
 * r: ending array offset
 *
 * returns: the sorted array
 */
int *merge_sort(int a[], int p, int r, char *text)
{
    if ( p < r ) {
        int q = (p + r) / 2;
        merge_sort(a, p, q, "first");
        merge_sort(a, (q + 1), r, "second");

        merge(a, p, q, r, text);
    }

    return a;
}
