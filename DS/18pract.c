// Insertion:
//     Create a new node with the given details.
//     If the tree is empty, set the new node as the root of the tree.
//     If the tree is not empty, compare the year of the new node with the year of the root.
//     If the year of the new node is less than the year of the root, insert the new node in the left subtree.
//     If the year of the new node is greater than the year of the root, insert the new node in the right subtree.

// Deletion:
//     If the tree is empty, return NULL.
//     If the year of the node to be deleted is less than the year of the root, delete the node from the left subtree.
//     If the year of the node to be deleted is greater than the year of the root, delete the node from the right subtree.
//     If the year of the node to be deleted is equal to the year of the root:
//         If the root has no children, free the root and set it to NULL.
//         If the root has one child, set the root to its child.
//         If the root has two children, find the minimum value node in the right subtree and set the root's year to the minimum value. Then delete the minimum value node from the right subtree.

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
#include <string.h>

typedef struct node
{
  char type[50];
  char company[50];
  int year;
  struct node *left;
  struct node *right;
} Node;

Node *create_node(char type[], char company[], int year)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  strcpy(new_node->type, type);
  strcpy(new_node->company, company);
  new_node->year = year;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

Node *insert(Node *root, char type[], char company[], int year)
{
  if (root == NULL)
  {
    return create_node(type, company, year);
  }
  if (year < root->year)
  {
    root->left = insert(root->left, type, company, year);
  }
  else if (year > root->year)
  {
    root->right = insert(root->right, type, company, year);
  }
  return root;
}

Node *min_value_node(Node *root)
{
  Node *current = root;
  while (current->left != NULL)
  {
    current = current->left;
  }
  return current;
}

Node *delete_node(Node *root, int year)
{
  if (root == NULL)
  {
    return root;
  }
  if (year < root->year)
  {
    root->left = delete_node(root->left, year);
  }
  else if (year > root->year)
  {
    root->right = delete_node(root->right, year);
  }
  else
  {
    if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }
    Node *temp = min_value_node(root->right);
    root->year = temp->year;
    root->right = delete_node(root->right, temp->year);
  }
  return root;
}

void preorder(Node *root)
{
  if (root != NULL)
  {
    printf("%s %s %d\n", root->type, root->company, root->year);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(Node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%s %s %d\n", root->type, root->company, root->year);
    inorder(root->right);
  }
}

void postorder(Node *root)
{
  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%s %s %d\n", root->type, root->company, root->year);
  }
}

int main()
{
  Node *root = NULL;
  root = insert(root, "Sedan", "Toyota", 2010);
  root = insert(root, "SUV", "Ford", 2012);
  root = insert(root, "Truck", "Chevrolet", 2015);
  root = insert(root, "Hatchback", "Honda", 2008);
  root = insert(root, "Convertible", "BMW", 2011);
  printf("Preorder traversal:\n");
  preorder(root);
  printf("\nInorder traversal:\n");
  inorder(root);
  printf("\nPostorder traversal:\n");
  postorder(root);
  printf("\n");
  root = delete_node(root, 2015);
  printf("After deleting 2015:\n");
  printf("Preorder traversal:\n");
  preorder(root);
  return 0;
}