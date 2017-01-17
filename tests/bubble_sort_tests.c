#include <assert.h>
#include <stdio.h>

#include "bubble_sort.c"

#define SIZE_OF_ARRAY   6

int main()
{
    printf("bubble sort\n");

    int sortedBubble[SIZE_OF_ARRAY] = { 1, 2, 3, 4, 5, 6 };
    int sortableBubble[SIZE_OF_ARRAY] = { 2, 5, 4, 6, 3, 1 };

    int *resultBubble = bubble_sort( sortableBubble, SIZE_OF_ARRAY );
    for ( int i=0; i < SIZE_OF_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", sortedBubble[i], resultBubble[i]);
        assert( sortedBubble[i] == resultBubble[i] );
    }
}
