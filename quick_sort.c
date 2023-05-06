#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for student data
typedef struct{
    char student_name[50];
    int student_roll_no;
    int total_marks;
}Student;

// Function to swap two Student elements
void swap(Student* a, Student* b, int* swap_count) {
    Student temp = *a;
    *a = *b;
    *b = temp;
    (*swap_count)++;
}

// Function to partition the array for Quick sort
int partition(Student arr[], int low, int high, int* swap_count) {
    Student pivot = arr[high];  // Pivot is the last element
    int i = low - 1;  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].student_roll_no < pivot.student_roll_no) {
            i++;
            swap(&arr[i], &arr[j], swap_count);
        }
    }
    swap(&arr[i + 1], &arr[high], swap_count);
    return (i + 1);
}

// Function to perform Quick sort
void quicksort(Student arr[], int low, int high, int* swap_count) {
    if (low < high) {
        int pi = partition(arr, low, high, swap_count);
        quicksort(arr, low, pi - 1, swap_count);
        quicksort(arr, pi + 1, high, swap_count);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for the array of students
    Student* students = (Student*)malloc(n * sizeof(Student));

    // Input student data
    for (int i = 0; i < n; i++) {
        printf("\nEnter the details of student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].student_name);
        printf("Roll no.: ");
        scanf("%d", &students[i].student_roll_no);
        printf("Total marks: ");
        scanf("%d", &students[i].total_marks);
    }

    // Sort the array of students
    int swap_count = 0;
    quicksort(students, 0, n - 1, &swap_count);

    // Output sorted student data
    printf("\nSorted student data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s\n", students[i].student_name);
        printf("Roll no.: %d\n", students[i].student_roll_no);
        printf("Total marks: %d\n", students[i].total_marks);
    }

    // Output number of swaps performed
    printf("\nNumber of swaps performed: %d\n", swap_count);

    // Free the memory allocated for the array of students
    free(students);

    return 0;
}
