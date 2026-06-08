#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

bool isFull() {
    return rear == MAX - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

void insert(int value) {
    if (isFull()) {
        printf("Queue Status: OVERFLOW! Cannot insert %d.\n", value);
        return;
    }
    if (front == -1) {
        front = 0; 
    }
    rear++;
    queue[rear] = value;
    printf("Successfully inserted %d into the queue.\n", value);
}

void delete() {
    if (isEmpty()) {
        printf("Queue Status: UNDERFLOW! No elements to delete.\n");
        return;
    }
    printf("Successfully deleted %d from the queue.\n", queue[front]);
    front++;
    
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

int getElementCount() {
    if (isEmpty()) {
        return 0;
    }
    return (rear - front + 1);
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is currently empty.\n");
        return;
    }
    printf("Current Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("[%d] ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
        printf("1. Insertion (Enqueue)\n");
        printf("2. Deletion (Dequeue)\n");
        printf("3. Check Number of Elements\n");
        printf("4. Check Overflow / Underflow Status\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");

    while (1) {
        
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
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
                printf("Total elements currently in queue: %d\n", getElementCount());
                break;

            case 4:
                if (isFull()) {
                    printf("Status: OVERFLOW condition reached (Queue is full).\n");
                } else if (isEmpty()) {
                    printf("Status: UNDERFLOW condition reached (Queue is empty).\n");
                } else {
                    printf("Status: Normal operations. Queue is neither full nor empty.\n");
                }
                break;

            case 5:
                displayQueue();
                break;

            case 6:
                printf("Exiting program. Tata! Goodbye! Gaya!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option from 1 to 6.\n");
        }
    }

    return 0;
}