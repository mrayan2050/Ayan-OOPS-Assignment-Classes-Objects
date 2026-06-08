#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int arr[], int n, int verbose) {
    int i, key, j, pass = 1;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        if (verbose) {
            printf("Pass %d: ", pass++);
            printArray(arr, n);
        }
    }
}

void selectionSort(int arr[], int n, int verbose) {
    int i, j, min_idx, pass = 1;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
        if (verbose) {
            printf("Pass %d: ", pass++);
            printArray(arr, n);
        }
    }
}

void bubbleSort(int arr[], int n, int verbose) {
    int i, j, pass = 1;
    for (i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (verbose) {
            printf("Pass %d: ", pass++);
            printArray(arr, n);
        }
        if (swapped == 0) break;
    }
}

int partition(int arr[], int low, int high, int n, int* pass, int verbose) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    if (verbose) {
        printf("Pivot '%d' Split (Pass %d): ", pivot, (*pass)++);
        printArray(arr, n);
    }
    return (i + 1);
}

void quickSortHelper(int arr[], int low, int high, int n, int* pass, int verbose) {
    if (low < high) {
        int pi = partition(arr, low, high, n, pass, verbose);
        quickSortHelper(arr, low, pi - 1, n, pass, verbose);
        quickSortHelper(arr, pi + 1, high, n, pass, verbose);
    }
}

void quickSort(int arr[], int n, int verbose) {
    int pass = 1;
    quickSortHelper(arr, 0, n - 1, n, &pass, verbose);
}

void merge(int arr[], int l, int m, int r, int n, int* pass, int verbose) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
    free(L);
    free(R);
    if (verbose) {
        printf("Merge Step %d: ", (*pass)++);
        printArray(arr, n);
    }
}

void mergeSortHelper(int arr[], int l, int r, int n, int* pass, int verbose) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m, n, pass, verbose);
        mergeSortHelper(arr, m + 1, r, n, pass, verbose);
        merge(arr, l, m, r, n, pass, verbose);
    }
}

void mergeSort(int arr[], int n, int verbose) {
    int pass = 1;
    mergeSortHelper(arr, 0, n - 1, n, &pass, verbose);
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n, int verbose) {
    int pass = 1;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
        if (verbose) {
            printf("Extract Step %d: ", pass++);
            printArray(arr, n);
        }
    }
}

void runBenchmark() {
    int size = 10000;
    int* original = (int*)malloc(size * sizeof(int));
    int* duplicate = (int*)malloc(size * sizeof(int));
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        original[i] = rand() % 50000;
    }

    printf("BENCHMARK PERFORMANCE (10,000 INTEGERS)\n");

    memcpy(duplicate, original, size * sizeof(int));
    start = clock();
    insertionSort(duplicate, size, 0);
    end = clock();
    printf("i.   Insertion Sort : %10.2f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    memcpy(duplicate, original, size * sizeof(int));
    start = clock();
    selectionSort(duplicate, size, 0);
    end = clock();
    printf("ii.  Selection Sort : %10.2f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    memcpy(duplicate, original, size * sizeof(int));
    start = clock();
    bubbleSort(duplicate, size, 0);
    end = clock();
    printf("iii. Bubble Sort    : %10.2f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    memcpy(duplicate, original, size * sizeof(int));
    start = clock();
    quickSort(duplicate, size, 0);
    end = clock();
    printf("iv.  Quick Sort     : %10.2f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    memcpy(duplicate, original, size * sizeof(int));
    start = clock();
    mergeSort(duplicate, size, 0);
    end = clock();
    printf("v.   Merge Sort     : %10.2f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    memcpy(duplicate, original, size * sizeof(int));
    start = clock();
    heapSort(duplicate, size, 0);
    end = clock();
    printf("vi.  Heap Sort      : %10.2f ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);
    printf("===========================================\n");

    free(original);
    free(duplicate);
}

int main() {
    int choice;
    int testSize;

    do {
        printf("\n=== SORTING ALGORITHMS MENU ===\n");
        printf("1. Run Sort Demonstrations (With Pass Outputs)\n");
        printf("2. Compare Performance on 10,000 Integers\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number of elements to sort: ");
            scanf("%d", &testSize);
            int* arr = (int*)malloc(testSize * sizeof(int));
            int* copy = (int*)malloc(testSize * sizeof(int));

            printf("Enter %d integers: ", testSize);
            for (int i = 0; i < testSize; i++) {
                scanf("%d", &arr[i]);
            }

            printf("\n--- i. Insertion Sort ---\n");
            memcpy(copy, arr, testSize * sizeof(int));
            insertionSort(copy, testSize, 1);

            printf("\n--- ii. Selection Sort ---\n");
            memcpy(copy, arr, testSize * sizeof(int));
            selectionSort(copy, testSize, 1);

            printf("\n--- iii. Bubble Sort ---\n");
            memcpy(copy, arr, testSize * sizeof(int));
            bubbleSort(copy, testSize, 1);

            printf("\n--- iv. Quick Sort ---\n");
            memcpy(copy, arr, testSize * sizeof(int));
            quickSort(copy, testSize, 1);

            printf("\n--- v. Merge Sort ---\n");
            memcpy(copy, arr, testSize * sizeof(int));
            mergeSort(copy, testSize, 1);

            printf("\n--- vi. Heap Sort ---\n");
            memcpy(copy, arr, testSize * sizeof(int));
            heapSort(copy, testSize, 1);

            free(arr);
            free(copy);
        } else if (choice == 2) {
            runBenchmark();
        }
    } while (choice != 3);

    return 0;
}