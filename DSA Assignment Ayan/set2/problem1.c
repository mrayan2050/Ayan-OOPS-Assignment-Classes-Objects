#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
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

void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

bool isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return true;
    if (char1 == '{' && char2 == '}') return true;
    if (char1 == '[' && char2 == ']') return true;
    return false;
}

bool isBalanced(char *expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&s, expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty(&s)) {
                return false;
            }
            char topChar = pop(&s);
            if (!isMatchingPair(topChar, expr[i])) {
                return false;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    if (scanf("%99s", expr) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isBalanced(expr)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is NOT balanced.\n");
    }

    return 0;
}