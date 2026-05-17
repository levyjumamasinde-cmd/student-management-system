# Student Management System

## Overview
This is a menu-driven Student Management System developed using the C programming language.
The system is designed to manage student records efficiently by allowing the user to add, display, search, update, and determine the best performing student.

The project demonstrates the use of structures, arrays, functions, pointers, and modular programming in C.

---

## Student Information

Full Name: Levy Masinde
Admission Number: YOUR ADMISSION NUMBER
Class: Computer Science / Maths and Modelling

---

## Program Features

### 1. Add Student
Allows the user to input student details such as name, admission number, age, and marks for three subjects.
The program automatically calculates the average and assigns a grade.

### 2. Display All Students
Displays all stored student records in a clean and readable format.

### 3. Search Student
Searches for a student using their admission number and displays their details if found.

### 4. Update Student
Allows updating student marks and automatically recalculates the average and grade.

### 5. Best Performing Student
Finds and displays the student with the highest average marks.

---

## Structures Used

The program uses a structure called `Student` to store all student information in one unit.
This includes:
- Name
- Admission Number
- Age
- Marks for 3 subjects
- Average Marks
- Grade

This helps to organize related data efficiently.

---

## Functions Used

- `addStudent()` → Adds a new student record
- `displayStudents()` → Displays all student records
- `searchStudent()` → Searches for a student by admission number
- `updateStudent()` → Updates marks and recalculates average and grade
- `bestStudent()` → Finds the highest performing student
- `calculateGrade()` → Assigns grade based on average marks
- `calculateAverageAndGrade()` → Calculates average and grade using pointer

---

## Challenges Faced

While working on this project, I faced a few challenges. At first, I had problems committing my project to GitHub because I received some errors and was not sure how to fix them. It took me some time to understand how Git and GitHub work together.

I also had some errors in my C program, especially in calculating the average marks and assigning grades correctly. I had to debug my code carefully to find and fix the mistakes.

Another challenge was saving my project in the wrong folder, which made me confused about which files were being tracked by Git. I later corrected this by organizing my files properly in one project folder.

Overall, these challenges helped me understand the importance of careful coding, debugging, and proper file management.

## Pointer Usage

A pointer was used in this function:

```c
void calculateAverageAndGrade(struct Student *s)
