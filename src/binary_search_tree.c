#include <limits.h>

#include "binary_search_tree.h"

/*
 * binary search tree
 *   binary tree in which every node fits a specific ordering property. where
 *   a binary tree is defined as a tree in which each node has up to two
 *   children.
 *
 *   a node is called a "leaf" if it has no children
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
 * binary-search-tree property
 *    for node x
 *      if y is a node in the left subtree of x, then 
 *          y.key <= x.key
 *      if y is a node in the right subtree of x, then
 *          y.key >= x.key
 */


/*
 * Function: inorder_tree_walk
 * ---------------------------
 * prints the tree's nodes ordered by key
 *
 * x: pointer to tree's root node
 *
 * returns: nothing (void)
 */
void inorder_tree_walk(struct leaf *x)
{
    /* leverage divide-and-conquer to recursively walk down the tree
     * traversing the left and right subtrees
     */
    if ( x != NULL ) {
        // left subtree
        inorder_tree_walk(x->left);

        printf("node key: %d\n", x->key);

        // right subtree
        inorder_tree_walk(x->right);
    }
}

/*
 * Function: inorder_tree_walk
 * ---------------------------
 * prints the tree's nodes beginning at the root traversing the left and right
 * subtrees
 *
 * x: pointer to tree's root node
 *
 * returns: nothing (void)
 */
void tree_walk(struct leaf *x, const char *tpe)
{
    /* leverage divide-and-conquer to recursively walk down the tree
     * traversing the left and right subtrees
     */
    if ( x != NULL ) {

        printf("%s node key: %d\n", tpe, x->key);

        // left subtree
        tree_walk(x->left, "left");
        // right subtree
        tree_walk(x->right, "right");
    }
}

/*
 * Function: tree_search
 * ---------------------
 * recursively traverses the tree to find the node specified by the key, NULL
 * is returned if the key does not exist within the tree
 *
 * time complexity
 *    O(h), where h is the height of the tree
 *
 * x: pointer to tree's root node
 * k: key
 *
 * returns: pointer to node
 */
struct leaf *tree_search(struct leaf *x, int k)
{
    if ( ( x == NULL ) || ( k == x->key ) ) {
        // the keys are equal or the key doesn't exist within the tree
        return x;
    }

    if ( k < x->key ) {

        // the key might exist within the left subtree
        return tree_search(x->left, k);

    } else {

        // the key might exist within the right subtree
        return tree_search(x->right, k);
    }
}

/*
 * Function: iterative_tree_search
 * -------------------------------
 * iteratively traverses the tree to find the node specified by the key, NULL
 * is returned if the key does not exist within the tree
 *
 * x: pointer to tree's root node
 * k: key
 *
 * returns: pointer to node
 */
struct leaf *iterative_tree_search(struct leaf *x, int k)
{
    while ( ( x != NULL ) && ( k != x->key ) ) {

        if ( k < x->key ) {

            // the key might exist within the left subtree
            x = x->left;

        } else {

            // the key might exist within the right subtree
            x = x->right;
        }
    }

    return x;
}

/*
 * Function: tree_minimum
 * ----------------------
 * follows the left child pointers from the tree's root until encountering NIL
 *
 * time complexity
 *    O(h), where h is the height of the tree
 *
 * x: pointer to tree's root node
 *
 * returns: pointer to minimum node
 */
struct leaf *tree_minimum(struct leaf *x)
{
    while ( x->left != NULL ) {
        x = x->left;
    }

    return x;
}

/*
 * Function: tree_maximum
 * ----------------------
 * follows the right child pointers from the tree's root until encountering NIL
 *
 * time complexity
 *    O(h), where h is the height of the tree
 *
 * x: pointer to tree's root node
 *
 * returns: pointer to maximum node
 */
struct leaf *tree_maximum(struct leaf *x)
{
    while ( x->right != NULL ) {
        x = x->right;
    }

    return x;
}

/*
 * Function: tree_successor
 * ------------------------
 * finds the node's successor in the sorted order determined by an inorder tree
 * walk. if all keys are distinct, the successor of a node x is the node with
 * the smallest key greater than x.key. the structure of a binary search tree
 * allows us to determine the successor of a node without ever comparing keys
 *
 * time complexity
 *    O(h), where h is the height of the tree
 *
 * x: pointer to a node within the binary search tree
 *
 * returns: pointer to node's successor
 */
struct leaf *tree_successor(struct leaf *x)
{
    /* if the right subtree of the given node is nonempty, the successor of the
     * node is the leftmost node in the right subtree
     */
    if ( x->right != NULL )
        return tree_minimum(x->right);

    struct leaf *y = x->parent;

    /* walk up the tree to find the successor, validating the node's parent is
     * not NULL and its right child is the node
     */
    while ( ( y != NULL ) && ( x == y->right ) ) {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
 * Function: tree_insert
 * ---------------------
 * traverse the tree searching for the appropriate subtree to place the node
 *
 * time complexity
 *    O(h), where h is the height of the tree
 *
 * t: pointer to tree
 * z: pointer to node
 *
 * returns: nothing (void)
 */
void tree_insert(struct tree *t, struct leaf *z)
{
    struct leaf *y = NULL;
    struct leaf *x = t->root;

    /* traverse tree beginning at root node tracing a downward path searching
     * for a NIL which will be replaced with the node
     */
    while ( x != NULL ) {

        // assign the current node to the temporary node variable
        y = x;

        if ( z->key < x->key ) {

            // the node's key belongs within the left subtree
            x = x->left;

       }  else {

            // the node's key belongs within the right subtree
            x = x->right;
        }
    }

    /* assign the last node discovered from tracing the downward path through
     * the tree as the parent of the node to be inserted into the tree
     */
    z->parent = y;

    if ( y == NULL ) {

        // this is the first node being placed within the tree
        t->root = z;

    } else if ( z->key < y->key ) {

        // the node is within the parent's left subtree
        y->left = z;

    } else {

        // the node is within the parent's right subtree
        y->right = z;
    }
}

/*
 * Function: transplant
 * --------------------
 * replaces the node within the appropriate subtree
 *
 * t: pointer to tree
 * u: pointer to node which will be replaced
 * v: pointer to new node
 *
 * returns: nothing (void)
 */
void transplant(struct tree *t, struct leaf *u, struct leaf *v)
{
    if ( u->parent == NULL ) {

        // this is the root node within the tree
        t->root = v;

    } else if ( u == u->parent->left ) {

        // node is the left child of its parent, replace node
        u->parent->left = v;

    } else {

        // node is the right child of its parent, replace node
        u->parent->right = v;
    }

    if ( v != NULL ) {

        // assign parent node
        v->parent = u->parent;
    }
}

/*
 * Function: tree_delete
 * ---------------------
 *
 * time complexity
 *    O(h), where h is the height of the tree
 *
 * t: pointer to tree
 * z: pointer to node
 *
 * returns: nothing (void)
 */
void tree_delete(struct tree *t, struct leaf *z)
{
    struct leaf *y = NULL;

    if ( z->left == NULL ) {

        /* node doesn't have a left child. replace the node by its right child,
         * which might be NIL
         */
        transplant(t, z, z->right);

    } else if ( z->right == NULL ) {

        /* node has a left child but not a right child. replace the node by its
         * left child
         */
        transplant(t, z, z->left);

    } else {

        /* node has both left and right children. determine the inorder
         * successor node from the right subtree. as the node has a nonempty
         * right subtree, its successor is the smallest node within the subtree
         */
        y = tree_minimum(z->right);

        /* sample tree
         *
         *           q
         *           |
         *           z
         *         /   \
         *        l     r
         *             /
         *            y
         *             \
         *              x
         */
        if ( y->parent != z ) {

            /* replace the successor with its right node
             *
             *           q
             *           |
             *           z
             *         /   \
             *        l     r
             *             /
             *            x
             *             \
             *              x
             */
            transplant(t, y, y->right);

            /* assign the right child of the node being deleted as the
             * successor's right node
             *
             *           q
             *           |
             *           z
             *         /   \
             *        l     r
             *             /
             *            x
             *             \
             *              r
             */
            y->right = z->right;

            /* assign the successor as the right child's parent of the
             * successor, where the right child was previously the right child
             * of the node being deleted
             *
             *           q
             *           |
             *           z
             *         /   \
             *        l     y
             *             /
             *            x
             *             \
             *              r
             */
            y->right->parent = y;
        }

        /* replace the node being deleted with its successor
         *
         *           q
         *           |
         *           y
         *         /   \
         *        l     y
         *             /
         *            x
         *             \
         *              r
         */
        transplant(t, z, y);

        /* assign the left child of the node being deleted as the successor's
         * left child
         *
         *           q
         *           |
         *           y
         *         /   \
         *        l     r
         *             /
         *            x
         *             \
         *              r
         */
        y->left = z->left;

        /* assign the successor as the right child's parent of the
         * successor, where the right child was previously the right child
         * of the node being deleted
         *
         *           q
         *           |
         *           y
         *         /   \
         *        l     r
         *             /
         *            x
         *             \
         *              r
         */
        y->left->parent = y;
    }
}
