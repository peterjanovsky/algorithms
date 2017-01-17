#include <limits.h>

/* 
 * quicksort
 *
 * time complexity (average)
 *   O(n lg n)
 * time complexity (worst-case)
 *   O(n^2)
 */

/*
 * Function: exchange
 * ------------------
 * swaps the values within the array at the specified offets
 *
 * a: array pointer
 * x: offset of the first number being swapped
 * y: offset of the second number being swapped
 *
 * returns: void (array is a pointer)
 */
void exchange(int *a, int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

/*
 * Function: partition
 * -------------------
 * sorts a portion of the array inplace by utilizing a "pivot" value (element's
 * value at the end of the subarray), which is compared against value of the
 * current offset when traversing the subarray. the "pivot" provides a value
 * which is used to determine if the element to which it is being compared should
 * be moved into either the portion of the array representing values less than
 * the "pivot" or the portion representing values greater than the "pivot"
 *
 * a: array to partition
 * p: array offset denoting beginning of subarray
 * r: array offset denoting end of subarray
 *
 * returns: 
 */
int partition(int *a, int p, int r)
{
    // value at end of subarray offset
    int x = a[r-1];
printf("x: %d\n", x);

    // offset immediately before beginning of subarray
    int i = p - 1;
printf("i: %d\n", i);

    // traverse subarray, stopping at the offset prior to the end
    for ( int j=p; j < (r-1); j++ ) {
printf("j: %d a[%d]: %d\n", j, j, a[j]);
        if ( a[j] <= x ) {
            /* the offset's value is less than the subarray's ending offset's value
             * exchange
             */
            i = i + 1;
printf("exchanging a[%d]: %d with a[%d]: %d\n", i+1, a[i], j, a[j]);
            exchange(a, i, j);
        }
    }

printf("exchanging a[%d]: %d with a[%d]: %d\n", i+1, a[i+1], r, a[r]);
    exchange(a, (i + 1), (r - 1));

    return (i + 1);
}

/*
 * Function: quicksort
 * -------------------
 * recursive function which splits the array into subarrays (divide-and-conquer)
 * sorting each subarray based upon the value within a "pivot" element
 *
 * a: array to partition
 * p: array offset denoting beginning of subarray
 * r: array offset denoting end of subarray
 *
 * returns: 
 */
void quicksort(int *a, int p, int r, char *str)
{
printf("quicksort called with p: %d r: %d on %s\n", p, r, str);
    // process when the beginning subarray offset is less than the ending
    // subarray offset. otherwise, this subarray has been sorted
    if ( p < r ) {
        int q = partition(a, p, r);

printf("partition called with p: %d r: %d\n", p, r);
for( int i=0; i < 8; i++ )
    printf("a[%d]: %d    ", i, a[i]);
printf("\n");

        quicksort(a, p, (q - 1), "left");
        quicksort(a, (q + 1), r, "right");
    }
}
