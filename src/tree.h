#ifndef TREE_H
#define TREE_H

struct lcrs_node {
    int data;
    struct lcrs_node *child;
    struct lcrs_node *sibling;
};

void lcrs_node_init(struct lcrs_node *node);

#endif
