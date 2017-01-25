#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bucket_sort.c"

#define SIZE_OF_ARRAY   10

int main()
{
    printf("bucket sort\n");

    float expected[SIZE_OF_ARRAY] = { .12, .17, .21, .23, .26, .39, .68, .72, .78, .94 };
    float arr[SIZE_OF_ARRAY] = { .78, .17, .39, .26, .72, .94, .21, .12, .23, .68 };

    float *result = bucket_sort( arr, SIZE_OF_ARRAY );
    for ( int i=0; i < SIZE_OF_ARRAY; i++ )
    {
        printf("expected: %f actual: %f\n", expected[i], result[i]);
        assert( expected[i] == result[i] );
    }
}
