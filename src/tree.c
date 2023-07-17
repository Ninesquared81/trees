#include <stdlib.h>

#include "tree.h"
void lcrs_node_init(struct lcrs_node *node) {
    node->data = 0;
    node->child = NULL;
    node->sibling = NULL;
}

