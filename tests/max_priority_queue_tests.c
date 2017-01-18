#include <assert.h>
#include <stdio.h>

#include "max_priority_queue.c"

#define SIZE_OF_ARRAY  10

/* Expected array values and offsets
 *
 *          ---------------------------------------------------------------
 * value    |  16 |  14  |  10  |  8  |  7  |  9  |  3  |  2  |  4  |  1  |
 *          ---------------------------------------------------------------
 * offset   |  0  |  1   |  2   |  3  |  4  |  5  |  6  |  7  |  8  |  9  |
 *          ---------------------------------------------------------------
 */
void test_heap_maximum()
{
    int expected[SIZE_OF_ARRAY] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
    int arr[SIZE_OF_ARRAY] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    heap h;
    h.length = SIZE_OF_ARRAY - 1;
    h.size = SIZE_OF_ARRAY;
    h.array = arr;

    // ensure heap adheres to max-heap property prior to testing max-priority
    // queue functions
    build_max_heap(&h);

    int max = heap_maximum(&h);

    printf("verify maximum heap value is 16\n");
    assert( max == 16 );

    for (int i=0; i < h.size; i++) {
        printf("offset: %d value: %d expected: %d\n", i, h.array[i], expected[i]);
        assert( h.array[i] == expected[i] );
    }
}

void test_heap_extract_max()
{
    int expected[SIZE_OF_ARRAY] = { 14, 10, 8, 7, 9, 3, 2, 4, 1 };
    int arr[SIZE_OF_ARRAY] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    heap h;
    h.length = SIZE_OF_ARRAY - 1;
    h.size = SIZE_OF_ARRAY;
    h.array = arr;

    // ensure heap adheres to max-heap property prior to testing max-priority
    // queue functions
    build_max_heap(&h);

    int max = heap_extract_max(&h);

    printf("extract maximum heap value\n");

    printf("verify heap size was decremented by a single element\n");
    assert( h.size == h.length );

    printf("verify maximum heap value is 16\n");
    assert( max == 16 );

    for (int i=0; i < h.size; i++) {
        printf("offset: %d value: %d expected: %d\n", i, h.array[i], expected[i]);
        //assert( h.array[i] == expected[i] );
    }
}

void test_heap_increase_key()
{
    //int expected[SIZE_OF_ARRAY] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
    int expected[SIZE_OF_ARRAY] = { 16, 15, 10, 14, 7, 9, 3, 2, 8, 1 };
    int arr[SIZE_OF_ARRAY] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    heap h;
    h.length = SIZE_OF_ARRAY - 1;
    h.size = SIZE_OF_ARRAY;
    h.array = arr;

    // ensure heap adheres to max-heap property prior to testing max-priority
    // queue functions
    build_max_heap(&h);

    // increase the value at array offset 8 from 4 to 15
    heap_increase_key(&h, 8, 15);

    printf("increase key\n");

    for (int i=0; i < h.size; i++) {
        printf("offset: %d value: %d expected: %d\n", i, h.array[i], expected[i]);
        //assert( h.array[i] == expected[i] );
    }
}

int main()
{
    printf("max-priority queue\n");

    test_heap_maximum();

    test_heap_extract_max();

    test_heap_increase_key();
}
