#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#define RED   1
#define BLACK 0

/*
 * Structure: rb_leaf
 * ------------------
 * key: identifier
 * color: node's color
 * data: pointer to satellite data
 * left: pointer to left child
 * right: pointer to right child
 * parent: pointer to parent
 */
typedef struct rb_leaf {
    int key;
    int color;
    void *data;
    struct rb_leaf *left;
    struct rb_leaf *right;
    struct rb_leaf *parent;
} rb_leaf_t;

/*
 * Structure: rb_tree
 * ------------------
 * root: root node
 * NIL: sentinel node (leaf)
 */
typedef struct rb_tree {
    struct rb_leaf *root;
    struct rb_leaf *NIL;
} rb_tree_t;

#endif
