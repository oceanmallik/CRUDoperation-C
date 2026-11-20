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
    scanf(" %[^\n]", s.cgpa);

    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);

    printf("Student Added \n");
}

