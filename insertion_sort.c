#include<stdio.h>
#include<string.h>

struct Student {
    char name[50];
    int roll_no;
    float total_marks;
};

int main() {
    int i, j, n, count = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student arr[n], temp;
    for(i = 0; i < n; i++) {
        printf("Enter the details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", arr[i].name);
        printf("Roll Number: ");
        scanf("%d", &arr[i].roll_no);
        printf("Total Marks: ");
        scanf("%f", &arr[i].total_marks);
    }

    // Insertion sort
    for(i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j].roll_no > temp.roll_no) {
            arr[j+1] = arr[j];
            j--;
            count++;
        }
        arr[j+1] = temp;
    }

    printf("Sorted array of students by Roll Number:\n");
    for(i = 0; i < n; i++) {
        printf("Student %d: %s, Roll Number: %d, Total Marks: %.2f\n", i+1, arr[i].name, arr[i].roll_no, arr[i].total_marks);
    }

    printf("Number of swaps performed: %d\n", count);
    return 0;
}
