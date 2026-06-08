#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (position == 1) {
        if (*head != NULL) {
            newNode->next = *head;
            (*head)->prev = newNode;
        }
        *head = newNode;
        printf("Node inserted successfully.\n");
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        printf("Node inserted successfully.\n");
    }
}

void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("List is empty or invalid position!\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
    } else {
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(temp);
        printf("Node deleted successfully.\n");
    }
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printReverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("List in reverse order: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = *head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
    printf("Doubly linked list completely reversed.\n");
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: NULL <- ");
    while (temp != NULL) {
        printf("[%d]", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert a node at a specified position\n");
        printf("2. Delete a node from a specified position\n");
        printf("3. Count the number of nodes\n");
        printf("4. Print the linked list in reverse order\n");
        printf("5. Reverse the linked list entirely\n");
        printf("6. Display original/current list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (1-based index): ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 2:
                printf("Enter position to delete (1-based index): ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 3:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                printReverse(head);
                break;
            case 5:
                reverseList(&head);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}