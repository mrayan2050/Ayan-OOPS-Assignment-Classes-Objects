#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

double evaluatePolynomial(struct Node* head, double x) {
    double result = 0.0;
    struct Node* temp = head;
    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
}

void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL && temp->coeff >= 0) {
            printf(" + ");
        } else if (temp != NULL && temp->coeff < 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* poly = NULL;
    int n, coeff, exp;
    double x, evaluationResult;

    printf("Enter the number of terms for the sparse polynomial: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    printf("Enter terms (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        appendNode(&poly, coeff, exp);
    }

    printf("\nEnter the value of x to evaluate: ");
    scanf("%lf", &x);

    printf("\nPolynomial: ");
    displayPolynomial(poly);

    evaluationResult = evaluatePolynomial(poly, x);

    printf("Result of evaluation for x = %.2lf: %.2lf\n", x, evaluationResult);

    freePolynomial(poly);
    return 0;
}