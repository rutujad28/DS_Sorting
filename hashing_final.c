#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Employee {
    int empId;
    char empName[20];
    char empDept[20];
};

struct HashTable {
    struct Employee empList[SIZE];
    int status[SIZE];
};

int hash(int key) {
    return key % SIZE;
}

void insert(struct Employee emp, struct HashTable *table) {
    int hashValue = hash(emp.empId);
    int index = hashValue;
    int i = 1;

    while(table->status[index] == 1) {
        index = (hashValue + i) % SIZE;
        i++;

        if (i > SIZE) {
            printf("\nHash table is full. Cannot insert employee with ID %d\n", emp.empId);
            return;
        }
    }

    table->empList[index] = emp;
    table->status[index] = 1;

    printf("\nEmployee with ID %d inserted at index %d\n", emp.empId, index);
}


void search(int empId, struct HashTable table) {
    int hashValue = hash(empId);
    int index = hashValue;
    int i = 1;

    while(table.status[index] != 0) {
        if(table.empList[index].empId == empId) {
            printf("\nEmployee ID: %d\nEmployee Name: %s\nEmployee Department: %s\n", table.empList[index].empId, table.empList[index].empName, table.empList[index].empDept);
            return;
        }
        index = (hashValue + i) % SIZE;
        i++;
    }

    printf("\nEmployee with ID %d not found in the hash table\n", empId);
}

void display(struct HashTable table) {
    printf("\nHash Table\n");
    printf("Index\tEmployee ID\tEmployee Name\tEmployee Department\n");
    for(int i=0; i<SIZE; i++) {
        printf("%d\t", i);
        if(table.status[i] == 1) {
            printf("%d\t\t%s\t\t%s\n", table.empList[i].empId, table.empList[i].empName, table.empList[i].empDept);
        }
        else {
            printf("---\t\t---\t\t---\n");
        }
    }
}

int main() {
    struct HashTable table;
    memset(table.status, 0, SIZE * sizeof(int));

    int choice, empId;

    while(1) {
        printf("\nMenu\n");
        printf("1. Insert Employee\n");
        printf("2. Search Employee\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                struct Employee emp;
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp.empId);
                printf("Enter Employee Name: ");
                scanf("%s", emp.empName);
                printf("Enter Employee Department: ");
                scanf("%s", emp.empDept);
                insert(emp, &table);
                break;
            }
            case 2: {
                printf("\nEnter Employee ID to search: ");
                scanf("%d", &empId);
                search(empId, table);
                break;
            }
            case 3: {
                display(table);
                break;
            }
            case 4: {
                printf("\nExiting...");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Try again.\n");
                break;
            }
        }
    }

    return 0;
}