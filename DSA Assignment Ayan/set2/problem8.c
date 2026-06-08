#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

bool isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

bool isEmpty() {
    return front == -1;
}

void insertFront(int val) {
    if (isFull()) {
        printf("Overflow! Cannot insert at front.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = val;
    printf("Inserted %d at front.\n", val);
}

void insertRear(int val) {
    if (isFull()) {
        printf("Overflow! Cannot insert at rear.\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = val;
    printf("Inserted %d at rear.\n", val);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Underflow! Deque is empty.\n");
        return;
    }

    printf("Deleted %d from front.\n", deque[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Underflow! Deque is empty.\n");
        return;
    }

    printf("Deleted %d from rear.\n", deque[rear]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

    while (1) {
        

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}