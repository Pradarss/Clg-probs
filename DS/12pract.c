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
        preorder(t->left);
        printf("%d\t", t->info);
        preorder(t->right);
    }
}
void postorder(node *t){
    if (t != NULL)
    {
        preorder(t->left);
        preorder(t->right);
        printf("%d\t", t->info);
    }
}
int main(){
    int ch;
    node *root;
    root = createtree();
    while (1)
    {
        printf("menu\n");
        printf("1.Preorder traversal\n");
        printf("2.Inorder traversal\n");
        printf("3.Postorder traversal\n");
        printf("4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("The Preorder traversal is:\n");
            preorder(root);
            break;
        case 2:
            printf("The Inorder traversal is:\n");
            inorder(root);
            break;
        case 3:
            printf("The Postorder traversal is:\n");
            postorder(root);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}