#include <limits.h>

#include "heap.h"

int left(int i);
int right(int i);
int parent(int i);
void exchange(heap *h, int x, int y);
void max_heapify(heap *h, int i);
void build_max_heap(heap *h);
void heap_sort(heap *h);
