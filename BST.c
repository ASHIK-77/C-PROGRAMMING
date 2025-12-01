#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
} Node;

// Create new node
Node* newnode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}

// Insert into BST
Node* insert(Node* root, int data) {
    if (root == NULL) 
        return newnode(data);

    if (data < root->data)
        root->lchild = insert(root->lchild, data);
    else if (data > root->data)
        root->rchild = insert(root->rchild, data);

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d  ", root->data);
        inorder(root->rchild);
    }
}

// Search in BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->lchild, data);
    else
        return search(root->rchild, data);
}

// Find minimum in right subtree
Node* findMin(Node* root) {
    while (root && root->lchild != NULL)
        root = root->lchild;
    return root;
}

// Delete node from BST
Node* delete(Node* root, int data) {
    if (root == NULL)
        return NULL;

    if (data < root->data) {
        root->lchild = delete(root->lchild, data);
    }
    else if (data > root->data) {
        root->rchild = delete(root->rchild, data);
    }
    else {  
        // Node found

        // Case 1: No child
        if (root->lchild == NULL && root->rchild == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->lchild == NULL) {
            Node* temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL) {
            Node* temp = root->lchild;
            free(root);
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->rchild);
        root->data = temp->data;
        root->rchild = delete(root->rchild, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, data;

    do {
        printf("\n--- MENU ---\n");
        printf("1. INSERTION\n");
        printf("2. SEARCH\n");
        printf("3. DELETION\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            printf("Inorder Traversal: ");
            inorder(root);
            break;

        case 2:
            printf("Enter element to search: ");
            scanf("%d", &data);
            if (search(root, data) != NULL)
                printf("%d found!\n", data);
            else
                printf("Not found!\n");
            break;

        case 3:
            printf("Enter element to delete: ");
            scanf("%d", &data);
            root = delete(root, data);
            printf("Inorder Traversal: ");
            inorder(root);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid input!\n");
        }

    } while (choice != 4);

    return 0;
}
