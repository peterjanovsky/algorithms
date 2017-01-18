#include <limits.h>

#include "heapsort.c"

/*
 * max-priority queue maintains a set of elements, each with an associated
 * value (key)
 *
 * possible applications include
 *   job scheduler
 *     keeps track of the jobs to be performed and their relative priorities,
 *     when a job is finished or interrupted the scheduler selects the
 *     highest-priority job from among those pending by calling extract-max.
 *     the scheduler can add a new job to the queue at any time by calling
 *     insert
 */


/*
 * Function: heap_maximum
 * ----------------------
 * returns the value stored at offset zero within the heap's underlying array,
 * resulting in a running time of O(1)
 *
 * h: heap
 *
 * returns: the heap's maximum value
 */
int heap_maximum(heap *h)
{
    return h->array[0];
}

/*
 * Function: heap_extract_max
 * --------------------------
 * removes and returns the value stored at offset zero within the heap's
 * underlying array, leveraging max_heapify to ensure the heap property is
 * enforced for a running time of O(lg n)
 *
 * h: heap
 *
 * returns: the heap's maximum value
 */
int heap_extract_max(heap *h)
{
    assert(h->size > 0);

    int max = h->array[0];
    h->array[0] = h->array[h->size-1];
    h->size = h->size - 1;
    max_heapify(h, 0);
    return max;
}

/*
 * Function: heap_increase_key
 * ---------------------------
 * assigns the value to the specified offset within the heap's underlying array,
 * ensuring the max-heap property is enforced as increasing the value might
 * violate the property for a running time of O(lg n)
 *
 * h: heap
 *
 * returns: nothing
 */
void heap_increase_key(heap *h, int i, int key)
{
    assert(key > h->array[i]);

    // assign (overwrite) value to specified offset
    h->array[i] = key;

    while((i > 0) && (h->array[parent(i)] < h->array[i]))
    {
        // we have not reached the beginning of the heap's underlying array and
        // the element's parent is smaller
        int temp = parent(i);
        exchange(h, i, temp);
        i = temp;
    }
}

/*
 * Function: max_heap_insert
 * -------------------------
 * adds the key to the heap's underlying array with a running time of O(lg n)
 *
 * h: heap
 *
 * returns: nothing
 */
void max_heap_insert(heap *h, int key)
{
    h->size = h->size + 1;
    h->array[h->size - 1] = INT_MIN;
    heap_increase_key(h, h->size - 1, key);
}
