/*
 * Structure: leaf
 * ---------------
 * key: identifier
 * data: pointer to satellite data
 * left: pointer to left child
 * right: pointer to right child
 * parent: pointer to parent
 */
typedef struct leaf {
    int key;
    void *data;
    struct leaf *left;
    struct leaf *right;
    struct leaf *parent;
} leaf_t;

/*
 * Structure: tree
 * ---------------
 * root: root node (leaf)
 */
typedef struct tree {
    struct leaf *root;
} tree_t;
