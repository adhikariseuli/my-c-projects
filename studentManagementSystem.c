#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH_LENGTH 100

// Structure to represent a payment
struct Payment {
    float amount;
    char date[12];  // Assuming date format MM/DD/YYYY
    struct Payment* next;
};

// Structure to represent a student
struct Student {
    char name[50];
    int rollNumber;
    char phoneNumber[15];
    char email[50];
    char dob[12];  // Assuming date of birth format MM/DD/YYYY
    float monthlyFee;
    char picturePath[100];  // Assuming a maximum file path length
    char aadharCardPicturePath[100];  // Assuming a maximum file path length for Aadhar card picture
    struct Payment* payments;
    struct Student* next;
};

// Function prototypes
struct Student* addStudent(struct Student* head);
struct Student* addPayment(struct Student* head, int rollNumber);
void displayPayments(struct Student* head, int rollNumber);
void displayStudents(struct Student* head);
void printData(struct Student* head);
void downloadData(struct Student* head);
void downloadAllStudents(struct Student* head, const char* fileName);
void downloadPayments(struct Student* head, int rollNumber, const char* fileName);
void saveToFile(struct Student* head, const char* fileName);
struct Student* loadFromFile(const char* fileName);
struct Student* deleteStudent(struct Student* head, int rollNumber);
struct Student* editStudent(struct Student* head, int rollNumber);
void freeMemory(struct Student* head);

int main() {
    const char* fileName = "students.txt";
    struct Student* head = loadFromFile(fileName);
    int choice;

    do {
        printf("\nSchool Management System\n");
        printf("1. Add Student\n");
        printf("2. Add Payment\n");
        printf("3. Display Students\n");
        printf("4. Display Payments\n");
        printf("5. Print Data\n");
        printf("6. Download Data\n");
        printf("7. Save Data to File\n");
        printf("8. Delete Student\n");
        printf("9. Edit Student Information\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addStudent(head);
                break;
            case 2:
                printf("Enter the roll number of the student to add payment: ");
                int rollNumber;
                scanf("%d", &rollNumber);
                head = addPayment(head, rollNumber);
                break;
            case 3:
                displayStudents(head);
                break;
            case 4:
                printf("Enter the roll number of the student to display payments: ");
                scanf("%d", &rollNumber);
                displayPayments(head, rollNumber);
                break;
            case 5:
                printData(head);
                break;
            case 6:
                downloadData(head);
                break;
            case 7:
                saveToFile(head, fileName);
                printf("Data saved to file.\n");
                break;
            case 8:
                printf("Enter the roll number of the student to delete: ");
                scanf("%d", &rollNumber);
                head = deleteStudent(head, rollNumber);
                break;
            case 9:
                printf("Enter the roll number of the student to edit: ");
                scanf("%d", &rollNumber);
                head = editStudent(head, rollNumber);
                break;
            case 10:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 10);

    // Free allocated memory before exiting
    freeMemory(head);

    return 0;
}

// Function to add a new student
struct Student* addStudent(struct Student* head) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter student details:\n");
    printf("Name: ");
    scanf("%s", newStudent->name);
    printf("Roll Number: ");
    scanf("%d", &newStudent->rollNumber);
    printf("Phone Number: ");
    scanf("%s", newStudent->phoneNumber);
    printf("Email: ");
    scanf("%s", newStudent->email);
    printf("Date of Birth (MM/DD/YYYY): ");
    scanf("%s", newStudent->dob);
    printf("Monthly Fee: ");
    scanf("%f", &newStudent->monthlyFee);
    printf("Picture Path: ");
    scanf("%s", newStudent->picturePath);
    printf("Aadhar Card Picture Path: ");
    scanf("%s", newStudent->aadharCardPicturePath);

    newStudent->payments = NULL;
    newStudent->next = head;

    return newStudent;
}

// Function to add a payment for a student
struct Student* addPayment(struct Student* head, int rollNumber) {
    struct Student* current = head;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            struct Payment* newPayment = (struct Payment*)malloc(sizeof(struct Payment));
            if (newPayment == NULL) {
                printf("Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }

            printf("Enter payment details:\n");
            printf("Amount: ");
            scanf("%f", &newPayment->amount);
            printf("Date (MM/DD/YYYY): ");
            scanf("%s", newPayment->date);

            newPayment->next = current->payments;
            current->payments = newPayment;

            printf("Payment added successfully.\n");
            return head;
        }
        current = current->next;
    }

    printf("Student not found!\n");
    return head;
}

// Function to display all payments for a student
void displayPayments(struct Student* head, int rollNumber) {
    struct Student* current = head;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            printf("Payments for %s (Roll Number: %d):\n", current->name, current->rollNumber);

            struct Payment* payment = current->payments;
            while (payment != NULL) {
                printf("Payment Amount: %.2f, Date: %s\n", payment->amount, payment->date);
                payment = payment->next;
            }

            return;
        }
        current = current->next;
    }

    printf("Student not found!\n");
}

// Function to display all students
void displayStudents(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Roll Number: %d\n", current->rollNumber);
        printf("Phone Number: %s\n", current->phoneNumber);
        printf("Email: %s\n", current->email);
        printf("Date of Birth: %s\n", current->dob);
        printf("Monthly Fee: %.2f\n", current->monthlyFee);
        printf("Picture Path: %s\n", current->picturePath);
        printf("Aadhar Card Picture Path: %s\n", current->aadharCardPicturePath);

        struct Payment* payment = current->payments;
        while (payment != NULL) {
            printf("Payment Amount: %.2f, Date: %s\n", payment->amount, payment->date);
            payment = payment->next;
        }

        printf("\n");

        current = current->next;
    }
}

// Function to print all student data to the console
void printData(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Roll Number: %d\n", current->rollNumber);
        printf("Phone Number: %s\n", current->phoneNumber);
        printf("Email: %s\n", current->email);
        printf("Date of Birth: %s\n", current->dob);
        printf("Monthly Fee: %.2f\n", current->monthlyFee);
        printf("Picture Path: %s\n", current->picturePath);
        printf("Aadhar Card Picture Path: %s\n", current->aadharCardPicturePath);

        struct Payment* payment = current->payments;
        while (payment != NULL) {
            printf("Payment Amount: %.2f, Date: %s\n", payment->amount, payment->date);
            payment = payment->next;
        }

        printf("\n");

        current = current->next;
    }
}

// Function to handle the download options
void downloadData(struct Student* head) {
    int subChoice;
    printf("\nDownload Options:\n");
    printf("1. Download All Student Data\n");
    printf("2. Download Payments for a Specific Student\n");
    printf("Enter your choice: ");
    scanf("%d", &subChoice);

    switch (subChoice) {
        case 1:
            downloadAllStudents(head, "all_students.txt");
            break;
        case 2: {
            int rollNumber;
            printf("Enter the roll number of the student to download payments: ");
            scanf("%d", &rollNumber);
            downloadPayments(head, rollNumber, "student_payments.txt");
            break;
        }
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

// Function to download all student data as a plain text file
void downloadAllStudents(struct Student* head, const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }

    struct Student* current = head;
    while (current != NULL) {
        fprintf(file, "Name: %s\n", current->name);
        fprintf(file, "Roll Number: %d\n", current->rollNumber);
        fprintf(file, "Phone Number: %s\n", current->phoneNumber);
        fprintf(file, "Email: %s\n", current->email);
        fprintf(file, "Date of Birth: %s\n", current->dob);
        fprintf(file, "Monthly Fee: %.2f\n", current->monthlyFee);
        fprintf(file, "Picture Path: %s\n", current->picturePath);
        fprintf(file, "Aadhar Card Picture Path: %s\n", current->aadharCardPicturePath);

        struct Payment* payment = current->payments;
        while (payment != NULL) {
            fprintf(file, "Payment Amount: %.2f, Date: %s\n", payment->amount, payment->date);
            payment = payment->next;
        }

        fprintf(file, "\n");

        current = current->next;
    }

    fclose(file);
    printf("All student data downloaded as plain text: %s\n", fileName);
}

// Function to download payments for a specific student as a plain text file
void downloadPayments(struct Student* head, int rollNumber, const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }

    struct Student* current = head;
    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            fprintf(file, "Payments for %s (Roll Number: %d):\n", current->name, current->rollNumber);

            struct Payment* payment = current->payments;
            while (payment != NULL) {
                fprintf(file, "Payment Amount: %.2f, Date: %s\n", payment->amount, payment->date);
                payment = payment->next;
            }

            fclose(file);
            printf("Payments for a specific student downloaded as plain text: %s\n", fileName);
            return;
        }

        current = current->next;
    }

    printf("Student not found!\n");
}

// Function to save student data to a file
void saveToFile(struct Student* head, const char* fileName) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }

    struct Student* current = head;
    while (current != NULL) {
        fprintf(file, "%s %d %s %s %s %.2f %s %s\n",
                current->name, current->rollNumber, current->phoneNumber,
                current->email, current->dob, current->monthlyFee, current->picturePath, current->aadharCardPicturePath);

        struct Payment* payment = current->payments;
        while (payment != NULL) {
            fprintf(file, "%.2f %s\n", payment->amount, payment->date);
            payment = payment->next;
        }

        current = current->next;
    }

    fclose(file);
}

// Function to load student data from a file
struct Student* loadFromFile(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        // If the file does not exist, return an empty list
        return NULL;
    }

    struct Student* head = NULL;
    struct Student* tail = NULL;

    while (1) {
        struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
        if (newStudent == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        int result = fscanf(file, "%s %d %s %s %s %f %s %s",
                            newStudent->name, &newStudent->rollNumber, newStudent->phoneNumber,
                            newStudent->email, newStudent->dob, &newStudent->monthlyFee,
                            newStudent->picturePath, newStudent->aadharCardPicturePath);

        if (result != 8) {
            free(newStudent);
            break; // End of file or format error
        }

        newStudent->payments = NULL;
        newStudent->next = NULL;

        if (head == NULL) {
            head = newStudent;
            tail = newStudent;
        } else {
            tail->next             = newStudent;
            tail = newStudent;
        }
    }

    fclose(file);
    return head;
}

// Function to free memory allocated for students and payments
void freeMemory(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        struct Payment* payment = current->payments;
        while (payment != NULL) {
            struct Payment* tempPayment = payment;
            payment = payment->next;
            free(tempPayment);
        }

        struct Student* tempStudent = current;
        current = current->next;
        free(tempStudent);
    }
}

// Function to delete a student by roll number
struct Student* deleteStudent(struct Student* head, int rollNumber) {
    struct Student* current = head;
    struct Student* prev = NULL;

    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            if (prev == NULL) {
                // If the student to be deleted is the head
                head = current->next;
            } else {
                // If the student to be deleted is not the head
                prev->next = current->next;
            }

            // Free memory for payments
            struct Payment* payment = current->payments;
            while (payment != NULL) {
                struct Payment* temp = payment;
                payment = payment->next;
                free(temp);
            }

            // Free memory for the student
            free(current);

            printf("Student with Roll Number %d deleted successfully.\n", rollNumber);
            return head;
        }

        // Move to the next student
        prev = current;
        current = current->next;
    }

    // If the student with the given roll number is not found
    printf("Student with Roll Number %d not found.\n", rollNumber);
    return head;
}

// Function to edit student information by roll number
struct Student* editStudent(struct Student* head, int rollNumber) {
    struct Student* current = head;

    while (current != NULL) {
        if (current->rollNumber == rollNumber) {
            printf("Enter new information for student (Roll Number: %d):\n", rollNumber);
            printf("Name: ");
            scanf("%s", current->name);
            printf("Phone Number: ");
            scanf("%s", current->phoneNumber);
            printf("Email: ");
            scanf("%s", current->email);
            printf("Date of Birth (MM/DD/YYYY): ");
            scanf("%s", current->dob);
            printf("Monthly Fee: ");
            scanf("%f", &current->monthlyFee);
            printf("Picture Path: ");
            scanf("%s", current->picturePath);
            printf("Aadhar Card Picture Path: ");
            scanf("%s", current->aadharCardPicturePath);

            printf("Student information updated successfully.\n");
            return head;
        }
        current = current->next;
    }

    printf("Student with Roll Number %d not found.\n", rollNumber);
    return head;
}

