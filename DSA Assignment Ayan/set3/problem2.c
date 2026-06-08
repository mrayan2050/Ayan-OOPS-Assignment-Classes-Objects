#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(char arr[], int strt, int end, char value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd, int* preIndex) {
    if (inStrt > inEnd) {
        return NULL;
    }

    struct Node* tNode = createNode(pre[*preIndex]);
    (*preIndex)++;

    if (inStrt == inEnd) {
        return tNode;
    }

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

void postOrder(struct Node* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%c ", node->data);
}

void freeTree(struct Node* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    int preIndex = 0;

    struct Node* root = buildTree(in, pre, 0, len - 1, &preIndex);

    printf("Post-order traversal of the constructed tree is: ");
    postOrder(root);
    printf("\n");

    freeTree(root);
    return 0;
}