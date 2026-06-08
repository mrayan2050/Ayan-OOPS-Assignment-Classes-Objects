#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool validateInfix(char *expr) {
    int len = strlen(expr);
    int bracketCount = 0;
    bool expectOperand = true;

    if (len == 0) return false;

    for (int i = 0; i < len; i++) {
        char c = expr[i];

        if (c == '(') {
            bracketCount++;
            if (!expectOperand) return false;
        } 
        else if (c == ')') {
            bracketCount--;
            if (bracketCount < 0 || expectOperand) return false;
        } 
        else if (isOperator(c)) {
            if (expectOperand) return false;
            expectOperand = true;
        } 
        else if (isalnum(c)) {
            if (!expectOperand) return false;
            expectOperand = false;
        } 
        else {
            return false;
        }
    }

    return (bracketCount == 0 && !expectOperand);
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int k = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        } 
        else if (c == '(') {
            push(&s, c);
        } 
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); 
        } 
        else if (isOperator(c)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(c)) {
                if (c == '^' && peek(&s) == '^') {
                    break;
                }
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    if (scanf("%99s", infix) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    if (!validateInfix(infix)) {
        printf("Result: Invalid Infix Expression.\n");
        return 1;
    }

    printf("Validation: Successful (Valid Expression).\n");
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}