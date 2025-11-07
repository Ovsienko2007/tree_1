#ifndef TREE_H_
#define TREE_H_

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define DUMP(tree) show_dump(tree, dump_position {__FILE__, __FUNCTION__,  __LINE__})

typedef int tree_elem_t;

struct node_t {
    tree_elem_t elem;
    node_t *left;
    node_t *right;
};

typedef node_t* tree_t;

struct dump_position {
    const char *file;
    const char *func;
    int line;
};

void print_tree(tree_t tree);

void add_elem(tree_t *tree, tree_elem_t new_elem_value);

void destroy_branch(tree_t *tree, tree_elem_t elem_value);
void destroy_tree(tree_t *tree);

void show_dump(tree_t tree, dump_position position);
#endif