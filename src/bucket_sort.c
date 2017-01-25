/*
 * Function: insertion_sort
 * ------------------------
 * see "insertion_sort.c" for explanation, this function is a duplicate specific
 * to an array of floating point numbers. within the bucket sort algorithm this
 * the function is used as a sub-routine
 *
 * sortable: array to sort ( signed integers )
 * size: size of sortable array
 *
 * returns: the sorted array
 */
float *insertion_sort(float sortable[], int size)
{
     float key;

     for ( int j=1; j < size; j++ ) {

          key = sortable[j];

          int i = j - 1;
          while ( (i > -1) && (sortable[i] > key) ) {

               sortable[i + 1] = sortable[i];
               i = i - 1;
          }

          sortable[i + 1] = key;
     }

     return sortable;
}

/*
 * Structure: node
 * ---------------
 * a node within a linked list
 */
typedef struct node {
    float value;
    struct node *next;
} node_t;

/*
 * Function: bucket_sort
 * -----------------------
 * places the individual floating-point numbers from the array to be sorted
 * within buckets. the individual buckets are sorted using "insertion sort"
 * as a sorting sub-routine and the results from each bucket are aggregated,
 * comprising the sorted array
 *
 * a: input array to sort ( floating-point numbers )
 * size: size of sortable array
 *
 * returns: sorted array ( floating-point numbers )
 */
float *bucket_sort(float a[], int size)
{
    // temporary storage, essentially this array is an array of linked lists
    struct node *b[size];
    for ( int i=0; i < size; i++ ) {
        b[i] = NULL;
    }

    // traverse the array to be sorted inserting each element its respective bucket.
    for ( int i=0; i < size; i++ ) {

        // linked list node
        struct node *node = (struct node *)malloc(sizeof(node));
        node->value = a[i];
        node->next = NULL;

        /* node's bucket is defined by the integer result from multiplying the
         * offset's value by the array's size
         */
        int offset = (size * a[i]);

        if (b[offset] == NULL) b[offset] = node;
        else {
            /* traverse the linked list until reaching the last node where the
             * new element will be inserted
             */
            struct node *n = b[offset];
            while (n->next != NULL) n = n->next;
            n->next = node;
        }
    }

    for ( int i=0; i < size; i++ ) {

        int offset = 0;
        float temp[size];

        /* insert all nodes within the bucket's linked list at the current offset
         * in the temporary array which will be sorted
         */
        struct node *node = b[i];
        while (node != NULL) {
            temp[offset++] = node->value;
            node = node->next;
        }

        /* call the insertion sort sub-routine and rehydrate the bucket's linked
         * list as the array has been sorted
         */
        float *result = insertion_sort(temp, offset);
        for ( int j=0; j < offset; j++ ) {

            struct node *node = (struct node *)malloc(sizeof(node));
            node->value = result[j];
            node->next = NULL;

            if (j == 0) b[i] = node;
            else {
                struct node *n = b[i];
                while (n->next != NULL) n = n->next;
                n->next = node;
            }
        }
    }

    int offset = 0;
    float *sorted = (float *)malloc(sizeof(float) * size);

    /* traverse the temporary array, buildoing the sorted array from the
     * bucket's linked lists at each offset
     */
    for ( int i=0; i < size; i++ ) {

        struct node *node = b[i];
        while (node != NULL) {
            sorted[offset++] = node->value;
            node = node->next;
        }
    }

    return sorted;
}
