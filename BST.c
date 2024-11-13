#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Search Tree (BST) structure
struct BST {
    int data;                // Data value stored in the node
    struct BST *left;        // Pointer to the left child
    struct BST *right;       // Pointer to the right child
};
typedef struct BST node;      // Typedef for convenience

// Insert function for BST: adds a new node with the given key
node* insert(node* root, int key) {
    // If root is NULL, create a new node and set it as the root
    if (root == NULL) {
        root = (node*)malloc(sizeof(node));
        root->data = key;      // Assign key to node's data
        root->left = NULL;     // Initialize left child to NULL
        root->right = NULL;    // Initialize right child to NULL
    }
    // If key is smaller than the root's data, insert it in the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    // If key is greater than the root's data, insert it in the right subtree
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    // Return the root after insertion
    return root;
}

// Function for in-order traversal (left-root-right)
void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);       // Traverse left subtree
        printf("%d ", root->data); // Print current node's data
        inorder(root->right);      // Traverse right subtree
    }
}

// Function for pre-order traversal (root-left-right)
void preorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Print current node's data
        preorder(root->left);      // Traverse left subtree
        preorder(root->right);     // Traverse right subtree
    }
}

// Function for post-order traversal (left-right-root)
void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);     // Traverse left subtree
        postorder(root->right);    // Traverse right subtree
        printf("%d ", root->data); // Print current node's data
    }
}

// Function to search for an element in the BST
void search(node* root, int key) {
    // If root is NULL, the key is not found
    if (root == NULL) {
        printf("%d not found.\n", key);
        return;
    }
    // If the key matches the current node's data, it is found
    if (root->data == key) {
        printf("%d found.\n", key);
        return;
    }
    // If key is smaller, search in the left subtree
    if (key < root->data) {
        search(root->left, key);
    }
    // If key is larger, search in the right subtree
    else {
        search(root->right, key);
    }
}

// Main function to interact with the BST
int main() {
    node* root = NULL;    // Initialize the root of the BST to NULL
    int n, key, choice;   // Variables for input

    // Prompt user for number of elements to insert in the BST
    printf("Enter the number of elements to insert in the BST: ");
    scanf("%d", &n);

    // Loop to insert elements into the BST
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);   // Insert each key into the BST
    }

    // Menu-driven loop for user interaction
    while (1) {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Inorder traversal\n");
        printf("2. Preorder traversal\n");
        printf("3. Postorder traversal\n");
        printf("4. Search for element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice with switch statement
        switch (choice) {
            case 1:
                printf("Inorder traversal: ");
                inorder(root);      // Perform in-order traversal
                printf("\n");
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);     // Perform pre-order traversal
                printf("\n");
                break;
            case 3:
                printf("Postorder traversal: ");
                postorder(root);    // Perform post-order traversal
                printf("\n");
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                search(root, key);  // Search for an element in the BST
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);            // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;  // End of main function
}
