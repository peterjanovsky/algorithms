#include <assert.h>
#include <stdio.h>

#include "quicksort.c"

#define SIZE_OF_ARRAY  9

int main()
{
    printf("quicksort\n");

    int expected[SIZE_OF_ARRAY] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int arr[SIZE_OF_ARRAY] = { 6, 5, 1, 3, 8, 4, 7, 9, 2 };

    quicksort(&arr, 0, SIZE_OF_ARRAY, "initial");

    for (int i=0; i < SIZE_OF_ARRAY; i++) {
        printf("offset: %d value: %d expected: %d\n", i, arr[i], expected[i]);
        assert( arr[i] == expected[i] );
    }
}
