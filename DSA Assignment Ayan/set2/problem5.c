#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int cqueue[MAX];
int front = -1;
int rear = -1;

bool isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

bool isEmpty() {
    return front == -1;
}

void insert(int value) {
    if (isFull()) {
        printf("Queue Status: OVERFLOW! Cannot insert %d.\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    cqueue[rear] = value;
    printf("Successfully inserted %d\n", value);
}

void delete() {
    if (isEmpty()) {
        printf("Queue Status: UNDERFLOW! No elements to delete.\n");
        return;
    }
    printf("Successfully deleted %d\n", cqueue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

int getElementCount() {
    if (isEmpty()) {
        return 0;
    }
    if (rear >= front) {
        return (rear - front + 1);
    }
    return (MAX - front + rear + 1);
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
     printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Check number of elements\n");
        printf("4. Check overflow and underflow conditions\n");
        printf("5. Display queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

    while (1) {
       
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                printf("Number of elements: %d\n", getElementCount());
                break;
            case 4:
                if (isFull()) printf("Status: OVERFLOW condition met.\n");
                else if (isEmpty()) printf("Status: UNDERFLOW condition met.\n");
                else printf("Status: Neither Full nor Empty.\n");
                break;
            case 5:
                displayQueue();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}