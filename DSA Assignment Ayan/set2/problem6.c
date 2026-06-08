#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int val) {
    if (!isFull(s)) {
        s->data[++(s->top)] = val;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

typedef struct {
    Stack s1;
    Stack s2;
} Queue;

void initQueue(Queue *q) {
    initStack(&(q->s1));
    initStack(&(q->s2));
}

void enqueue(Queue *q, int val) {
    if (isFull(&(q->s1))) {
        printf("Queue Overflow!\n");
        return;
    }
    push(&(q->s1), val);
    printf("Enqueued: %d\n", val);
}

int dequeue(Queue *q) {
    if (isEmpty(&(q->s1)) && isEmpty(&(q->s2))) {
        printf("Queue Underflow!\n");
        return -1;
    }

    if (isEmpty(&(q->s2))) {
        while (!isEmpty(&(q->s1))) {
            push(&(q->s2), pop(&(q->s1)));
        }
    }

    return pop(&(q->s2));
}

void displayQueue(Queue *q) {
    if (isEmpty(&(q->s1)) && isEmpty(&(q->s2))) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->s2.top; i >= 0; i--) {
        printf("%d ", q->s2.data[i]);
    }
    for (int i = 0; i <= q->s1.top; i++) {
        printf("%d ", q->s1.data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, val;
        printf("\n--- QUEUE USING TWO STACKS ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
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
                val = dequeue(&q);
                if (val != -1) {
                    printf("Dequeued: %d\n", val);
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