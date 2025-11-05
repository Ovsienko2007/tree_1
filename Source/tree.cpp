#include "tree.h"

void add_elem(tree_t *tree, tree_elem_t new_elem_value) {
    node_t *new_elem = (node_t *)calloc(1, sizeof(node_t));

    new_elem->elem = new_elem_value;
    new_elem->left = NULL;
    new_elem->right = NULL;

    if (!*tree){
        *tree = new_elem;
        return;
    }

    node_t *pos = *tree;
    while (true) {
        if (pos->elem > new_elem_value) {
            
            if (!pos->left) {
                pos->left = new_elem;
                break;
            }
            pos = pos->left;
        }
        else {
            if (!pos->right) {
                pos->right = new_elem;
                break;
            }
            pos = pos->right;
        }
    }
}

void destroy_branch(tree_t *tree, tree_elem_t elem_value) {
    if (!tree) return;
    if (!*tree) return;

    static bool elem_in_tree = true;

    if ((*tree)->elem > elem_value) {
        destroy_branch(&((*tree)->left), elem_value);
        if (!elem_in_tree){
            elem_in_tree = true;
        }
    }
    else if ((*tree)->elem < elem_value){
        destroy_branch(&((*tree)->right), elem_value);
    }
    else {
        destroy_tree(tree);
        elem_in_tree = false;
    }
}

void destroy_tree(tree_t *tree) {
    if (!tree) return;
    if (!*tree) return;

    if ((*tree)->left) {
        destroy_tree(&((*tree)->left));
    }
    if ((*tree)->right) {
        destroy_tree(&((*tree)->right));
    }

    free(*tree);
    *tree = NULL;
}

void print_tree(tree_t tree) {
    if (!tree) return;

    if (tree->left) {
        print_tree(tree->left);
    }

    printf("%d ", tree->elem);

    if (tree->right) {
        print_tree(tree->right);
    }
}