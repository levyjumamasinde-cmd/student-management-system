#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Structure definition
struct Student {
    char name[50];
    char admissionNumber[20];
    int age;
    float marks[3];
    float average;
    char grade;
};

struct Student students[MAX];
int count = 0;

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void bestStudent();
char calculateGrade(float average);
void calculateAverageAndGrade(struct Student *s);
void saveToFile();
void loadFromFile();

int main() {
    int choice;

    // Load saved students from file
    loadFromFile();

    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Best Performing Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                bestStudent();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}

// Function to calculate average and grade
void calculateAverageAndGrade(struct Student *s) {
    s->average = (s->marks[0] + s->marks[1] + s->marks[2]) / 3.0;
    s->grade = calculateGrade(s->average);
}

// Function to determine grade
char calculateGrade(float average) {
    if (average >= 70)
        return 'A';
    else if (average >= 60)
        return 'B';
    else if (average >= 50)
        return 'C';
    else if (average >= 40)
        return 'D';
    else
        return 'E';
}

// Add student
void addStudent() {
    if(count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter student name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter admission number: ");
    scanf("%s", &students[count].admissionNumber);

    printf("Enter age: ");
    scanf("%d", &students[count].age);

    for(int i = 0; i < 3; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &students[count].marks[i]);
    }

    calculateAverageAndGrade(&students[count]);

    printf("Student added successfully!\n");

    count++;

    // Save data to file
    saveToFile();
}

// Display all students
void displayStudents() {
    if(count == 0) {
        printf("No students available.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("\n----- Student %d -----\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Admission Number: %s\n", students[i].admissionNumber);
        printf("Age: %d\n", students[i].age);
        printf("Average: %.2f\n", students[i].average);
        printf("Grade: %c\n", students[i].grade);
    }
}

// Search student
void searchStudent() {
    char adm[20];
    int found = 0;

    printf("Enter admission number to search: ");
    scanf("%s", &adm);

    for(int i = 0; i < count; i++) {
        if(students[i].admissionNumber == adm) {

            printf("\nStudent Found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Admission Number: %s\n", students[i].admissionNumber);
            printf("Age: %d\n", students[i].age);
            printf("Average: %.2f\n", students[i].average);
            printf("Grade: %c\n", students[i].grade);

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Student not found.\n");
    }
}

// Update student
void updateStudent() {
    char adm[20];
    int found = 0;

    printf("Enter admission number to update: ");
    scanf("%s", &adm);

    for(int i = 0; i < count; i++) {

        if(students[i].admissionNumber == adm) {

            printf("Enter new marks:\n");

            for(int j = 0; j < 3; j++) {
                printf("Subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);
            }

            calculateAverageAndGrade(&students[i]);

            printf("Student updated successfully!\n");

            // Save updated data
            saveToFile();

            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Student not found.\n");
    }
}

// Best performing student
void bestStudent() {

    if(count == 0) {
        printf("No students available.\n");
        return;
    }

    int best = 0;

    for(int i = 1; i < count; i++) {

        if(students[i].average > students[best].average) {
            best = i;
        }
    }

    printf("\n===== BEST PERFORMING STUDENT =====\n");
    printf("Name: %s\n", students[best].name);
    printf("Admission Number: %s\n", students[best].admissionNumber);
    printf("Average: %.2f\n", students[best].average);
    printf("Grade: %c\n", students[best].grade);
}

// Save students to file
void saveToFile() {

    FILE *file = fopen("students.txt", "w");

    if(file == NULL) {
        printf("Error saving file!\n");
        return;
    }

    for(int i = 0; i < count; i++) {

        fprintf(file, "%s %s %d %.2f %c\n",
            students[i].name,
            students[i].admissionNumber,
            students[i].age,
            students[i].average,
            students[i].grade);
    }

    fclose(file);
}

// Load students from file
void loadFromFile() {

    FILE *file = fopen("students.txt", "r");

    if(file == NULL) {
        return;
    }

    count = 0;

    while(fscanf(file, "%s %s %d %f %c",
        students[count].name,
        &students[count].admissionNumber,
        &students[count].age,
        &students[count].average,
        &students[count].grade) != EOF) {

        count++;
    }

    fclose(file);
}
