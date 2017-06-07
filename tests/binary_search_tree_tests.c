#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.c"

#define TRUE  1
#define FALSE 0

struct leaf *add_leaf(struct tree *t, int key)
{
    struct leaf *node;
    node = (struct leaf*)malloc(sizeof(struct leaf));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    tree_insert(t, node);

    return node;
}

void test_tree_insert()
{
    printf("tree insert\n");

    struct tree *t;
    t = (struct tree*)malloc(sizeof(struct tree));
    t->root = NULL;

    struct leaf *node_1 = add_leaf(t, 12);

    assert(t->root->key = node_1->key);
    assert(t->root->left == NULL);
    assert(t->root->right == NULL);
    assert(t->root->parent == NULL);

    struct leaf *node_2 = add_leaf(t, 10);

    assert(t->root->key == node_1->key);
    assert(t->root->left->key == node_2->key);
    assert(t->root->right == NULL);
    assert(t->root->parent == NULL);

    assert(node_2->left == NULL);
    assert(node_2->right == NULL);
    assert(node_2->parent == node_1);

    struct leaf *node_3 = add_leaf(t, 14);

    assert(t->root->key == node_1->key);
    assert(t->root->left->key == node_2->key);
    assert(t->root->right->key == node_3->key);
    assert(t->root->parent == NULL);

    assert(node_3->left == NULL);
    assert(node_3->right == NULL);
    assert(node_3->parent == node_1);

    struct leaf *node_4 = add_leaf(t, 4);

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

void validate_node(struct leaf *node,
                   int key,
                   struct leaf *left,
                   struct leaf *right,
                   struct leaf *parent)
{
    printf("validating node\n");

    assert(node->key == key);
    assert(node->left == left);
    assert(node->right == right);
    assert(node->parent == parent);
}

void test_tree_minimum()
{
    printf("tree minimum\n");

    struct tree *t;
    t = (struct tree*)malloc(sizeof(struct tree));
    t->root = NULL;

    struct leaf *node_1 = add_leaf(t, 15);
    struct leaf *node_2 = add_leaf(t, 6);
    struct leaf *node_3 = add_leaf(t, 18);
    struct leaf *node_4 = add_leaf(t, 3);
    struct leaf *node_5 = add_leaf(t, 7);
    struct leaf *node_6 = add_leaf(t, 17);
    struct leaf *node_7 = add_leaf(t, 20);
    struct leaf *node_8 = add_leaf(t, 2);
    struct leaf *node_9 = add_leaf(t, 4);
    struct leaf *node_10 = add_leaf(t, 13);
    struct leaf *node_11 = add_leaf(t, 9);

    struct leaf *node_minimum = tree_minimum(t->root);

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

void test_tree_maximum()
{
    printf("tree maximum\n");

    struct tree *t;
    t = (struct tree*)malloc(sizeof(struct tree));
    t->root = NULL;

    struct leaf *node_1 = add_leaf(t, 15);
    struct leaf *node_2 = add_leaf(t, 6);
    struct leaf *node_3 = add_leaf(t, 18);
    struct leaf *node_4 = add_leaf(t, 3);
    struct leaf *node_5 = add_leaf(t, 7);
    struct leaf *node_6 = add_leaf(t, 17);
    struct leaf *node_7 = add_leaf(t, 20);
    struct leaf *node_8 = add_leaf(t, 2);
    struct leaf *node_9 = add_leaf(t, 4);
    struct leaf *node_10 = add_leaf(t, 13);
    struct leaf *node_11 = add_leaf(t, 9);

    struct leaf *node_maximum = tree_maximum(t->root);

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

void test_tree_successor()
{
    printf("tree successor\n");

    struct tree *t;
    t = (struct tree*)malloc(sizeof(struct tree));
    t->root = NULL;

    struct leaf *node_1 = add_leaf(t, 15);
    struct leaf *node_2 = add_leaf(t, 6);
    struct leaf *node_3 = add_leaf(t, 18);
    struct leaf *node_4 = add_leaf(t, 3);
    struct leaf *node_5 = add_leaf(t, 7);
    struct leaf *node_6 = add_leaf(t, 17);
    struct leaf *node_7 = add_leaf(t, 20);
    struct leaf *node_8 = add_leaf(t, 2);
    struct leaf *node_9 = add_leaf(t, 4);
    struct leaf *node_10 = add_leaf(t, 13);
    struct leaf *node_11 = add_leaf(t, 9);

    printf("find successor of root node\n");
    struct leaf *node_successor = tree_successor(t->root);

    validate_node(node_successor,
                  node_6->key,
                  node_6->left,
                  node_6->right,
                  node_6->parent);

    printf("find successor of child node\n");
    node_successor = tree_successor(node_10);

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

void test_tree_search(int key, int null_expected)
{
    printf("recursive tree search\n");

    struct tree *t;
    t = (struct tree*)malloc(sizeof(struct tree));
    t->root = NULL;

    struct leaf *node_1 = add_leaf(t, 15);
    struct leaf *node_2 = add_leaf(t, 6);
    struct leaf *node_3 = add_leaf(t, 18);
    struct leaf *node_4 = add_leaf(t, 3);
    struct leaf *node_5 = add_leaf(t, 7);
    struct leaf *node_6 = add_leaf(t, 17);
    struct leaf *node_7 = add_leaf(t, 20);
    struct leaf *node_8 = add_leaf(t, 2);
    struct leaf *node_9 = add_leaf(t, 4);
    struct leaf *node_10 = add_leaf(t, 13);
    struct leaf *node_11 = add_leaf(t, 9);

    struct leaf *node = tree_search(t->root, key);

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

void test_iterative_tree_search(int key, int null_expected)
{
    printf("iterative tree search\n");

    struct tree *t;
    t = (struct tree*)malloc(sizeof(struct tree));
    t->root = NULL;

    struct leaf *node_1 = add_leaf(t, 15);
    struct leaf *node_2 = add_leaf(t, 6);
    struct leaf *node_3 = add_leaf(t, 18);
    struct leaf *node_4 = add_leaf(t, 3);
    struct leaf *node_5 = add_leaf(t, 7);
    struct leaf *node_6 = add_leaf(t, 17);
    struct leaf *node_7 = add_leaf(t, 20);
    struct leaf *node_8 = add_leaf(t, 2);
    struct leaf *node_9 = add_leaf(t, 4);
    struct leaf *node_10 = add_leaf(t, 13);
    struct leaf *node_11 = add_leaf(t, 9);

    struct leaf *node = iterative_tree_search(t->root, key);

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

    struct tree *t;
    t = (struct tree*)malloc(sizeof(struct tree));
    t->root = NULL;

    struct leaf *node_1 = add_leaf(t, 15);
    struct leaf *node_2 = add_leaf(t, 6);
    struct leaf *node_3 = add_leaf(t, 18);
    struct leaf *node_4 = add_leaf(t, 3);
    struct leaf *node_5 = add_leaf(t, 7);
    struct leaf *node_6 = add_leaf(t, 17);
    struct leaf *node_7 = add_leaf(t, 20);
    struct leaf *node_8 = add_leaf(t, 2);
    struct leaf *node_9 = add_leaf(t, 4);
    struct leaf *node_10 = add_leaf(t, 13);
    struct leaf *node_11 = add_leaf(t, 9);

    struct leaf *node;
    node = (struct leaf*)malloc(sizeof(struct leaf));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    printf("-------------------\n");
    inorder_tree_walk(t->root);
    printf("-------------------\n");

    transplant(t, node_3, node);

    printf("-------------------\n");
    inorder_tree_walk(t->root);
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

void test_tree_delete()
{
    printf("tree delete\n");

    struct tree *t;
    t = (struct tree*)malloc(sizeof(struct tree));
    t->root = NULL;

    struct leaf *node_1 = add_leaf(t, 15);
    struct leaf *node_2 = add_leaf(t, 6);
    struct leaf *node_3 = add_leaf(t, 18);
    struct leaf *node_4 = add_leaf(t, 3);
    struct leaf *node_5 = add_leaf(t, 7);
    struct leaf *node_6 = add_leaf(t, 17);
    struct leaf *node_7 = add_leaf(t, 20);
    struct leaf *node_8 = add_leaf(t, 2);
    struct leaf *node_9 = add_leaf(t, 4);
    struct leaf *node_10 = add_leaf(t, 13);
    struct leaf *node_11 = add_leaf(t, 9);

    printf("-------------------\n");
    inorder_tree_walk(t->root);
    printf("-------------------\n");

    tree_delete(t, node_1);

    printf("-------------------\n");
    inorder_tree_walk(t->root);
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

void test_tree_delete_2()
{
    printf("tree delete 2\n");

    struct tree *t;
    t = (struct tree*)malloc(sizeof(struct tree));
    t->root = NULL;

    struct leaf *node_1 = add_leaf(t, 50);
    //struct leaf *node_2 = add_leaf(t, 30);
    struct leaf *node_3 = add_leaf(t, 70);
    //struct leaf *node_4 = add_leaf(t, 20);
    struct leaf *node_5 = add_leaf(t, 40);
    struct leaf *node_6 = add_leaf(t, 60);
    struct leaf *node_7 = add_leaf(t, 80);

    printf("-------------------\n");
    inorder_tree_walk(t->root);
    printf("-------------------\n");

    printf("-------------------\n");
    tree_walk(t->root, "parent");
    printf("-------------------\n");

    tree_delete(t, node_1);

    printf("-------------------\n");
    tree_walk(t->root, "parent");
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

int main()
{
    printf("binary search tree\n");

    test_tree_insert();

    test_tree_minimum();

    test_tree_maximum();

    test_tree_successor();

    test_tree_search(17, FALSE);
    test_tree_search(7, FALSE);
    test_tree_search(15, FALSE);
    test_tree_search(25, TRUE);
    test_tree_search(1, TRUE);

    test_iterative_tree_search(17, FALSE);
    test_iterative_tree_search(7, FALSE);
    test_iterative_tree_search(15, FALSE);
    test_iterative_tree_search(25, TRUE);
    test_iterative_tree_search(1, TRUE);

    test_transplant(16);

    test_tree_delete();

    test_tree_delete_2();
}
