#include <stdlib.h>

#include "tree.h"
#include "utils.h"

void lcrs_node_init(struct lcrs_node *node) {
    node->data = 0;
    node->child = NULL;
    node->sibling = NULL;
}

struct lcrs_node **last_sibling(struct lcrs_node *start) {
    struct lcrs_node **node_ptr = &start->sibling;
    while (*node_ptr != NULL) {
        /* Find tail of sibling linked list. */
        node_ptr = &(*node_ptr)->sibling;
    }
    return node_ptr;
}

void lcrs_insert_at(struct lcrs_node *node, struct lcrs_node **at) {
    struct lcrs_node *new_sibling = *at;
    *at = node;
    struct lcrs_node **last_sibling = find_last_sibling(node);
    (*last_sibling)->sibling = new_sibling;
}

void lcrs_insert_child(struct lcrs_node *node, struct lcrs_node *parent) {
    lcrs_insert_at(node, &parent->child);
}

void lcrs_insert_sibling(struct lcrs_node *node, struct lcrs_node *sibling) {
    lcrs_insert_at(node, &sibling->sibling);
}

int lcrs_tree_height(struct lcrs_node *root) {
    if (root == NULL) return -1;

    /* Since siblings are on the same level, 1 is added only to the child's height. */
    return max(1 + lcrs_tree_height(root->child), lcrs_tree_height(root->sibling));
}
