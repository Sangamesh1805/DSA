#include<stdio.h>
#include<stdlib.h>
struct BST
{
    int data;
    struct BST*left;
    struct BST*right;
};
typedef struct BST node;

//Insert function for BST.
node* insert( node*root, int key)
{
    if (root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=key;
        root->left=NULL;
        root->right=NULL;
    }
    if(key < root->data)
    {
        root->left=insert(root->left,key);
    }
    else if(key > root->data)
    {
        root->right=insert(root->right,key);
    }
    return root;
}

//Function for inorder traversal.
void inorder(node* root) 
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

//Function for preorder traversal.
void preorder(node* root) 
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//Function for postorder traversal.
void postorder(node* root) 
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

//Function for searching an element in BST.
void search( node*root, int key)
{
    if(root==NULL)
    {
        printf("%d not found.\n", key);
        return;
    }
    if(root->data == key)
    {
        printf("%d found.\n", key);
        return;
    }
    if(key < root->data)
    {
        search(root->left,key);
    }
    else
    {
        search(root->right,key);
    }
}

int main() {
    node* root = NULL;
    int n, key, choice;

    printf("Enter the number of elements to insert in the BST: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &key);
        root = insert(root, key);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inorder traversal\n");
        printf("2. Preorder traversal\n");
        printf("3. Postorder traversal\n");
        printf("4. Search for element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}