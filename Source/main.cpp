#include <stdio.h>
#include "tree.h"

int main(){
    tree_t tree = NULL;

    add_elem(&tree, 5);
    add_elem(&tree, 5);
    add_elem(&tree, 3);
    add_elem(&tree, 6);
    add_elem(&tree, 10);
    add_elem(&tree, 11);
    add_elem(&tree, 9);

    print_tree(tree);
    printf("\n");

    DUMP(tree);

    destroy_branch(&tree, 10);

    DUMP(tree);

    destroy_tree(&tree);

    return 0;
}