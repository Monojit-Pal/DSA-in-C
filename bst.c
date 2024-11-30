#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Find the successor (minimum value in right subtree)
struct node *getSuccessor(struct node *curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

// Delete a node from the BST
struct node *deleteNode(struct node *root, int x) {
    // Base case
    if (root == NULL) {
        printf("Element not found\n");
        return root;
    }

    // If key is smaller than root's data, go to left subtree
    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    }
    // If key is greater than root's data, go to right subtree
    else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    }
    // If the key matches the root's data
    else {
        // Case: No child or only right child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        // Case: Only left child
        if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case: Both children present
        struct node *succ = getSuccessor(root);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }
    return root;
}

// Search for a node in the BST
void search(struct node *root, int data) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }
    if (data == root->data) {
        printf("Element found\n");
        return;
    }
    if (data < root->data) {
        search(root->left, data);
    } else {
        search(root->right, data);
    }
}

// Inorder traversal of the BST
void traverse(struct node *root) {
    if (root == NULL) {
        return;
    }
    traverse(root->left);
    printf("%d ", root->data);
    traverse(root->right);
}

int main() {
    int ch = 0, data;
    struct node *root = NULL;

    while (ch != 5) {
        printf("\nPress 1. Insert 2. Delete 3. Search 4. Traverse 5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(root, data);
                break;
            case 4:
                printf("Binary Search Tree (Inorder): ");
                traverse(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting the Binary Search Tree program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}