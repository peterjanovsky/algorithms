#include <assert.h>
#include <stdio.h>

#include "insertion_sort.c"
#include "merge_sort.c"
#include "bubble_sort.c"
#include "find_maximum_subarray.c"

#define SIZE_OF_SMALL_ARRAY   6
#define SIZE_OF_MEDIUM_ARRAY  10
#define SIZE_OF_LARGE_ARRAY   16

int main()
{
    printf("insertion sort\n");

    int sorted[SIZE_OF_SMALL_ARRAY] = { 1, 2, 3, 4, 5, 6 };
    int sortable[SIZE_OF_SMALL_ARRAY] = { 5, 2, 4, 6, 1, 3 };

    int *result = insertion_sort( sortable, SIZE_OF_SMALL_ARRAY );
    for ( int i=0; i < SIZE_OF_SMALL_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", sorted[i], result[i]);
        assert( sorted[i] == result[i] );
    }

    printf("merge sort\n");

    int sortedMerge[SIZE_OF_LARGE_ARRAY] = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 2, 3, 4, 5, 6, 7 };
    int sortableMerge[SIZE_OF_LARGE_ARRAY] = { 1, 2, 3, 4, 5, 6, 7, 8, 2, 4, 5, 7, 1, 2, 3, 6 };

    int *resultMerge = merge_sort( sortableMerge, 8, 11, 15);
    for ( int i=-0; i < SIZE_OF_LARGE_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", sortedMerge[i], resultMerge[i]);
        assert( sortedMerge[i] == resultMerge[i] );
    }

    printf("bubble sort\n");

    int sortedBubble[SIZE_OF_SMALL_ARRAY] = { 1, 2, 3, 4, 5, 6 };
    int sortableBubble[SIZE_OF_SMALL_ARRAY] = { 2, 5, 4, 6, 3, 1 };

    int *resultBubble = bubble_sort( sortableBubble, SIZE_OF_SMALL_ARRAY );
    for ( int i=0; i < SIZE_OF_SMALL_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", sortedBubble[i], resultBubble[i]);
        assert( sortedBubble[i] == resultBubble[i] );
    }

    printf("maximum crossing subarray\n");

    int sortableCrossingSmall[SIZE_OF_SMALL_ARRAY] = { -6, 5, 2, -3, 7, 1 };

    tuple tupSmall = find_max_crossing_subarray( sortableCrossingSmall, 0, 3, 6 );
    printf("tuple max_left: %d max_right: %d sum: %d\n", tupSmall.max_left, tupSmall.max_right, tupSmall.sum);
    assert( tupSmall.max_left == 1 );
    assert( tupSmall.max_right == 5 );
    assert( tupSmall.sum == 12 );

    int sortableCrossingMedium[SIZE_OF_MEDIUM_ARRAY] = { -6, 5, 2, -3, 7, 1, -5, 8, -4, -9 };

    tuple tupMedium = find_max_crossing_subarray( sortableCrossingMedium, 0, 5, 10 );
    printf("tuple max_left: %d max_right: %d sum: %d\n", tupMedium.max_left, tupMedium.max_right, tupMedium.sum);
    assert( tupMedium.max_left == 1 );
    assert( tupMedium.max_right == 7 );
    assert( tupMedium.sum == 15 );

    printf("maximum subarray\n");

    int sortableSingleElem[1] = { -6 };

    tuple tupSingleElem = find_max_subarray( sortableSingleElem, 0, 0 );
    printf("tuple max_left: %d max_right: %d sum: %d\n", tupSingleElem.max_left, tupSingleElem.max_right, tupSingleElem.sum);
    assert( tupSingleElem.max_left == 0 );
    assert( tupSingleElem.max_right == 0 );
    assert( tupSingleElem.sum == -6 );

    int sortableMax[SIZE_OF_SMALL_ARRAY] = { -6, 5, 2, -3, 7, 1 };

    tuple tupMax = find_max_subarray( sortableMax, 0, 6 );
    printf("tuple max_left: %d max_right: %d sum: %d\n", tupMax.max_left, tupMax.max_right, tupMax.sum);
    assert( tupMax.max_left == 1 );
    assert( tupMax.max_right == 5 );
    assert( tupMax.sum == 12 );
}
