// Ocean Mallik	            253-35-087
// Hanif shahoria abide 	253-35-459
// Ashikur Rahman Himel 	253-35-046
#include <stdio.h>

typedef struct
{
    int teacherID;
    char name[50];
    char email[50];
    char phone[20];
    char department[30];
    float salary;
} Teacher;

// CRUD operation with text files

// Creation
void capture_teacher(void)
{
    FILE *file = fopen("teachers.txt", "a");

    if (file == NULL)
    {
        printf("There is a problem and cannot open file\n");
        return;
    }

    Teacher t;

    printf("Enter Teacher ID: \n");
    scanf("%d", &t.teacherID);

    printf("Enter Name: \n");
    scanf(" %[^\n]", t.name);

    printf("Enter Email: \n");
    scanf(" %[^\n]", t.email);

    printf("Enter Phone: \n");
    scanf(" %[^\n]", t.phone);

    printf("Enter Department: \n");
    scanf(" %[^\n]", t.department);

    printf("Enter Salary: \n");
    scanf(" %f", &t.salary);

    fprintf(file, "%d\n%s\n%s\n%s\n%s\n%.2f\n", t.teacherID, t.name, t.email, t.phone, t.department, t.salary);
    fclose(file);

    printf("Teacher Added \n");
}

// Read
void all_teachers(void)
{
    FILE *file = fopen("teachers.txt", "r");

    if (file == NULL)
    {
        printf("Error with the file\n");
        return;
    }

    Teacher t;

    printf("List of all Teachers\n");

    while (fscanf(file, "%d %[^\n] %[^\n] %[^\n] %[^\n] %f", &t.teacherID, t.name, t.email, t.phone, t.department, &t.salary) == 6)
    {
        printf("Teacher ID: %d\n", t.teacherID);
        printf("Name: %s\n", t.name);
        printf("Email: %s\n", t.email);
        printf("Phone: %s\n", t.phone);
        printf("Department: %s\n", t.department);
        printf("Salary: %.2f\n", t.salary);

    }

    fclose(file);
}

// Update
void update_teacher(void)
{
    FILE *file = fopen("teachers.txt", "r");
    if (file == NULL)
    {
        printf("No teachers here. \n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    
    int id;
    int found = 0;
    Teacher t;

    printf("Enter Teacher ID to update: \n");
    scanf("%d", &id);

    while (fscanf(file, "%d %[^\n] %[^\n] %[^\n] %[^\n] %f", &t.teacherID, t.name, t.email, t.phone, t.department, &t.salary) == 6)
    {
        if (t.teacherID == id)
        {
            found = 1;

            printf("Enter New Name: \n");
            scanf(" %[^\n]", t.name);

            printf("Enter New Email: \n");
            scanf(" %[^\n]", t.email);

            printf("Enter New Phone: \n");
            scanf(" %[^\n]", t.phone);

            printf("Enter New Department: \n");
            scanf(" %[^\n]", t.department);

            printf("Enter New Salary: \n");
            scanf("%f", &t.salary);
        }

        fprintf(temp, "%d\n%s\n%s\n%s\n%s\n%.2f\n", t.teacherID, t.name, t.email, t.phone, t.department, t.salary);
    }


    fclose(file);
    fclose(temp);

    if (!found)
    {
        remove("temp.txt");
        printf("Not found\n");
        return;
    }

    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");

    printf("Teacher Updated. \n");
}

// Delete
void delete_teacher(void)
{
    FILE *file = fopen("teachers.txt", "r");
    if (file == NULL)
    {
        printf("\nNo Teachers here. \n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");

    int id;
    int found = 0;
    Teacher t;

    printf("\nEnter Teacher ID to delete: ");
    scanf("%d", &id);


    while (fscanf(file, "%d %[^\n] %[^\n] %[^\n] %[^\n] %f", &t.teacherID, t.name, t.email, t.phone, t.department, &t.salary) == 6)
    {
        if (t.teacherID == id)
        {
            found = 1;
            continue; //skips adding data to temp
        }

        fprintf(temp, "%d\n%s\n%s\n%s\n%s\n%.2f\n", t.teacherID, t.name, t.email, t.phone, t.department, t.salary);
    }

    fclose(file);
    fclose(temp);

    if (!found)
    {
        remove("temp.txt");
        printf("Not found\n");
        return;
    }
    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");

    printf("Teacher Deleted \n");
}

int main(void)
{
    int choice = -1;
    while (choice != 0)
    {
        printf("Teacher Menu\n");
        printf("1. Add teacher\n");
        printf("2. Show all teachers\n");
        printf("3. Update teacher by ID\n");
        printf("4. Delete teacher by ID\n");

        printf("Enter Choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            capture_teacher();
            break;
        case 2:
            all_teachers();
            break;
        case 3:
            update_teacher();
            break;
        case 4:
            delete_teacher();
            break;
        default:
            break;
        }
    }

    return 0;
}
