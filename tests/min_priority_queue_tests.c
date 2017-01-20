#include <assert.h>
#include <stdio.h>

#include "min_priority_queue.c"

#define SIZE_OF_ARRAY  10

/* Expected array values and offsets
 *
 *          -----------------------------------------------------------------------
 * value    |  14  |  32  |  23  |  50  |  53  |  41  |  87  |  64  |  90  |  54  |
 *          -----------------------------------------------------------------------
 * offset   |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |
 *          -----------------------------------------------------------------------
 */
void test_heap_minimum()
{
    int expected[SIZE_OF_ARRAY] = { 14, 32, 23, 50, 53, 41, 87, 64, 90, 54 };
    int arr[SIZE_OF_ARRAY] = { 14, 32, 23, 90, 53, 41, 87, 64, 50, 54 };

    heap h;
    h.length = SIZE_OF_ARRAY - 1;
    h.size = SIZE_OF_ARRAY;
    h.array = arr;

    // ensure heap adheres to min-heap property prior to testing min-priority
    // queue functions
    build_min_heap(&h);

    int min = heap_minimum(&h);

    printf("verify minimum heap value is 14\n");
    assert( min == 14 );

    for (int i=0; i < h.size; i++) {
        printf("offset: %d value: %d expected: %d\n", i, h.array[i], expected[i]);
        assert( h.array[i] == expected[i] );
    }
}

void test_heap_extract_min()
{
    int expected[SIZE_OF_ARRAY] = { 23, 32, 41, 50, 53, 54, 87, 64, 90 };
    int arr[SIZE_OF_ARRAY] = { 14, 32, 23, 90, 53, 41, 87, 64, 50, 54 };

    heap h;
    h.length = SIZE_OF_ARRAY - 1;
    h.size = SIZE_OF_ARRAY;
    h.array = arr;

    // ensure heap adheres to min-heap property prior to testing min-priority
    // queue functions
    build_min_heap(&h);

    int min = heap_extract_min(&h);

    printf("extract minimum heap value\n");
    printf("verify heap size was decremented by a single element\n");
    assert( h.size == h.length );

    printf("verify minimum heap value is 14\n");
    assert( min == 14 );

    for (int i=0; i < h.size; i++) {
        printf("offset: %d value: %d expected: %d\n", i, h.array[i], expected[i]);
        assert( h.array[i] == expected[i] );
    }
}

void test_heap_decrease_key()
{
    int expected[SIZE_OF_ARRAY] = { 14, 15, 23, 32, 53, 41, 87, 64, 50, 54 };
    int arr[SIZE_OF_ARRAY] = { 14, 32, 23, 90, 53, 41, 87, 64, 50, 54 };

    heap h;
    h.length = SIZE_OF_ARRAY - 1;
    h.size = SIZE_OF_ARRAY;
    h.array = arr;

    // ensure heap adheres to min-heap property prior to testing min-priority
    // queue functions
    build_min_heap(&h);

    // decrease the value at array offset 8 from 90 to 15
    heap_decrease_key(&h, 8, 15);

    printf("decrease key\n");

    for (int i=0; i < h.size; i++) {
        printf("offset: %d value: %d expected: %d\n", i, h.array[i], expected[i]);
        assert( h.array[i] == expected[i] );
    }
}

int main()
{
    printf("min-priority queue\n");

    test_heap_minimum();

    test_heap_extract_min();

    test_heap_decrease_key();
}
