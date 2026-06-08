#include <stdio.h>
#include <stdlib.h>

struct Node {
    int player_id;
    struct Node* next;
};

struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->player_id = id;
    newNode->next = NULL;
    return newNode;
}

void solveJosephus(int n, int m) {
    if (n <= 0 || m <= 0) {
        printf("Invalid inputs.\n");
        return;
    }

    struct Node* head = createNode(1);
    struct Node* prev = head;

    for (int i = 2; i <= n; i++) {
        prev->next = createNode(i);
        prev = prev->next;
    }
    prev->next = head; 

    struct Node* curr = head;
    while (curr->next != curr) {
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        printf("Person %d eliminated.\n", curr->player_id);
        free(curr);
        curr = prev->next;
    }

    printf("\nThe safe position (Survivor) is: %d\n", curr->player_id);
    free(curr);
}

int main() {
    int n, m;

    printf("Enter the total number of people (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter the elimination step size (M): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    solveJosephus(n, m);

    return 0;
}