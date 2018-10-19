#include <assert.h>
#include <stdio.h>

#include "find_maximum_subarray.c"

#define SIZE_OF_SMALL_ARRAY   6
#define SIZE_OF_MEDIUM_ARRAY  10
#define SIZE_OF_LARGE_ARRAY   16

int main()
{
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
/*

    tuple tupMax = find_max_subarray( sortableMax, 0, 6 );
    printf("tuple max_left: %d max_right: %d sum: %d\n", tupMax.max_left, tupMax.max_right, tupMax.sum);
    assert( tupMax.max_left == 1 );
    assert( tupMax.max_right == 5 );
    assert( tupMax.sum == 12 );
*/
}
