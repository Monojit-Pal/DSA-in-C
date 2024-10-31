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

void display(struct node *root) {
    if(root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

void insert(struct node *root, int key) {
    struct node *prev = NULL;
    while(root != NULL) {
        prev = root;
        if(key == root->data) {
            printf("Cannot insert %d, already in BST\n", key);
            return;
        } else if(key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    struct node *new = createNode(key);
    if(key < prev->data) {
        prev->left = new;
    } else {
        prev->right = new;
    }
}

int main() {
    struct node *p = createNode(8);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(10);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(6);
    struct node *p5 = createNode(14);
    struct node *p6 = createNode(4);
    struct node *p7 = createNode(7);
    struct node *p8 = createNode(13);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p4->left = p6;
    p4->right = p7;
    p5->left = p8;
    insert(p, 5);
    display(p);
    return 0;
}