#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int roll_no;
    int marks;
};

int bubble_sort(struct student arr[], int n) {
    int swap_count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                struct student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (swap_count)++;
            }
        }
    }
    return swap_count;
}

int main() {
    int n, swap_count;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student arr[n];
    printf("Enter the student details (name, roll no, marks):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", arr[i].name, &arr[i].roll_no, &arr[i].marks);
    }

    bubble_sort(arr, n);

    printf("\nSorted student details (sorted by roll no):\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", arr[i].name, arr[i].roll_no, arr[i].marks);
    }

    printf("\nNumber of swaps performed: %d\n", swap_count);

    return 0;
}
