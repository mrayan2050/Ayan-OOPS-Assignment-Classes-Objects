#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = *head;
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
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
    } else {
        prev->next = temp->next;
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
        return;
    }
    printReverse(head->next);
    printf("%d ", head->data);
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("Linked list completely reversed.\n");
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Insert a node at a specified position\n");
        printf("2. Delete a node from a specified position\n");
        printf("3. Count the number of nodes\n");
        printf("4. Print the linked list in reverse order\n");
        printf("5. Reverse the linked list entirely\n");
        printf("6. Display original/current list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

    while (1) {
    

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
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    printf("List in reverse order: ");
                    printReverse(head);
                    printf("\n");
                }
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