#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertSingly(struct Node** front, struct Node** rear, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow!\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    if (*front == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Inserted %d into Singly Linked List Queue.\n", val);
}

void deleteSingly(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    struct Node* temp = *front;
    printf("Deleted %d from Singly Linked List Queue.\n", temp->data);
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

void displaySingly(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Singly Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertCircular(struct Node** rear, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow!\n");
        return;
    }
    newNode->data = val;
    if (*rear == NULL) {
        newNode->next = newNode;
        *rear = newNode;
    } else {
        newNode->next = (*rear)->next;
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Inserted %d into Circular Linked List Queue.\n", val);
}

void deleteCircular(struct Node** rear) {
    if (*rear == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    struct Node* front = (*rear)->next;
    if (front == *rear) {
        printf("Deleted %d from Circular Linked List Queue.\n", front->data);
        free(front);
        *rear = NULL;
    } else {
        printf("Deleted %d from Circular Linked List Queue.\n", front->data);
        (*rear)->next = front->next;
        free(front);
    }
}

void displayCircular(struct Node* rear) {
    if (rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* front = rear->next;
    struct Node* temp = front;
    printf("Circular Queue: ");
    while (1) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        if (temp == front) {
            break;
        }
    }
    printf("(loops back to front)\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeCircularList(struct Node* rear) {
    if (rear == NULL) return;
    struct Node* front = rear->next;
    struct Node* curr = front;
    struct Node* nextNode;
    while (1) {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
        if (curr == front) {
            break;
        }
    }
}

int main() {
    struct Node* sFront = NULL;
    struct Node* sRear = NULL;
    struct Node* cRear = NULL;

    int typeChoice, opChoice, val;

    while (1) {
        printf("1. Operate on Singly Linked List Queue\n");
        printf("2. Operate on Circular Linked List Queue\n");
        printf("3. Exit Program\n");
        printf("Enter your choice: ");
        if (scanf("%d", &typeChoice) != 1) break;

        if (typeChoice == 3) {
            break;
        }

        if (typeChoice == 1) {
            while (1) {
                printf("1. Insertion (Enqueue)\n");
                printf("2. Deletion (Dequeue)\n");
                printf("3. Display\n");
                printf("4. Back to Main Menu\n");
                printf("Enter choice: ");
                scanf("%d", &opChoice);

                if (opChoice == 4) break;
                switch (opChoice) {
                    case 1:
                        printf("Enter value to insert: ");
                        scanf("%d", &val);
                        insertSingly(&sFront, &sRear, val);
                        break;
                    case 2:
                        deleteSingly(&sFront, &sRear);
                        break;
                    case 3:
                        displaySingly(sFront);
                        break;
                    default:
                        printf("Invalid operation!\n");
                }
            }
        } else if (typeChoice == 2) {
            while (1) {
                printf("1. Insertion (Enqueue)\n");
                printf("2. Deletion (Dequeue)\n");
                printf("3. Display\n");
                printf("4. Back to Main Menu\n");
                printf("Enter choice: ");
                scanf("%d", &opChoice);

                if (opChoice == 4) break;
                switch (opChoice) {
                    case 1:
                        printf("Enter value to insert: ");
                        scanf("%d", &val);
                        insertCircular(&cRear, val);
                        break;
                    case 2:
                        deleteCircular(&cRear);
                        break;
                    case 3:
                        displayCircular(cRear);
                        break;
                    default:
                        printf("Invalid operation!\n");
                }
            }
        } else {
            printf("Invalid selection!\n");
        }
    }

    freeList(sFront);
    freeCircularList(cRear);
    return 0;
}