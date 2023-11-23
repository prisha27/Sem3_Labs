#include<stdio.h>
#include<stdlib.h>
 
int ctr=0;
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create() {
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter data (-1 if you don't want to enter that child): ");
    scanf("%d", &x);
    nn->data = x;
    if (x == -1)
        return NULL;
    else {
        printf("Enter the left child %d: ", x);
        nn->left = create();

        printf("Enter the right child %d: ", x);
        nn->right = create();
    }
    return nn;
}

void inorder(struct node *root) {
    if (root == NULL)
        return;
    else {
        inorder(root->left);
        printf("-> %d", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root,*root1;
    root = create();
    root1=create();
    printf("The inorder of 1st is:\n");
    inorder(root);
    printf("The inorder of 2nd is:\n");
    inorder(root1);
}
    