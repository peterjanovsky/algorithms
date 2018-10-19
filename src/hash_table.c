#include <stdlib.h>
#include <string.h>

/*
 * hash table
 * -------------------
 *    supports these dictionary operations on an array
 *      insert, search and delete
 *    array positions (slots) correspond to a key in the universe, with each
 *    slot pointing to an element in the set
 *      key -> satellite data
 *    when to use direct addressing
 *      when we can afford to allocate an array which has one position for
 *      every possible key
 *    when to use a hash table
 *      when the number of keys stored is small relative to the total number
 *      of possible keys, as the hash table typically uses an array of size
 *      proportional to the number of keys actually stored
 *      collision
 *        when two keys hash to the same slot
 *      chaining
 *        all elements which hash to the same slot are stored within a linked
 *        list
 *
 *    time complexity
 *      0(1)
 */
typedef char *key_t;
typedef void *value_t;

typedef struct node_s node_t;
struct node_s {
    key_t key;
    value_t value;
    node_t *next;
};

node_t *
linked_list_create()
{
    node_t *node;
    node = (node_t *)malloc(sizeof(node_t));
    //node->value = (value_t *)malloc(sizeof(value_t));
    node->next = NULL;
    return node;
}

void
linked_list_node_destroy(node_t *node)
{
    if (node->next != NULL) {
        linked_list_node_destroy(node->next);
    }
    free(node->key);
    free(node->value);
    free(node);
}

void
linked_list_destroy(node_t *node)
{
    if (node != NULL) {
        linked_list_node_destroy(node);
    }
}

void
linked_list_node_insert(node_t *node, key_t key, value_t value)
{
    while (node->next != NULL) {
        node = node->next;
    }

    node_t *node_new;
    node_new = (node_t *)malloc(sizeof(node_t));
    node_new->key = key;
    node_new->value = value;
    node_new->next = NULL;

    node->next = node_new;
}

void
linked_list_node_remove(node_t *pnode, node_t *cnode, key_t key)
{
    if (strcmp(cnode->key, key) == 0) {
        // raassign current node's next node
        pnode->next = cnode->next;
        // destroy current node
        free(cnode->key);
        free(cnode->value);
        free(cnode);
    } else {
        // recursive search
        if (cnode->next != NULL) {
            linked_list_node_remove(cnode, cnode->next, key);
        }
    }
}

void
linked_list_remove(node_t *node, key_t key)
{
    if (node != NULL) {
        linked_list_node_remove(NULL, node, key);
    }
}

typedef struct hashtable_s hashtable_t;
struct hashtable_s {
    int size;
    node_t **nodes;
};

hashtable_t *
hashtable_create(int size)
{
    hashtable_t *htbl;
    htbl = (hashtable_t *)malloc(sizeof(hashtable_t));
    htbl->size = size;
    htbl->nodes = (node_t **)malloc(sizeof(node_t) * size);
    for (int i=0; i < size; i++) {
        htbl->nodes[i] = NULL;
    }
    return htbl;
}

void
hashtable_destroy(hashtable_t *htbl)
{
    if (htbl != NULL) {
        if (htbl->nodes != NULL) {
            for (int i=0; i < htbl->size; i++) {
                linked_list_destroy(htbl->nodes[i]);
            }
        }
        free(htbl);
    }
}

void
hashtable_insert(hashtable_t *htbl, key_t key, value_t value)
{
    
}

/*
void chained_hash_insert(slot table[], slot_t slot)
{
    table[
    insert x at the head of list T[h(x.key)]
}

chained_hash_search(slot table[], slot_t slot)
{
    search for an element with key k in list T[h(k)]
}

chained_hash_delete(slot table[], slot_t slot)
{
    delete x from the list T[h(x.key)]
}

slot *direct_address_search(slot table[], key k)
{
    return &table[k];
}

void direct_address_insert(slot table[], slot kv)
{
    table[kv.k] = kv;
}

void direct_address_delete(slot table[], slot kv)
{
    //table[kv.key] = NULL;
}
*/
