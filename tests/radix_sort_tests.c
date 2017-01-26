#include <assert.h>
#include <stdio.h>

#include "radix_sort.c"

#define SIZE_OF_ARRAY   10

void test_counting_sort_sub_routine_with_ones()
{
    int expected[SIZE_OF_ARRAY] = { 720, 901, 422, 355, 215, 436, 457, 657, 329, 839 };
    int arr[SIZE_OF_ARRAY] = { 329, 457, 657, 839, 436, 720, 355, 422, 901, 215 };

    printf("ones\n");

    int result[SIZE_OF_ARRAY];
    counting_sort( arr, result, SIZE_OF_ARRAY, 901, ones );
    for ( int i=0; i < SIZE_OF_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", expected[i], result[i]);
        assert( expected[i] == result[i] );
    }
}

void test_counting_sort_sub_routine_with_tens()
{
    int expected[SIZE_OF_ARRAY] = { 901, 215, 720, 422, 329, 436, 839, 355, 457, 657 };
    int arr[SIZE_OF_ARRAY] = { 720, 901, 422, 355, 215, 436, 457, 657, 329, 839 };

    printf("tens\n");

    int result[SIZE_OF_ARRAY];
    counting_sort( arr, result, SIZE_OF_ARRAY, 901, tens );
    for ( int i=0; i < SIZE_OF_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", expected[i], result[i]);
        assert( expected[i] == result[i] );
    }
}

void test_counting_sort_sub_routine_with_hundreds()
{
    int expected[SIZE_OF_ARRAY] = { 215, 329, 355, 422, 436, 457, 657, 720, 839, 901 };
    int arr[SIZE_OF_ARRAY] = { 901, 215, 720, 422, 329, 436, 839, 355, 457, 657 };

    printf("hundreds\n");

    int result[SIZE_OF_ARRAY];
    counting_sort( arr, result, SIZE_OF_ARRAY, 901, hundreds );
    for ( int i=0; i < SIZE_OF_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", expected[i], result[i]);
        assert( expected[i] == result[i] );
    }
}

void test_radix_sort()
{
    int expected[SIZE_OF_ARRAY] = { 215, 329, 355, 422, 436, 457, 657, 720, 839, 901 };
    int arr[SIZE_OF_ARRAY] = { 329, 457, 657, 839, 436, 720, 355, 422, 901, 215 };

    printf("radix sort algorithm\n");

    int result[SIZE_OF_ARRAY];
    radix_sort( arr, result, SIZE_OF_ARRAY, 901 );
    for ( int i=0; i < SIZE_OF_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", expected[i], result[i]);
        assert( expected[i] == result[i] );
    }
}

int main()
{
    printf("radix sort\n");

    test_counting_sort_sub_routine_with_ones();
    test_counting_sort_sub_routine_with_tens();
    test_counting_sort_sub_routine_with_hundreds();

    test_radix_sort();
}
