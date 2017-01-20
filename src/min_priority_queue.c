#include <limits.h>

#include "heapsort.c"

/*
 * min-priority queue maintains a set of elements, each with an associated
 * value (key)
 *
 * possible applications include
 *   event-driven simulator
 *     items in the queue are events to be simulated, each with an associated
 *     time of occurrence serving as its key. events must be simulated in order
 *     of their time of occurrence, because the simulation of an event can cause
 *     events to be simulated in the future. the simulation program calls
 *     extract-min at each step to choose the next event to simulate and insert
 *     to add a new event to the queue at any time
 */


/*
 * Function: heap_minimum
 * ----------------------
 * returns the value stored at offset zero within the heap's underlying array,
 * resulting in a running time of O(1)
 *
 * h: heap
 *
 * returns: the heap's minimum value
 */
int heap_minimum(heap *h)
{
    return h->array[0];
}

/*
 * Function: heap_extract_min
 * --------------------------
 * removes and returns the value stored at offset zero within the heap's
 * underlying array, leveraging min_heapify to ensure the heap property is
 * enforced for a running time of O(lg n)
 *
 * h: heap
 *
 * returns: the heap's minimum value
 */
int heap_extract_min(heap *h)
{
    assert(h->size > 0);

    int min = h->array[0];
    h->array[0] = h->array[h->size-1];
    h->size = h->size - 1;
    min_heapify(h, 0);

    return min;
}

/*
 * Function: heap_decrease_key
 * ---------------------------
 * assigns the value to the specified offset within the heap's underlying array,
 * ensuring the min-heap property is enforced as decreasing the value might
 * violate the property for a running time of O(lg n)
 *
 * h: heap
 * i: offset
 * key: value to insert at offset
 *
 * returns: nothing
 */
void heap_decrease_key(heap *h, int i, int key)
{
    assert(key < h->array[i]);

    h->array[i] = key;
    while((i > 0) && (h->array[parent(i)] > h->array[i]))
    {
        int temp = parent(i);
        exchange(h, i, temp);
        i = temp;
    }
}

/*
 * Function: min_heap_insert
 * -------------------------
 * adds the key to the heap's underlying array with a running time of O(lg n)
 *
 * h: heap
 * key: key to insert
 *
 * returns: nothing
 */
void min_heap_insert(heap *h, int key)
{
    h->size = h->size + 1;
    h->array[h->size - 1] = INT_MAX;
    heap_decrease_key(h, h->size - 1, key);
}
