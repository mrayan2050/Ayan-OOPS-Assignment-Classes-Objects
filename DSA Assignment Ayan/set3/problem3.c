#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void findPredecessorSuccessor(struct Node* root, int key, struct Node** pred, struct Node** succ) {
    if (root == NULL) return;

    if (root->data == key) {
        if (root->left != NULL) {
            struct Node* temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            *pred = temp;
        }
        if (root->right != NULL) {
            struct Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            *succ = temp;
        }
        return;
    }

    if (key < root->data) {
        *succ = root;
        findPredecessorSuccessor(root->left, key, pred, succ);
    } else {
        *pred = root;
        findPredecessorSuccessor(root->right, key, pred, succ);
    }
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int choice, val, key;
    struct Node* temp = NULL;

    do {
        printf("\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Create / Insert a key\n");
        printf("2. Search a key\n");
        printf("3. Find In-order Predecessor and Successor\n");
        printf("4. Delete a key\n");
        printf("5. Display Tree (In-order traversal)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Key %d inserted.\n", val);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                temp = search(root, key);
                if (temp != NULL) {
                    printf("Key %d found in the BST.\n", key);
                } else {
                    printf("Key %d not found in the BST.\n", key);
                }
                break;

            case 3:
                printf("Enter key to find predecessor and successor: ");
                scanf("%d", &key);
                struct Node* pred = NULL;
                struct Node* succ = NULL;
                findPredecessorSuccessor(root, key, &pred, &succ);
                
                if (pred != NULL) {
                    printf("In-order Predecessor: %d\n", pred->data);
                } else {
                    printf("In-order Predecessor: None (or key outside range)\n");
                }
                
                if (succ != NULL) {
                    printf("In-order Successor: %d\n", succ->data);
                } else {
                    printf("In-order Successor: None (or key outside range)\n");
                }
                break;

            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Key %d deleted if it existed.\n", key);
                break;

            case 5:
                printf("Current BST (In-order): ");
                inOrder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                freeTree(root);
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}