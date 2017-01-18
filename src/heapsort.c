#include <limits.h>

#include "heapsort.h"

/* 
 * heapsort
 *
 * time complexity
 *   O(n lg n)
 *
 * sorts in place, only a constant number of array elements are stored outside
 * the input array at any time
 *
 * example of max-heap
 *
 *             16
 *           /    \
 *         14      10
 *        /  \    /  \
 *       8    7  9    3
 *      / \  /
 *     2  4 1
 *
 * represented as an array
 *
 *          ---------------------------------------------------------------
 * value    |  16 |  14  |  10  |  8  |  7  |  9  |  3  |  2  |  4  |  1  |
 *          ---------------------------------------------------------------
 * offset   |  0  |  1   |  2   |  3  |  4  |  5  |  6  |  7  |  8  |  9  |
 *          ---------------------------------------------------------------
 *
 * max-heap property
 *    for every node i, other than the root the value of the node is at most the
 *    value of its parent
 *      A[PARENT(i)] >= A[i]
 *
 * min-heap property
 *    for every node i, other than the root the value of the node is at minimum the
 *    value of its parent
 *      A[PARENT(i)] <= A[i]
 */


/*
 * Function: left
 * --------------
 * detemine the left child's array offset
 *
 * i: parent's offset
 *
 * returns: left child's offset
 */
int left(int i)
{
    /*
     * shift the binary representation of the integer left by one bit position.
     * as the heap's underlying array utilizes zero-based numbering we must add
     * one (1) to the value computed from the left shift operation to obtain
     * the proper array offset
     *
     * (i << 1) is the same as (2 * 1)
     */
    return (i << 1) + 1;
}

/*
 * Function: right
 * ---------------
 * detemine the right child's array offset
 *
 * i: parent's offset
 *
 * returns: right child's offset
 */
int right(int i)
{
    /*
     * shift the binary representation of the integer left by one bit position
     * and add one (1) as the low-order bit as the heap's underlying array
     * utilizes zero-based numbering we must add one (1) to the value computed
     * from the left shift operation to obtain the proper array offset
     */
    return (left(i) + 1);
}

/*
 * Function: parent
 * ----------------
 * determine the parent's array offset
 *
 * i: child's offset
 *
 * returns: parent's offset
 */
int parent(int i)
{
    /*
     * shift the binary representation of the integer right by one bit position
     * as the heap's underlying array utilizes zero-based numbering we must add
     * one (1) to the value computed from the left shift operation to obtain
     * the proper array offset
     *
     * (i >> 1) is the same as (i / 2)
     */
    if (i == 0) return 0;
    else return ((i - 1) >> 1);
}

/*
 * Function: exchange
 * ------------------
 * swaps the values within the heap's backing array at the specified offets
 *
 * h: heap
 * x: offset of the first number being swapped
 * y: offset of the second number being swapped
 *
 * returns: void (heap parameter is a pointer, swap occurs within backing array)
 */
void exchange(heap *h, int x, int y)
{
    int temp = h->array[x];
    h->array[x] = h->array[y];
    h->array[y] = temp;
}

/*
 * Function: max_heapify
 * ---------------------
 * maintains the heap property, the function assumes the binary trees rooted at
 * LEFT(i) and RIGHT(i) are max-heaps, but that A[i] might be smaller than its
 * children, thus violating the max-heap property. whenever called on a node,
 * the function lets the value at A[i] "float down" in the max-heap ensuring
 * the subtree rooted at the node obey the max-heap property
 *
 * h: heap
 * i: node's index in array
 *
 * returns: void (heap parameter is a pointer)
 */
void max_heapify(heap *h, int i)
{
    int largest = 0;

    /* find the node's children by shifting its array index providing the offset
     * into the array for the left and right children
     *
     * see example of max-heap represented as an array above
     */
    int l = left(i);
    int r = right(i);

    /* within each step store the index of what is determined to be the largest
     * of the following within a local variable
     *    ARRAY[i]
     *    ARRAY[LEFT(i)]
     *    ARRAY[RIGHT(i)]
     *
     * if A[i] is the largest, then the subtree rooted at the node is already a
     * max-heap and the procedure terminates. otherwise one of the two children
     * has the largest element and A[i] is swapped with A[largest], causing the
     * node and its children to satisfy the max-heap property. this routine is
     * recursive as the subtree rooted at largest might violate the max-heap
     */

    /* assign the node's left child's index if the index of the left child is
     * within the array's boundaries and the offset's value is greater than the
     * node's value. otherwise the node might be the largest depending upon the
     * following conditional checks
     */
    if ( (l < h->size) && (h->array[l] > h->array[i]) )
        largest = l;
    else
        largest = i;

    /* assign the node's right child's index if the index of the right child is
     * within the array's boundaries and the offset's value is greater than the
     * node's value
     */
    if ( (r < h->size) && (h->array[r] > h->array[largest]) )
        largest = r;

    if ( largest != i ) {
        /* one of the node's children is larger, swap the values at the specified
         * offsets and ensure tree adheres to max-heap property
         */
        exchange(h, i, largest);
        max_heapify(h, largest);
    }
}

/*
 * Function: build_max_heap
 * ------------------------
 * recursive function which walks the tree ensuring it adheres to the max-heap
 * propery
 *
 * h: heap
 *
 * returns: void (heap parameter is a pointer)
 */
void build_max_heap(heap *h)
{
    // traverse the array backwards starting at the last node with children
    for (int i = (h->length / 2); i >= 0; i--)
        max_heapify(h, i);
}

/*
 * Function: heap_sort
 * -------------------
 * sorts a max-heap in ascending order
 *
 * explanation of running time which is O(n lg n)
 *    call to build_max_heap takes O(n)
 *    each of the n - 1 calls to max_heapify takes O(lg n)
 *
 * h: heap
 *
 * returns: void (heap parameter is a pointer)
 */
void heap_sort(heap *h)
{
    build_max_heap(h);

    for (int i=h->length; i >= 1; i--)
    {
        exchange(h, 0, i);
        h->size = h->size-1;
        max_heapify(h, 0);
    }
}
