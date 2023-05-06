#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int roll_no;
    float marks;
};

void heapify(struct student arr[], int n, int i, int *swap_count) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].roll_no > arr[largest].roll_no) {
        largest = left;
    }

    if (right < n && arr[right].roll_no > arr[largest].roll_no) {
        largest = right;
    }

    if (largest != i) {
        struct student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*swap_count)++;
        heapify(arr, n, largest, swap_count);
    }
}

void heap_sort(struct student arr[], int n, int *swap_count) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, swap_count);
    }

    for (i = n - 1; i >= 0; i--) {
        struct student temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        (*swap_count)++;
        heapify(arr, i, 0, swap_count);
    }
}

int main() {
    int n, i, swap_count = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student *arr = (struct student *) malloc(n * sizeof(struct student));

    for (i = 0; i < n; i++) {
        printf("Enter the name, roll no, and marks of student %d: ", i + 1);
        scanf("%s%d%f", arr[i].name, &arr[i].roll_no, &arr[i].marks);
    }

    heap_sort(arr, n, &swap_count);

    printf("\nSorted array (by roll no):\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%.2f\n", arr[i].name, arr[i].roll_no, arr[i].marks);
    }

    printf("\nNumber of swaps performed: %d\n", swap_count);

    free(arr);
    return 0;
}
