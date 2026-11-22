// Ocean Mallik	            253-35-087
// Hanif shahoria abide 	253-35-459
// Ashikur Rahman Himel 	253-35-046
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
    scanf(" %f", &s.cgpa);

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

// Update
void update_student(void)
{
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL)
    {
        printf("No students here. \n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    
    int id;
    int found = 0;
    Student s;

    printf("Enter Students ID to update: \n");
    scanf("%d", &id);

    while (fread(&s, sizeof(Student), 1, file) == 1)
    {
        if (s.studentID == id)
        {
            found = 1;

            printf("Enter New Name: \n");
            scanf(" %[^\n]", s.name);

            printf("Enter New Email: \n");
            scanf(" %[^\n]", s.email);

            printf("Enter New Phone: \n");
            scanf(" %[^\n]", s.phone);

            printf("Enter New Department: \n");
            scanf(" %[^\n]", s.department);

            printf("Enter New CGPA: \n");
            scanf("%f", &s.cgpa);
        }

        fwrite(&s, sizeof(Student), 1, temp);
    }


    fclose(file);
    fclose(temp);

    if (!found)
    {
        remove("temp.dat");
        printf("Not found\n");
        return;
    }

    remove("students.dat");
    rename("temp.dat", "students.dat");

    printf("Student Updated. \n");
}

// Delete
void delete_student(void)
{
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL)
    {
        printf("\nNo Students here. \n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");

    int id;
    int found = 0;
    Student s;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);


    while (fread(&s, sizeof(Student), 1, file) == 1)
    {
        if (s.studentID == id)
        {
            found = 1;
            continue; //skips adding data to temp
        }

        fwrite(&s, sizeof(Student), 1, temp);
    }

    fclose(file);
    fclose(temp);

    if (!found)
    {
        remove("temp.dat");
        printf("Not found\n");
        return;
    }
    remove("students.dat");
    rename("temp.dat", "students.dat");

    printf("Student Deleted \n");
}

int main(void)
{
    int choice = -1;
    while (choice != 0)
    {
        printf("Student Menu\n");
        printf("1. Add student\n");
        printf("2. Show all students\n");
        printf("3. Update student by ID\n");
        printf("4. Delete student by ID\n");

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
        case 3:
            update_student();
            break;
        case 4:
            delete_student();
            break;
        default:
            break;
        }
    }

    return 0;
}

