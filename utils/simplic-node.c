#include <stdio.h>
#include <string.h>

#include "simplic-node.h"

Node* allocNode(void* data, size_t dataSize) {

    // Try to alloc for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "(Simplic) Error: Memory allocation failed for Node.\n");
        exit(EXIT_FAILURE);
    }
    // make sure that this pointer doesn't point to un-init value
    newNode->next[0] = NULL;
    newNode->next[1] = NULL;

    // Try to alloc for a new new data
    newNode->data = malloc(dataSize);
    if (newNode->data == NULL) {
        fprintf(stderr, "(Simplic) Error: Memory allocation failed for Node data.\n");
        exit(EXIT_FAILURE);
    }

    // Since data's a pointer, need to copy the data's value into the Node's data
    memcpy(newNode->data, data, dataSize);
    newNode->dataSize = dataSize;

    return newNode;
}

void freeNode(Node* node) {
    if (node == NULL) {
        return;
    }

    // Free the data. Note that this does not handle pointers
    if (node->data != NULL) {
        free(node->data);
    }

    // Free both of node's pointers
    freeNode(node->next[0]);
    freeNode(node->next[1]);

    // Finally, free the Node itself
    free(node);
}