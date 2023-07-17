#ifndef TREE_H
#define TREE_H

struct lcrs_node {
    int data;
    struct lcrs_node *child;
    struct lcrs_node *sibling;
};

void lcrs_node_init(struct lcrs_node *node);
void lcrs_insert_at(struct lcrs_node *node, struct lcrs_node **at);
void lcrs_insert_child(struct lcrs_node *node, struct lcrs_node *parent);
void lcrs_insert_sibling(struct lcrs_node *node, struct lsrc_node *sibling);

int lcrs_tree_height(struct lcrs_node *root);

#endif
