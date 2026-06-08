#include <stdio.h>
#include <string.h>

void reverseString(const char *src, char *dest) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        dest[i] = src[len - 1 - i];
    }
    dest[len] = '\0';
}

int main() {
    char original[100];
    char firstReverse[100];
    char secondReverse[100];

    printf("Enter a number: ");
    if (scanf("%99s", original) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    reverseString(original, firstReverse);

    reverseString(firstReverse, secondReverse);

    printf("Original Number:         %s\n", original);
    printf("After First Reversal:    %s\n", firstReverse);
    printf("After Second Reversal:   %s\n", secondReverse);

    if (strcmp(original, secondReverse) == 0) {
        printf("Success: The twice-reversed number ALWAYS matches the original!\n");
    } else {
        printf("Error: They do not match.\n");
    }

    return 0;
}