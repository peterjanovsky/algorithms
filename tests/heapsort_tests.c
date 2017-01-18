#include <assert.h>
#include <stdio.h>

#include "heapsort.c"

#define SIZE_OF_SMALL_ARRAY   6
#define SIZE_OF_MEDIUM_ARRAY  10
#define SIZE_OF_LARGE_ARRAY   16

/* the following is a quick breakdown of the first 15 numbers in their decimal
 * and binary representations
 *
 * ------------------------------------------------------------------------------------------
 * Decimal  0  1   2    3    4    5    6    7     8     9    10    11    12    13    14    15
 * ------------------------------------------------------------------------------------------
 * Binary   0  1  10   11  100  101  110  111  1000  1001  1010  1011  1100  1101  1110  1111
 * ------------------------------------------------------------------------------------------
 */
void test_left_shift()
{
    int result = left(0);
    printf("shift (left) decimal value of 0 resulting in %d\n", result);
    assert( result == 1 );

    result = left(1);
    printf("shift (left) decimal value of 1 resulting in %d\n", result);
    assert( result == 3 );

    result = left(2);
    printf("shift (left) decimal value of 2 resulting in %d\n", result);
    assert( result == 5 );

    result = left(3);
    printf("shift (left) decimal value of 3 resulting in %d\n", result);
    assert( result == 7 );

    result = left(4);
    printf("shift (left) decimal value of 4 resulting in %d\n", result);
    assert( result == 9 );

    result = left(5);
    printf("shift (left) decimal value of 5 resulting in %d\n", result);
    assert( result == 11 );
}

void test_right_shift()
{
    int result = right(0);
    printf("shift (right) decimal value of 0 resulting in %d\n", result);
    assert( result == 2 );

    result = right(1);
    printf("shift (right) decimal value of 1 resulting in %d\n", result);
    assert( result == 4 );

    result = right(2);
    printf("shift (right) decimal value of 2 resulting in %d\n", result);
    assert( result == 6 );

    result = right(3);
    printf("shift (right) decimal value of 3 resulting in %d\n", result);
    assert( result == 8 );

    result = right(4);
    printf("shift (right) decimal value of 4 resulting in %d\n", result);
    assert( result == 10 );

    result = right(5);
    printf("shift (right) decimal value of 5 resulting in %d\n", result);
    assert( result == 12 );
}

void test_parent()
{
    int result = parent(0);
    printf("shift (parent) decimal value of 0 resulting in %d\n", result);
    assert( result == 0 );

    result = parent(1);
    printf("shift (parent) decimal value of 1 resulting in %d\n", result);
    assert( result == 0 );

    result = parent(2);
    printf("shift (parent) decimal value of 2 resulting in %d\n", result);
    assert( result == 0 );

    result = parent(3);
    printf("shift (parent) decimal value of 3 resulting in %d\n", result);
    assert( result == 1 );

    result = parent(4);
    printf("shift (parent) decimal value of 4 resulting in %d\n", result);
    assert( result == 1 );

    result = parent(5);
    printf("shift (parent) decimal value of 5 resulting in %d\n", result);
    assert( result == 2 );
}

/* Expected array values and offsets
 *
 *          ---------------------------------------------------------------
 * value    |  16 |  14  |  10  |  8  |  7  |  9  |  3  |  2  |  4  |  1  |
 *          ---------------------------------------------------------------
 * offset   |  0  |  1   |  2   |  3  |  4  |  5  |  6  |  7  |  8  |  9  |
 *          ---------------------------------------------------------------
 */
void test_max_heapify()
{
    int expected[10] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
    int arr[10] = { 16, 14, 10, 4, 7, 9, 3, 2, 8, 1 };

    heap h;
    h.length = 9;
    h.size = 10;
    h.array = arr;

    max_heapify(&h, 3);

    printf("max-heap\n");
    for (int i=0; i < h.size; i++) {
        printf("offset: %d value: %d expected: %d\n", i, h.array[i], expected[i]);
        assert( h.array[i] == expected[i] );
    }
}

void test_build_max_heap()
{
    int expected[10] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
    int arr[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    heap h;
    h.length = 9;
    h.size = 10;
    h.array = arr;

    build_max_heap(&h);

    printf("build max-heap\n");
    for (int i=0; i < h.size; i++) {
        printf("offset: %d value: %d expected: %d\n", i, h.array[i], expected[i]);
        assert( h.array[i] == expected[i] );
    }
}

void test_heap_sort()
{
    int expected[10] = { 1, 2, 3, 4, 7, 8, 9, 10, 14, 16 };
    int arr[10] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

    heap h;
    h.length = 9;
    h.size = 10;
    h.array = arr;

    heap_sort(&h);

    printf("sort max-heap\n");

    printf("verify heap size was decremented to a single element\n");
    assert( h.size == 1 );

    for (int i=0; i < 10; i++) {
        printf("offset: %d value: %d expected: %d\n", i, h.array[i], expected[i]);
        assert( h.array[i] == expected[i] );
    }
}

int main()
{
    printf("heapsort\n");

    test_left_shift();

    test_right_shift();

    test_parent();

    test_max_heapify();

    test_build_max_heap();

    test_heap_sort();
}
