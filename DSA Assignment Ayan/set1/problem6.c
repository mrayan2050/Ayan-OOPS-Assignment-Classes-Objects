#include <stdio.h>
#include <string.h>

#define MAX 1000

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

void addLargeNumbers(char *num1, char *num2, char *result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;

        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }

        carry = sum / 10;
        result[k++] = (sum % 10) + '0';
    }

    result[k] = '\0';
    reverseString(result);
}

int main() {
    char num1[MAX];
    char num2[MAX];
    char result[MAX + 1];

    printf("Enter first large number: ");
    if (scanf("%999s", num1) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter second large number: ");
    if (scanf("%999s", num2) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    addLargeNumbers(num1, num2, result);

    printf("\nSum: %s\n", result);

    return 0;
}