#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a Student
struct Student {
    int rollNo;
    char name[50];
    char course[30];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

// Function to create a new student node
struct Student* createStudent(int rollNo, char name[], char course[], float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    strcpy(newStudent->course, course);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student
void addStudent() {
    int rollNo;
    char name[50];
    char course[30];
    float marks;

    printf("\nEnter Roll No: ");
    scanf("%d", &rollNo);
    getchar();
    printf("Enter Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Enter Course: ");
    fgets(course, sizeof(course), stdin);
    course[strcspn(course, "\n")] = 0;
    printf("Enter Marks: ");
    scanf("%f", &marks);

    struct Student* newStudent = createStudent(rollNo, name, course, marks);

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }

    printf("✅ Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (head == NULL) {
        printf("\n⚠ No students found!\n");
        return;
    }

    struct Student* temp = head;
    printf("\n--- Student List ---\n");
    while (temp != NULL) {
        printf("Roll No: %d | Name: %s | Course: %s | Marks: %.2f\n",
               temp->rollNo, temp->name, temp->course, temp->marks);
        temp = temp->next;
    }
}

// Function to search a student
void searchStudent() {
    int rollNo;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &rollNo);

    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            printf("✅ Student Found:\n");
            printf("Roll No: %d | Name: %s | Course: %s | Marks: %.2f\n",
                   temp->rollNo, temp->name, temp->course, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("⚠ Student not found!\n");
}

// Function to update student details
void updateStudent() {
    int rollNo;
    printf("\nEnter Roll No to update: ");
    scanf("%d", &rollNo);
    getchar();

    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            printf("Enter New Name: ");
            fgets(temp->name, sizeof(temp->name), stdin);
            temp->name[strcspn(temp->name, "\n")] = 0;
            printf("Enter New Course: ");
            fgets(temp->course, sizeof(temp->course), stdin);
            temp->course[strcspn(temp->course, "\n")] = 0;
            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);
            printf("✅ Student details updated!\n");
            return;
        }
        temp = temp->next;
    }
    printf("⚠ Student not found!\n");
}

// Function to delete a student
void deleteStudent() {
    int rollNo;
    printf("\nEnter Roll No to delete: ");
    scanf("%d", &rollNo);

    struct Student* temp = head;
    struct Student* prev = NULL;

    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("⚠ Student not found!\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("🗑 Student deleted successfully!\n");
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n=== STUDENT MANAGEMENT SYSTEM (Using Linked List) ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: printf("Thank you! Exiting program...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}