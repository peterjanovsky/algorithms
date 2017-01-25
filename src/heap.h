/*
 * Structure: heap
 * ---------------
 * backed by an array
 */
typedef struct {
    int length;   // number of elements stored within the array
    int size;     // size of the array
    int *array;
} heap;
