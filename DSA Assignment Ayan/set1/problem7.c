#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void readMatrix(int matrix[MAX][3], int rows, int cols, int nonZero) {
    matrix[0][0] = rows;
    matrix[0][1] = cols;
    matrix[0][2] = nonZero;

    printf("Enter row, column, and value for each non-zero element:\n");
    for (int i = 1; i <= nonZero; i++) {
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    }
}

void addSparseMatrices(int m1[MAX][3], int m2[MAX][3], int result[MAX][3]) {
    if (m1[0][0] != m2[0][0] || m1[0][1] != m2[0][1]) {
        printf("Error: Matrix dimensions do not match. Addition impossible.\n");
        exit(1);
    }

    result[0][0] = m1[0][0];
    result[0][1] = m1[0][1];

    int i = 1, j = 1, k = 1;
    int t1 = m1[0][2];
    int t2 = m2[0][2];

    while (i <= t1 && j <= t2) {
        if (m1[i][0] < m2[j][0]) {
            result[k][0] = m1[i][0];
            result[k][1] = m1[i][1];
            result[k][2] = m1[i][2];
            i++; k++;
        } 
        else if (m1[i][0] > m2[j][0]) {
            result[k][0] = m2[j][0];
            result[k][1] = m2[j][1];
            result[k][2] = m2[j][2];
            j++; k++;
        } 
        else {
            if (m1[i][1] < m2[j][1]) {
                result[k][0] = m1[i][0];
                result[k][1] = m1[i][1];
                result[k][2] = m1[i][2];
                i++; k++;
            } 
            else if (m1[i][1] > m2[j][1]) {
                result[k][0] = m2[j][0];
                result[k][1] = m2[j][1];
                result[k][2] = m2[j][2];
                j++; k++;
            } 
            else {
                int sum = m1[i][2] + m2[j][2];
                if (sum != 0) {
                    result[k][0] = m1[i][0];
                    result[k][1] = m1[i][1];
                    result[k][2] = sum;
                    k++;
                }
                i++; j++;
            }
        }
    }

    while (i <= t1) {
        result[k][0] = m1[i][0];
        result[k][1] = m1[i][1];
        result[k][2] = m1[i][2];
        i++; k++;
    }

    while (j <= t2) {
        result[k][0] = m2[j][0];
        result[k][1] = m2[j][1];
        result[k][2] = m2[j][2];
        j++; k++;
    }

    result[0][2] = k - 1;
}

void printTriplet(int matrix[MAX][3]) {
    int totalElements = matrix[0][2];
    printf("\nTriplet Representation:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= totalElements; i++) {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

int main() {
    int m1[MAX][3], m2[MAX][3], result[MAX][3];
    int rows, cols, nz1, nz2;

    printf("Enter total rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter number of non-zero elements for Matrix 1: ");
    scanf("%d", &nz1);
    readMatrix(m1, rows, cols, nz1);

    printf("\nEnter number of non-zero elements for Matrix 2: ");
    scanf("%d", &nz2);
    readMatrix(m2, rows, cols, nz2);

    addSparseMatrices(m1, m2, result);

    printf("\n--- Resulting Sparse Matrix ---");
    printTriplet(result);

    return 0;
}