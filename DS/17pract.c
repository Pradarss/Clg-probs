// Preorder traversal:
//     Visit the root.
//     Traverse the left subtree in preorder.
//     Traverse the right subtree in preorder.

// Inorder traversal:
//     Traverse the left subtree in inorder.
//     Visit the root.
//     Traverse the right subtree in inorder.

// Postorder traversal:
//     Traverse the left subtree in postorder.
//     Traverse the right subtree in postorder.
//     Visit the root.

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int info;
    struct node *left;
    struct node *right;
} node;
node *createtree(){

    struct node *new_node;

    int x;
    printf("Enter the data (-1 for no node) :\n");
    scanf("%d", &x);
    if (x == -1){
        return NULL;
    }
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->info = x;
    printf("Enter the left child of %d\n", x);
    new_node->left = createtree();
    printf("Enter the right child of %d\n", x);
    new_node->right = createtree();
    return new_node;
}
void preorder(node *t){
    if (t != NULL)
    {
        printf("%d\t", t->info);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(node *t){
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d\t", t->info);
        inorder(t->right);
    }
}
void postorder(node *t){
    if (t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d\t", t->info);
    }
}
int main(){
    node *root;
    root = createtree();
            printf("\nThe Preorder traversal is:\n");
            preorder(root);
            printf("\nThe Inorder traversal is:\n");
            inorder(root);
            printf("\nThe Postorder traversal is:\n");
            postorder(root);
            exit(0);
    }