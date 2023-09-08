#include <stdlib.h>

// a utility type to be used for making non-contiguous and non-primitive data structures
typedef struct
{
    void* data;         // any data to hold in this node
    size_t dataSize;    // need to specify data size for memory management
    Node* next;         // next node to point to
} Node;

// allocate a new node with no other pointers
Node* allocNode(void* data, size_t dataSize);

// free all linked nodes, beginning at the root
int freeAll(Node* root);
