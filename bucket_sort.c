#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MARKS 100
#define BUCKET_SIZE 10

struct Student {
    char name[50];
    int rollNo;
    int marks;
};

void bucketSort(struct Student arr[], int n, int *swapCount) {
    // Create an array of buckets
    struct Student buckets[BUCKET_SIZE][n];
    int bucketIndex[BUCKET_SIZE] = {0};

    // Place each student in the appropriate bucket
    for (int i = 0; i < n; i++) {
        int bucketNo = arr[i].rollNo / BUCKET_SIZE;
        buckets[bucketNo][bucketIndex[bucketNo]++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 1; j < bucketIndex[i]; j++) {
            struct Student key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k].rollNo > key.rollNo) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
                (*swapCount)++;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Copy the sorted elements back to the original array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < bucketIndex[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *arr = malloc(n * sizeof(struct Student));
    printf("Enter the details of each student:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter name, roll no, and marks of student %d: ", i+1);
        scanf("%s %d %d", arr[i].name, &arr[i].rollNo, &arr[i].marks);
    }

    int swapCount = 0;
    bucketSort(arr, n, &swapCount);

    printf("Sorted array (by roll no):\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-5d %d\n", arr[i].name, arr[i].rollNo, arr[i].marks);
    }
    printf("Number of swaps: %d\n", swapCount);

    free(arr);
    return 0;
}
