#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
    printf("Successfully pushed %d onto the stack.\n", val);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements (Top to Bottom):\n");
    while (temp != NULL) {
        printf("| %d |\n", temp->data);
        temp = temp->next;
    }
    printf("-----\n");
}

int main() {
    struct Node* top = NULL;
    int choice, val;

    while (1) {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&top, val);
                break;
            case 2:
                val = pop(&top);
                if (val != -1) {
                    printf("Popped element: %d\n", val);
                }
                break;
            case 3:
                val = peek(top);
                if (val != -1) {
                    printf("Element at the top: %d\n", val);
                }
                break;
            case 4:
                displayStack(top);
                break;
            case 5:
                while (top != NULL) {
                    struct Node* temp = top;
                    top = top->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}