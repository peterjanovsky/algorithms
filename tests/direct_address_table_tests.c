#include <assert.h>
#include <stdio.h>

#include "direct_address_table.c"

#define SIZE_OF_SMALL_ARRAY   6
#define SIZE_OF_MEDIUM_ARRAY  10
#define SIZE_OF_LARGE_ARRAY   16

int main()
{
    printf("direct address table\n");

    slot s1;
    s1.k = 0;
    s1.v = 1;

    slot s2;
    s2.k = 1;
    s2.v = 2;

    slot s3;
    s3.k = 2;
    s3.v = 3;

    slot table[3];
    direct_address_insert(table, s1);
    direct_address_insert(table, s2);
    direct_address_insert(table, s3);

    slot *s = direct_address_search(table, 0);
    printf("expected: %d actual: %d\n", 1, s->v);

    s = direct_address_search(table, 1);
    printf("expected: %d actual: %d\n", 2, s->v);

    s = direct_address_search(table, 2);
    printf("expected: %d actual: %d\n", 3, s->v);
/*
    int sortedMerge[SIZE_OF_LARGE_ARRAY] = { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 2, 3, 4, 5, 6, 7 };
    int sortableMerge[SIZE_OF_LARGE_ARRAY] = { 1, 2, 3, 4, 5, 6, 7, 8, 2, 4, 5, 7, 1, 2, 3, 6 };

    int *resultMerge = merge_sort( sortableMerge, 8, 11, 15);
    for ( int i=-0; i < SIZE_OF_LARGE_ARRAY; i++ )
    {
        printf("expected: %d actual: %d\n", sortedMerge[i], resultMerge[i]);
        assert( sortedMerge[i] == resultMerge[i] );
    }
*/
}
