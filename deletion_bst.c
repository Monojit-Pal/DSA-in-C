#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};  

struct node* createNode(int data) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node* deleteNode(struct node *root, int value) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data > value) {
        root->left = deleteNode(root->left, value);
    } else if(root->data < value) {
        root->right = deleteNode(root->right, value);
    } else {
        if(root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        } else {
            struct node *temp = root->right;
            while(temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
  
    return root;
}

void display(struct node *root) {
    if(root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    display(p);
    printf("\n");
    p = deleteNode(p, 3);
    display(p);   

    return 0;
}