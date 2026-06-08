#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Enter the number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\n--- Non-Zero Elements Per Row ---\n");
    for (int i = 0; i < rows; i++) {
        int nonZeroCount = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
        printf("Row %d: %d non-zero element(s)\n", i, nonZeroCount);
    }

    return 0;
}