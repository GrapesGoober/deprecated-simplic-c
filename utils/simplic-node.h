#include <stdlib.h>

// A binary node to be used for making non-contiguous and non-primitive data structures.
// Can be used for an s-list, d-list, binary tree, or anything really
typedef struct Node{
    void* data;             // any data to hold in this node, but do not put pointers here
    size_t dataSize;        // need to specify data size for memory management
    struct Node* next[2];   // next 2 nodes to point to
} Node;

// Allocate a new node with no other pointers
Node* allocNode(void* data, size_t dataSize);

// Recursively free all linked nodes, beginning at the root. Keep in mind that this uses
// a traditional "free()" on the data field of the node. It does not properly free pointers.
void freeNode(Node* node);

