#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int len = strlen(str);
    int start = 0;
    int end = len - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    char arr[n][20];
    getchar(); 

    printf("Enter %d integers (one by one):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        if (scanf("%19s", arr[i]) != 1) {
            printf("Error reading input.\n");
            return 1;
        }
    }

    printf("\n--- Original Array ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        reverseString(arr[i]);
    }

    printf("\n--- Array After Reversing Individual Elements ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    return 0;
}