#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};

struct bstnode *GetNewNode(int data);
struct bstnode *Insert(struct bstnode *root, int data);
bool Search(struct bstnode *root, int data);
void Preorder(struct bstnode *root);
void Inorder(struct bstnode *root);
void Postorder(struct bstnode *root);
struct bstnode *Delete(struct bstnode *root, int data);
int FindHeight(struct bstnode *root);
struct bstnode *FindMin(struct bstnode *root);
struct bstnode *FindMax(struct bstnode *root);

struct bstnode *GetNewNode(int data)
{
    struct bstnode *newNode = (struct bstnode *)malloc(sizeof(struct bstnode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct bstnode *Insert(struct bstnode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(struct bstnode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

void Preorder(struct bstnode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct bstnode *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Postorder(struct bstnode *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

struct bstnode *Delete(struct bstnode *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: 1 child
        else if (root->left == NULL)
        {
            struct bstnode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct bstnode *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: 2 children
        else
        {
            struct bstnode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int FindHeight(struct bstnode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return fmax(FindHeight(root->left), FindHeight(root->right)) + 1;
}

struct bstnode *FindMin(struct bstnode *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct bstnode *FindMax(struct bstnode *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

int main(void)
{
    int ch, ch2, data;
    struct bstnode *root = NULL;
    struct bstnode *temp = NULL;
    while (1)
    {
        printf("\n\n1.Insertion\n2.Search\n3.Traversal\n4.Deletion\n5.Height of the tree\n6.Minimum element\n7.Maximum element\n8.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number to be inserted: ");
            scanf("%d", &data);
            root = Insert(root, data);
            break;
        case 2:
            printf("Enter the number to be searched: ");
            scanf("%d", &data);
            if (Search(root, data) == true)
                printf("Element found\n");
            else
                printf("Element not found\n");
            break;
        case 3:
            printf("1.Pre-Order\t2.In-Order\t3.Post-Order\n");
            printf("Enter choice: ");
            scanf("%d", &ch2);
            switch (ch2)
            {
            case 1:
                Preorder(root);
                break;
            case 2:
                Inorder(root);
                break;
            case 3:
                Postorder(root);
                break;
            default:
                printf("Error! Invalid choice\n");
            }
            break;
        case 4:
            printf("Enter number to be deleted: ");
            scanf("%d", &data);
            root = Delete(root, data);
            break;
        case 5:
            data = FindHeight(root);
            if (data == -1)
            {
                printf("Error! Tree Empty\n");
            }
            else
            {
                printf("Height: %d\n", data);
            }
            break;
        case 6:
            temp = FindMin(root);
            if (temp == NULL)
            {
                printf("Error! Tree Empty\n");
            }
            else
            {
                printf("Minimum element: %d\n", temp->data);
            }
            break;
        case 7:
            temp = FindMax(root);
            if (temp == NULL)
            {
                printf("Error! Tree Empty\n");
            }
            else
            {
                printf("Maximum element: %d\n", temp->data);
            }
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nError! Invalid choice\n");
        }
    }
}
