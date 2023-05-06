#include<stdio.h>
#include<string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    float total_marks;
};

void merge(struct Student arr[], int l, int m, int r, int *count) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    struct Student L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i].student_roll_no <= R[j].student_roll_no) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            *count += (n1 - i);
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(struct Student arr[], int l, int r, int *count) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m, count);
        mergeSort(arr, m + 1, r, count);
 
        merge(arr, l, m, r, count);
    }
}

int main() {
    int n, count = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student arr[n];

    for(int i=0; i<n; i++) {
        printf("Enter the details of student %d\n", i+1);
        printf("Name: ");
        scanf("%s", arr[i].student_name);
        printf("Roll No: ");
        scanf("%d", &arr[i].student_roll_no);
        printf("Total Marks: ");
        scanf("%f", &arr[i].total_marks);
    }

    mergeSort(arr, 0, n-1, &count);

    printf("\nSorted array of students by roll number:\n");
    for(int i=0; i<n; i++) {
        printf("Name: %s, Roll No: %d, Total Marks: %.2f\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }

    printf("\nNumber of swaps performed: %d", count);

    return 0;
}
