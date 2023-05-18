#include "binary_trees.h"

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} heap_t;

int get_last_node(heap_t* root) {
    // Helper function to find the last level-order node
    if (root == NULL)
        return 0;

    int height = 0;
    heap_t* temp = root;
    while (temp->left != NULL) {
        height++;
        temp = temp->left;
    }

    int count = 0;
    int max_nodes = 1 << height;
    temp = root;
    while (count < max_nodes - 1) {
        if (count == max_nodes / 2)
            temp = temp->right;
        else {
            temp = temp->left;
            max_nodes /= 2;
        }
        count++;
    }

    return temp->data;
}

void rebuild_heap(heap_t* root) {
    // Helper function to rebuild the heap if necessary
    heap_t* temp = root;
    while (temp != NULL) {
        heap_t* largest = temp;
        heap_t* left_child = temp->left;
        heap_t* right_child = temp->right;

        if (left_child != NULL && left_child->data > largest->data)
            largest = left_child;

        if (right_child != NULL && right_child->data > largest->data)
            largest = right_child;

        if (largest != temp) {
            int temp_data = temp->data;
            temp->data = largest->data;
            largest->data = temp_data;
            temp = largest;
        } else {
            break;
        }
    }
}

int heap_extract(heap_t** root) {
    if (root == NULL || *root == NULL)
        return 0;

    int extracted_value = (*root)->data;
    int last_node_value = get_last_node(*root);

    if (*root == NULL) {
        *root = NULL;
        return extracted_value;
    }

    heap_t* temp = *root;
    heap_t* prev = NULL;
    while (temp->left != NULL) {
        prev = temp;
        temp = temp->left;
    }

    if (prev != NULL)
        prev->left = NULL;
    else
        *root = NULL;

    free(temp);
    (*root)->data = last_node_value;
    rebuild_heap(*root);

    return extracted_value;
}