#include <stdio.h>
#include <stdlib.h>

void get_values(int *arr, int size) {
    printf("Enter the values: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void merge_sort(int *A, int sizeA, int *B, int sizeB, int *C) {
    int i = 0, j = 0, k = 0;
    
    while (i < sizeA && j < sizeB) {
        if (A[i] < B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    while (i < sizeA) {
        C[k] = A[i];
        k++;
        i++;
    }

    while (j < sizeB) {
        C[k] = B[j];
        k++;
        j++;
    }
}

int main() {
    int size_1, size_2, size_3, *A, *B, *C;

    printf("Enter the size of the first array: ");
    scanf("%d", &size_1);
    printf("Enter the size of the second array: ");
    scanf("%d", &size_2);

    size_3 = size_1 + size_2;

    A = (int *)malloc(size_1 * sizeof(int));
    B = (int *)malloc(size_2 * sizeof(int));
    C = (int *)malloc(size_3 * sizeof(int));

    printf("Enter values for the first array:\n");
    get_values(A, size_1);

    printf("Enter values for the second array:\n");
    get_values(B, size_2);

    merge_sort(A, size_1, B, size_2, C);

    printf("Sorted array:\n");
    for (int i = 0; i < size_3; i++)
        printf("%d ", C[i]);

    free(A);
    free(B);
    free(C);

    return 0;
}
