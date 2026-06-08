#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

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

int pop(Stack *s, bool *error) {
    if (isEmpty(s)) {
        *error = true;
        return 0;
    }
    return s->data[(s->top)--];
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int performOperation(char op, int op1, int op2, bool *error) {
    switch (op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': 
            if (op2 == 0) {
                *error = true;
                return 0;
            }
            return op1 / op2;
        case '^': return (int)pow(op1, op2);
        default: *error = true; return 0;
    }
}

int main() {
    char postfix[MAX];
    Stack s;
    initStack(&s);
    bool error = false;

    printf("Enter a postfix expression : ");
    if (scanf("%99s", postfix) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            push(&s, c - '0');
        } 
        else if (isOperator(c)) {
            int val2 = pop(&s, &error);
            int val1 = pop(&s, &error);

            if (error) {
                printf("Result: Invalid Postfix Expression (Operator syntax mismatch).\n");
                return 1;
            }

            int res = performOperation(c, val1, val2, &error);
            if (error) {
                printf("Result: Runtime mathematical error (e.g., Division by zero).\n");
                return 1;
            }
            push(&s, res);
        } 
        else {
            printf("Result: Invalid characters detected in expression.\n");
            return 1;
        }
    }

    int finalResult = pop(&s, &error);

    if (!isEmpty(&s) || error) {
        printf("Result: Invalid Postfix Expression (Operand mismatch).\n");
        return 1;
    }

    printf("Validation: Successful (Valid Expression).\n");
    printf("Evaluation Result: %d\n", finalResult);

    return 0;
}