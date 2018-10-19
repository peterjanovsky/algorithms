#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "red_black_tree.c"

#define TRUE  1
#define FALSE 0

struct rb_leaf *add_rb_leaf(struct rb_tree *t, int key)
{
    struct rb_leaf *node;
    node = (struct rb_leaf*)malloc(sizeof(struct rb_leaf));

    node->key = key;
    node->color = RED;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    rb_tree_insert(t, node);

    return node;
}

void test_rb_tree_insert()
{
    printf("red-black tree insert\n");

    struct rb_tree *t;
    t = (struct rb_tree*)malloc(sizeof(struct rb_tree));
    t->root = NULL;

    struct rb_leaf *node_1 = add_rb_leaf(t, 12);

    assert(t->root->key = node_1->key);
    assert(t->root->left == NULL);
    assert(t->root->right == NULL);
    assert(t->root->parent == NULL);

    struct rb_leaf *node_2 = add_rb_leaf(t, 10);

    assert(t->root->key == node_1->key);
    assert(t->root->left->key == node_2->key);
    assert(t->root->right == NULL);
    assert(t->root->parent == NULL);

    assert(node_2->left == NULL);
    assert(node_2->right == NULL);
    assert(node_2->parent == node_1);

    struct rb_leaf *node_3 = add_rb_leaf(t, 14);

    assert(t->root->key == node_1->key);
    assert(t->root->left->key == node_2->key);
    assert(t->root->right->key == node_3->key);
    assert(t->root->parent == NULL);

    assert(node_3->left == NULL);
    assert(node_3->right == NULL);
    assert(node_3->parent == node_1);

    struct rb_leaf *node_4 = add_rb_leaf(t, 4);

    assert(t->root->key == node_1->key);
    assert(t->root->left->key == node_2->key);
    assert(t->root->right->key == node_3->key);
    assert(t->root->parent == NULL);

    assert(node_4->left == NULL);
    assert(node_4->right == NULL);
    assert(node_4->parent == node_2);
    assert(node_2->left == node_4);

    free(node_4);
    free(node_3);
    free(node_2);
    free(node_1);
    free(t);
}

/*
void validate_node(struct rb_leaf *node,
                   int key,
                   struct rb_leaf *left,
                   struct rb_leaf *right,
                   struct rb_leaf *parent)
{
    printf("validating node\n");

    assert(node->key == key);
    assert(node->left == left);
    assert(node->right == right);
    assert(node->parent == parent);
}

void test_rb_tree_minimum()
{
    printf("tree minimum\n");

    struct rb_tree *t;
    t = (struct rb_tree*)malloc(sizeof(struct rb_tree));
    t->root = NULL;

    struct rb_leaf *node_1 = add_rb_leaf(t, 15);
    struct rb_leaf *node_2 = add_rb_leaf(t, 6);
    struct rb_leaf *node_3 = add_rb_leaf(t, 18);
    struct rb_leaf *node_4 = add_rb_leaf(t, 3);
    struct rb_leaf *node_5 = add_rb_leaf(t, 7);
    struct rb_leaf *node_6 = add_rb_leaf(t, 17);
    struct rb_leaf *node_7 = add_rb_leaf(t, 20);
    struct rb_leaf *node_8 = add_rb_leaf(t, 2);
    struct rb_leaf *node_9 = add_rb_leaf(t, 4);
    struct rb_leaf *node_10 = add_rb_leaf(t, 13);
    struct rb_leaf *node_11 = add_rb_leaf(t, 9);

    struct rb_leaf *node_minimum = rb_tree_minimum(t->root);

    validate_node(node_minimum,
                  node_8->key,
                  node_8->left,
                  node_8->right,
                  node_8->parent);

    free(node_11);
    free(node_10);
    free(node_9);
    free(node_8);
    free(node_7);
    free(node_6);
    free(node_5);
    free(node_4);
    free(node_3);
    free(node_2);
    free(node_1);
    free(t);
}

void test_rb_tree_maximum()
{
    printf("tree maximum\n");

    struct rb_tree *t;
    t = (struct rb_tree*)malloc(sizeof(struct rb_tree));
    t->root = NULL;

    struct rb_leaf *node_1 = add_rb_leaf(t, 15);
    struct rb_leaf *node_2 = add_rb_leaf(t, 6);
    struct rb_leaf *node_3 = add_rb_leaf(t, 18);
    struct rb_leaf *node_4 = add_rb_leaf(t, 3);
    struct rb_leaf *node_5 = add_rb_leaf(t, 7);
    struct rb_leaf *node_6 = add_rb_leaf(t, 17);
    struct rb_leaf *node_7 = add_rb_leaf(t, 20);
    struct rb_leaf *node_8 = add_rb_leaf(t, 2);
    struct rb_leaf *node_9 = add_rb_leaf(t, 4);
    struct rb_leaf *node_10 = add_rb_leaf(t, 13);
    struct rb_leaf *node_11 = add_rb_leaf(t, 9);

    struct rb_leaf *node_maximum = rb_tree_maximum(t->root);

    validate_node(node_maximum,
                  node_7->key,
                  node_7->left,
                  node_7->right,
                  node_7->parent);

    free(node_11);
    free(node_10);
    free(node_9);
    free(node_8);
    free(node_7);
    free(node_6);
    free(node_5);
    free(node_4);
    free(node_3);
    free(node_2);
    free(node_1);
    free(t);
}

void test_rb_tree_successor()
{
    printf("tree successor\n");

    struct rb_tree *t;
    t = (struct rb_tree*)malloc(sizeof(struct rb_tree));
    t->root = NULL;

    struct rb_leaf *node_1 = add_rb_leaf(t, 15);
    struct rb_leaf *node_2 = add_rb_leaf(t, 6);
    struct rb_leaf *node_3 = add_rb_leaf(t, 18);
    struct rb_leaf *node_4 = add_rb_leaf(t, 3);
    struct rb_leaf *node_5 = add_rb_leaf(t, 7);
    struct rb_leaf *node_6 = add_rb_leaf(t, 17);
    struct rb_leaf *node_7 = add_rb_leaf(t, 20);
    struct rb_leaf *node_8 = add_rb_leaf(t, 2);
    struct rb_leaf *node_9 = add_rb_leaf(t, 4);
    struct rb_leaf *node_10 = add_rb_leaf(t, 13);
    struct rb_leaf *node_11 = add_rb_leaf(t, 9);

    printf("find successor of root node\n");
    struct rb_leaf *node_successor = rb_tree_successor(t->root);

    validate_node(node_successor,
                  node_6->key,
                  node_6->left,
                  node_6->right,
                  node_6->parent);

    printf("find successor of child node\n");
    node_successor = rb_tree_successor(node_10);

    validate_node(node_successor,
                  node_1->key,
                  node_1->left,
                  node_1->right,
                  node_1->parent);

    free(node_11);
    free(node_10);
    free(node_9);
    free(node_8);
    free(node_7);
    free(node_6);
    free(node_5);
    free(node_4);
    free(node_3);
    free(node_2);
    free(node_1);
    free(t);
}

void test_rb_tree_search(int key, int null_expected)
{
    printf("recursive tree search\n");

    struct rb_tree *t;
    t = (struct rb_tree*)malloc(sizeof(struct rb_tree));
    t->root = NULL;

    struct rb_leaf *node_1 = add_rb_leaf(t, 15);
    struct rb_leaf *node_2 = add_rb_leaf(t, 6);
    struct rb_leaf *node_3 = add_rb_leaf(t, 18);
    struct rb_leaf *node_4 = add_rb_leaf(t, 3);
    struct rb_leaf *node_5 = add_rb_leaf(t, 7);
    struct rb_leaf *node_6 = add_rb_leaf(t, 17);
    struct rb_leaf *node_7 = add_rb_leaf(t, 20);
    struct rb_leaf *node_8 = add_rb_leaf(t, 2);
    struct rb_leaf *node_9 = add_rb_leaf(t, 4);
    struct rb_leaf *node_10 = add_rb_leaf(t, 13);
    struct rb_leaf *node_11 = add_rb_leaf(t, 9);

    struct rb_leaf *node = rb_tree_search(t->root, key);

    if ( null_expected == TRUE ) assert(node == NULL);
    else assert(node->key == key);

    free(node_11);
    free(node_10);
    free(node_9);
    free(node_8);
    free(node_7);
    free(node_6);
    free(node_5);
    free(node_4);
    free(node_3);
    free(node_2);
    free(node_1);
    free(t);
}

void test_iterative_rb_tree_search(int key, int null_expected)
{
    printf("iterative tree search\n");

    struct rb_tree *t;
    t = (struct rb_tree*)malloc(sizeof(struct rb_tree));
    t->root = NULL;

    struct rb_leaf *node_1 = add_rb_leaf(t, 15);
    struct rb_leaf *node_2 = add_rb_leaf(t, 6);
    struct rb_leaf *node_3 = add_rb_leaf(t, 18);
    struct rb_leaf *node_4 = add_rb_leaf(t, 3);
    struct rb_leaf *node_5 = add_rb_leaf(t, 7);
    struct rb_leaf *node_6 = add_rb_leaf(t, 17);
    struct rb_leaf *node_7 = add_rb_leaf(t, 20);
    struct rb_leaf *node_8 = add_rb_leaf(t, 2);
    struct rb_leaf *node_9 = add_rb_leaf(t, 4);
    struct rb_leaf *node_10 = add_rb_leaf(t, 13);
    struct rb_leaf *node_11 = add_rb_leaf(t, 9);

    struct rb_leaf *node = iterative_rb_tree_search(t->root, key);

    if ( null_expected == TRUE ) assert(node == NULL);
    else assert(node->key == key);

    free(node_11);
    free(node_10);
    free(node_9);
    free(node_8);
    free(node_7);
    free(node_6);
    free(node_5);
    free(node_4);
    free(node_3);
    free(node_2);
    free(node_1);
    free(t);
}

void test_transplant(int key)
{
    printf("transplant\n");

    struct rb_tree *t;
    t = (struct rb_tree*)malloc(sizeof(struct rb_tree));
    t->root = NULL;

    struct rb_leaf *node_1 = add_rb_leaf(t, 15);
    struct rb_leaf *node_2 = add_rb_leaf(t, 6);
    struct rb_leaf *node_3 = add_rb_leaf(t, 18);
    struct rb_leaf *node_4 = add_rb_leaf(t, 3);
    struct rb_leaf *node_5 = add_rb_leaf(t, 7);
    struct rb_leaf *node_6 = add_rb_leaf(t, 17);
    struct rb_leaf *node_7 = add_rb_leaf(t, 20);
    struct rb_leaf *node_8 = add_rb_leaf(t, 2);
    struct rb_leaf *node_9 = add_rb_leaf(t, 4);
    struct rb_leaf *node_10 = add_rb_leaf(t, 13);
    struct rb_leaf *node_11 = add_rb_leaf(t, 9);

    struct rb_leaf *node;
    node = (struct rb_leaf*)malloc(sizeof(struct rb_leaf));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    printf("-------------------\n");
    inorder_rb_tree_walk(t->root);
    printf("-------------------\n");

    transplant(t, node_3, node);

    printf("-------------------\n");
    inorder_rb_tree_walk(t->root);
    printf("-------------------\n");

    free(node);
    free(node_11);
    free(node_10);
    free(node_9);
    free(node_8);
    free(node_7);
    free(node_6);
    free(node_5);
    free(node_4);
    free(node_3);
    free(node_2);
    free(node_1);
    free(t);
}

void test_rb_tree_delete()
{
    printf("tree delete\n");

    struct rb_tree *t;
    t = (struct rb_tree*)malloc(sizeof(struct rb_tree));
    t->root = NULL;

    struct rb_leaf *node_1 = add_rb_leaf(t, 15);
    struct rb_leaf *node_2 = add_rb_leaf(t, 6);
    struct rb_leaf *node_3 = add_rb_leaf(t, 18);
    struct rb_leaf *node_4 = add_rb_leaf(t, 3);
    struct rb_leaf *node_5 = add_rb_leaf(t, 7);
    struct rb_leaf *node_6 = add_rb_leaf(t, 17);
    struct rb_leaf *node_7 = add_rb_leaf(t, 20);
    struct rb_leaf *node_8 = add_rb_leaf(t, 2);
    struct rb_leaf *node_9 = add_rb_leaf(t, 4);
    struct rb_leaf *node_10 = add_rb_leaf(t, 13);
    struct rb_leaf *node_11 = add_rb_leaf(t, 9);

    printf("-------------------\n");
    inorder_rb_tree_walk(t->root);
    printf("-------------------\n");

    rb_tree_delete(t, node_1);

    printf("-------------------\n");
    inorder_rb_tree_walk(t->root);
    printf("-------------------\n");

    free(node_11);
    free(node_10);
    free(node_9);
    free(node_8);
    free(node_7);
    free(node_6);
    free(node_5);
    free(node_4);
    free(node_3);
    free(node_2);
    free(node_1);
    free(t);
}

void test_rb_tree_delete_2()
{
    printf("tree delete 2\n");

    struct rb_tree *t;
    t = (struct rb_tree*)malloc(sizeof(struct rb_tree));
    t->root = NULL;

    struct rb_leaf *node_1 = add_rb_leaf(t, 50);
    //struct rb_leaf *node_2 = add_rb_leaf(t, 30);
    struct rb_leaf *node_3 = add_rb_leaf(t, 70);
    //struct rb_leaf *node_4 = add_rb_leaf(t, 20);
    struct rb_leaf *node_5 = add_rb_leaf(t, 40);
    struct rb_leaf *node_6 = add_rb_leaf(t, 60);
    struct rb_leaf *node_7 = add_rb_leaf(t, 80);

    printf("-------------------\n");
    inorder_rb_tree_walk(t->root);
    printf("-------------------\n");

    printf("-------------------\n");
    rb_tree_walk(t->root, "parent");
    printf("-------------------\n");

    rb_tree_delete(t, node_1);

    printf("-------------------\n");
    rb_tree_walk(t->root, "parent");
    printf("-------------------\n");

    free(node_7);
    free(node_6);
    free(node_5);
    //free(node_4);
    free(node_3);
    //free(node_2);
    free(node_1);
    free(t);
}
*/

int main()
{
    printf("binary search tree\n");

    test_rb_tree_insert();

/*
    test_rb_tree_minimum();

    test_rb_tree_maximum();

    test_rb_tree_successor();

    test_rb_tree_search(17, FALSE);
    test_rb_tree_search(7, FALSE);
    test_rb_tree_search(15, FALSE);
    test_rb_tree_search(25, TRUE);
    test_rb_tree_search(1, TRUE);

    test_iterative_rb_tree_search(17, FALSE);
    test_iterative_rb_tree_search(7, FALSE);
    test_iterative_rb_tree_search(15, FALSE);
    test_iterative_rb_tree_search(25, TRUE);
    test_iterative_rb_tree_search(1, TRUE);

    test_transplant(16);

    test_rb_tree_delete();

    test_rb_tree_delete_2();
*/
}
