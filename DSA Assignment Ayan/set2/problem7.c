#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

bool isQueueFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int val) {
    if (isQueueFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->data[++(q->rear)] = val;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        return -1;
    }
    int val = q->data[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return val;
}

void initStack(Stack *s) {
    s->top = -1;
}

bool isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

void reverseQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        return;
    }

    Stack s;
    initStack(&s);

    while (!isQueueEmpty(q)) {
        push(&s, dequeue(q));
    }

    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, val;
        printf("\n--- REVERSE QUEUE USING STACK ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Reverse Queue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

    while (1) {
        

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                if (isQueueEmpty(&q)) {
                    printf("Queue is empty! Nothing to reverse.\n");
                } else {
                    reverseQueue(&q);
                    printf("Queue reversed successfully.\n");
                }
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}