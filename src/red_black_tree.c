#include <limits.h>

#include "red_black_tree.h"

/******************************************************************************
 * red-black tree
 *   binary search tree with one extra bit of storage per node. its color,
 *   which can be either RED or BLACK. it is one of many search-tree schemes
 *   that are "balanced" in order to guarantee basic dynamic operations in the
 *   worse case take O(lg n)
 *
 *   constraining the node colors leads to the tree being approximately
 *   balanced
 *
 *   black-height: bh(x)
 *     number of black nodes on any simple path from, but not including, a
 *     node x down to a leaf
 *
 *   rotation
 *     local operation in a search tree which preserves the binary-search-tree
 *     property
 *
 *   rotation types
 *     left rotation
 *       in performing a left rotation on node x, we assume its right child
 *       is not NIL. pivoting around the link from x to y, making y the new
 *       root of the subtree with x as y's left child and y's left child as
 *       x's right child
 *
 *     right rotation
 *       
 *
 * time complexity
 *   baasic operations take time proportional to the height of the tree
 *     O(lg n) worst-case time
 *   if the tree is a linear chain of n nodes
 *     O(n) worst-case time
 *
 * example of binary search tree
 *
 *             15
 *           /    \
 *          6      18
 *        /  \    /  \
 *       3    7  17    20
 *      / \    \
 *     2   4   13
 *             /
 *            9
 *
 * red-black tree properties
 *    - every node is either red or black
 *    - root is black
 *    - every leaf is black
 *    - if a node is red, then both of its children are black
 *    - for each node, all simple pathsfrom the node to descendent leaves
 *      contain the same number of black nodes
 *****************************************************************************/


/*
 * Function: left-rotate
 * ---------------------
 *
 *
 * t: pointer to tree
 * x: pointer to node
 *
 * returns: nothing (void)
 */
void left_rotate(struct rb_tree *t, struct rb_leaf *x)
{
    struct rb_leaf *y = x->right;

    x->right = y->left;

    if ( y->left != t->root ) {

        y->left->parent = x;
    }

    y->parent = x->parent;

    if ( x->parent == t->root ) {

        t->root = y;

    } else if ( x == x->parent->left ) {

        x->parent->left = y;

    } else {

        x->parent->right = y;
    }

    y->left = x;

    x->parent = y;
}

/*
 * Function: right-rotate
 * ----------------------
 *
 *
 * t: pointer to tree
 * x: pointer to node
 *
 * returns: nothing (void)
 */
void right_rotate(struct rb_tree *t, struct rb_leaf *x)
{
    struct rb_leaf *y = x->left;

    x->left = y->right;

    if ( y->right != t->root ) {

        y->right->parent = x;
    }

    y->parent = x->parent;

    if ( x->parent == t->root ) {

        t->root = y;

    } else if ( x == x->parent->right ) {

        x->parent->right = y;

    } else {

        x->parent->left = y;
    }

    y->right = x;

    x->parent = y;
}

void rb_insert_fixup(struct rb_tree *t, struct rb_leaf *z)
{
    while ( z->parent->color == RED ) {

        if ( z->parent == z->parent->parent->left ) {

            struct rb_leaf *y = z->parent->parent->right;

            if ( y->color == RED ) {

                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = BLACK;
                z = z->parent->parent;

            } else if ( z == z->parent->right ) {

                z = z->parent;
                left_rotate(t, z);

                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(t, z->parent->parent);

            }

        } else {
            
        }
    }
}

void rb_tree_insert(struct rb_tree *t, struct rb_leaf *x)
{
    struct rb_leaf *y = t->NIL;

    struct rb_leaf *z = t->root;

    while ( x != t->NIL ) {

        y = x;
        if ( z->key < x->key ) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if ( y == t->NIL ) {
        t->root = z;
    } else if ( x->key < y->key ) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->left = t->NIL;
    z->right = t->NIL;
    z->color = RED;

    rb_insert_fixup(t, z);
}
