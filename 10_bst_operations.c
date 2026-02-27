/*
 * Program: Binary Search Tree (BST) Implementation in C
 * Description:
 * This C program implements a Binary Search Tree (BST) with the following features:
 * 1. Create a BST by inserting elements (duplicates are ignored).
 * 2. Search for a key in the BST.
 * 3. Display BST using Preorder, Inorder, and Postorder traversals.
 */

#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *lchild;
    struct BST *rchild;
};
typedef struct BST * NODE;

/* Create a new BST node */
NODE create() {
    NODE temp = (NODE)malloc(sizeof(struct BST));
    if (temp == NULL) {
        printf("\nMemory allocation failed!");
        exit(1);
    }
    printf("\nEnter the value: ");
    scanf("%d", &temp->data);
    temp->lchild = temp->rchild = NULL;
    return temp;
}

/* Insert node into BST */
void insert(NODE root, NODE newnode) {
    if (newnode->data < root->data) {
        if (root->lchild == NULL)
            root->lchild = newnode;
        else
            insert(root->lchild, newnode);
    }
    else if (newnode->data > root->data) {
        if (root->rchild == NULL)
            root->rchild = newnode;
        else
            insert(root->rchild, newnode);
    }
    // Duplicate values are skipped
}

/* Search for a key in BST */
void search(NODE root) {
    int key;
    NODE cur;
    if (root == NULL) {
        printf("\nBST is empty.\n");
        return;
    }
    printf("\nEnter element to be searched: ");
    scanf("%d", &key);
    cur = root;
    while (cur != NULL) {
        if (cur->data == key) {
            printf("\nKey element is present in BST\n");
            return;
        }
        else if (key < cur->data)
            cur = cur->lchild;
        else
            cur = cur->rchild;
    }
    printf("\nKey element is not found in the BST\n");
}

/* Inorder traversal */
void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

/* Preorder traversal */
void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

/* Postorder traversal */
void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

/* Main function */
int main() {
    int ch, i, n;
    NODE root = NULL, newnode;

    while (1) {
        printf("\n~~~~BST MENU~~~~");
        printf("\n1. Create a BST");
        printf("\n2. BST Traversals");
        printf("\n3. Search");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("\nEnter the number of elements: ");
                scanf("%d", &n);
                for(i = 1; i <= n; i++) {
                    newnode = create();
                    if (root == NULL)
                        root = newnode;
                    else
                        insert(root, newnode);
                }
                break;

            case 2:
                if (root == NULL)
                    printf("\nTree is not created.\n");
                else {
                    printf("\nPreorder display: ");
                    preorder(root);
                    printf("\nInorder display: ");
                    inorder(root);
                    printf("\nPostorder display: ");
                    postorder(root);
                    printf("\n");
                }
                break;

            case 3:
                search(root);
                break;

            case 4:
                exit(0);

            default:
                printf("\nPlease enter a valid choice.\n");
        }
    }
}

~~~~BST MENU~~~~
1. Create a BST
2. BST Traversals
3. Search
4. Exit
Enter your choice: 1
Enter the number of elements: 8
Enter the value: 12
Enter the value: 20
Enter the value: 15
Enter the value: 40
Enter the value: 32
Enter the value: 25
Enter the value: 5
Enter the value: 50

Enter your choice: 2
Preorder display: 12 5 20 15 40 32 25 50
Inorder display: 5 12 15 20 25 32 40 50
Postorder display: 5 15 25 32 50 40 20 12

Enter your choice: 3
Enter element to be searched: 15
Key element is present in BST

Enter your choice: 3
Enter element to be searched: 10
Key element is not found in the BST
