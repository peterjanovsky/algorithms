#include <assert.h>
#include <stdio.h>

#include "merge_sort.c"

#define SIZE_OF_ARRAY   8

int main()
{
    printf("merge sort\n");

    int sorted[SIZE_OF_ARRAY] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int sortable[SIZE_OF_ARRAY] = { 6, 5, 3, 1, 8, 7, 2, 4 };

    int *result = merge_sort(sortable, 0, 7, "initial");
    for ( int i=-0; i < SIZE_OF_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", sorted[i], result[i]);
        assert( sorted[i] == result[i] );
    }
}
