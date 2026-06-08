#include <stdio.h>
#include <stdlib.h>

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

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            appendNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } 
        else if (poly1->exp < poly2->exp) {
            appendNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } 
        else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                appendNode(&result, sumCoeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        appendNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        appendNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
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
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;
    int n, coeff, exp;

    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient and exponent) in descending order of exponents:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        appendNode(&poly1, coeff, exp);
    }

    printf("\nEnter the number of terms for Polynomial 2: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient and exponent) in descending order of exponents:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        appendNode(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}