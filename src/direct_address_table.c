/*
 * direct-address table
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
 *
 *    time complexity
 *      0(1)
 */
typedef int key;
typedef int value;

typedef struct {
    key k;
    value v;
} slot;

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
