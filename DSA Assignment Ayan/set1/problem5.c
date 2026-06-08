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

void insertInOrder(struct Node** head, int coeff, int exp) {
    if (coeff == 0) return;

    struct Node* prev = NULL;
    struct Node* curr = *head;

    while (curr != NULL && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && curr->exp == exp) {
        curr->coeff += coeff;
        if (curr->coeff == 0) {
            if (prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
        }
        return;
    }

    struct Node* newNode = createNode(coeff, exp);
    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = curr;
        prev->next = newNode;
    }
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* t1 = poly1;

    while (t1 != NULL) {
        struct Node* t2 = poly2;
        while (t2 != NULL) {
            int c = t1->coeff * t2->coeff;
            int e = t1->exp + t2->exp;
            insertInOrder(&result, c, e);
            t2 = t2->next;
        }
        t1 = t1->next;
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

    printf("Enter number of terms for Polynomial 1: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertInOrder(&poly1, coeff, exp);
    }

    printf("\nEnter number of terms for Polynomial 2: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertInOrder(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = multiplyPolynomials(poly1, poly2);

    printf("Product Polynomial: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}