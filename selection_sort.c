#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll_no;
    float total_marks;
};

int selectionSort(struct Student arr[], int n) {
    int i, j, min_idx, swap_count = 0;
    struct Student temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].roll_no < arr[min_idx].roll_no) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swap_count++;
        }
    }

    return swap_count;
}

int main() {
    int n, i, swap_count;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student students[n];

    for (i = 0; i < n; i++) {
        printf("Enter the details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Total Marks: ");
        scanf("%f", &students[i].total_marks);
    }

    printf("\nBefore sorting:\n");
    for (i = 0; i < n; i++) {
        printf("Roll No: %d, Name: %s, Total Marks: %.2f\n", students[i].roll_no, students[i].name, students[i].total_marks);
    }

    swap_count = selectionSort(students, n);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("Roll No: %d, Name: %s, Total Marks: %.2f\n", students[i].roll_no, students[i].name, students[i].total_marks);
    }

    printf("\nNumber of swaps performed: %d\n", swap_count);

    return 0;
}

