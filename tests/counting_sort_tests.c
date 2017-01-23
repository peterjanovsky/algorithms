#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "counting_sort.c"

#define SIZE_OF_ARRAY   8

int main()
{
    printf("counting sort\n");

    int expected[SIZE_OF_ARRAY] = { 0, 0, 2, 2, 3, 3, 3, 5 };
    int arr[SIZE_OF_ARRAY] = { 2, 5, 3, 0, 2, 3, 0, 3 };

    int *result;
    result = (int *)malloc(SIZE_OF_ARRAY);
    memset(result, 0, SIZE_OF_ARRAY);

    counting_sort( arr, result, SIZE_OF_ARRAY, 5 );
    for ( int i=0; i < SIZE_OF_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", expected[i], result[i]);
        assert( expected[i] == result[i] );
    }

    free(result);
}
