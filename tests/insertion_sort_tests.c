#include <assert.h>
#include <stdio.h>

#include "insertion_sort.c"
#include "merge_sort.c"

#define SIZE_OF_SMALL_ARRAY   6
#define SIZE_OF_LARGE_ARRAY   16

int main()
{
     printf("insertion sort\n");

     int sorted[SIZE_OF_SMALL_ARRAY] = { 1, 2, 3, 4, 5, 6 };
     int sortable[SIZE_OF_SMALL_ARRAY] = { 5, 2, 4, 6, 1, 3 };

     int *result = insertion_sort( sortable, SIZE_OF_SMALL_ARRAY );
     for ( int i=0; i < SIZE_OF_SMALL_ARRAY; i++ ) {

          printf("expected: %d actual: %d\n", sorted[i], result[i]);
          assert( sorted[i] == result[i] );
     }

     printf("merge sort\n");

     int sortedMerge[SIZE_OF_LARGE_ARRAY] = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 2, 3, 4, 5, 6, 7 };
     int sortableMerge[SIZE_OF_LARGE_ARRAY] = { 1, 2, 3, 4, 5, 6, 7, 8, 2, 4, 5, 7, 1, 2, 3, 6 };

     int *resultMerge = merge_sort( sortableMerge, 8, 11, 15);
     for ( int i=-0; i < SIZE_OF_LARGE_ARRAY; i++ ) {

          printf("expected: %d actual: %d\n", sortedMerge[i], resultMerge[i]);
          assert( sortedMerge[i] == resultMerge[i] );
     }
}
