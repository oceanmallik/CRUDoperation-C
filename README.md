# CRUD Operations in C

## Team Information

| Name | Student ID |
| :--- | :--- |
| **Ocean Mallik** | 253-35-087 |
| **Hanif Shahoria Abide** | 253-35-459 |
| **Ashikur Rahman Himel** | 253-35-046 |

---

## Project Overview

This project implements a complete **CRUD (Create, Read, Update, Delete)** management system in C, showcasing two different approaches to file persistence:

1. **Student Record System (`Student.c`)** – Implements CRUD operations using **binary file handling** (`students.dat`) with `fwrite()` and `fread()`.
2. **Teacher Record System (`Teacher.c`)** – Implements CRUD operations using **plain text file handling** (`teachers.txt`) with `fprintf()` and `fscanf()`.

---

## Features

Both modules provide an interactive console menu with the following features:
- **Create**: Add a new record (ID, Name, Email, Phone, Department, and CGPA/Salary).
- **Read**: Display all stored records.
- **Update**: Search for a record by its unique ID and update its details.
- **Delete**: Remove a record by its unique ID using a temporary file swapping mechanism.

---

## Data Models

### Student Model (`Student.c`)
- `int studentID`
- `char name[50]`
- `char email[50]`
- `char phone[20]`
- `char department[30]`
- `float cgpa`

*Stored in binary format (`students.dat`).*

### Teacher Model (`Teacher.c`)
- `int teacherID`
- `char name[50]`
- `char email[50]`
- `char phone[20]`
- `char department[30]`
- `float salary`

*Stored in formatted text format (`teachers.txt`).*

---

## How to Compile and Run

GCC Compiler can be used to compile this project.

### 1. Student Management (Binary File)
```bash
# Compile
gcc Student.c -o Student

# Run
./Student
```

### 2. Teacher Management (Text File)
```bash
# Compile
gcc Teacher.c -o Teacher

# Run
./Teacher
```

---

## Project Structure

```text
├── Student.c     # Student CRUD operations using binary files
├── Teacher.c     # Teacher CRUD operations using text files
├── students.dat  # Binary data file for student records
├── teachers.txt  # Text data file for teacher records
├── README.md     # Project documentation
└── .gitignore    # Git ignore rules
```
