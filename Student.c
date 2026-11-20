#include <stdio.h>

typedef struct
{
    int studentID;
    char name[50];
    char email[50];
    char phone[20];
    char department[30];
    float cgpa;
} Student;

// CRUD operation with binary files

// Creation
void capture_student(void)
{
    FILE *file = fopen("students.dat", "ab");

    if (file == NULL)
    {
        printf("There is a problem and cannot open file\n");
        return;
    }

    Student s;

    printf("Enter Student ID: \n");
    scanf("%d", &s.studentID);

    printf("Enter Name: \n");
    scanf(" %[^\n]", s.name);

    printf("Enter Email: \n");
    scanf(" %[^\n]", s.email);

    printf("Enter Phone: \n");
    scanf(" %[^\n]", s.phone);

    printf("Enter Department: \n");
    scanf(" %[^\n]", s.department);

    printf("Enter CGPA: \n");
    scanf(" %f", s.cgpa);

    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);

    printf("Student Added \n");
}

// Read
void all_students(void)
{
    FILE *file = fopen("students.dat", "rb");

    if (file == NULL)
    {
        printf("Error with the file\n");
        return;
    }

    Student s;

    printf("List of all Students\n");

    while (fread(&s, sizeof(Student), 1, file) == 1)
    {
        printf("Student ID: %d\n", s.studentID);
        printf("Name: %s\n", s.name);
        printf("Email: %s\n", s.email);
        printf("Phone: %s\n", s.phone);
        printf("Department: %s\n", s.department);
        printf("CGPA: %.2f\n", s.cgpa);

    }

    fclose(file);
}

int main(void)
{
    int choice = -1;
    while (choice != 0)
    {
        printf("Student Menu\n");
        printf("1. Add student\n");
        printf("2. Show all students\n");

        printf("Enter Choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            capture_student();
            break;
        case 2:
            all_students();
            break;
        default:
            break;
        }
    }

    return 0;
}

