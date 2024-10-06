
// Bank Management Project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define MAX_TRANSACTIONS 100

// Structure to represent a user in the system
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    double balance;
    double transactions[MAX_TRANSACTIONS];
    int transaction_count;
} User;

// Function prototypes
void add_user();
void delete_user();
void withdraw();
void deposit();
void transaction_history();
int validate_user(int id, const char* name, const char* password);
void check_balance();
void display_users();

// File operations
void save_user(User* user);
void update_user(User* user);
User* get_user(int id);
void remove_user(int id);

int main() {
    
    int choice;

    while (1) {
        // Display the main menu
        printf("\nBank Management System\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Withdraw\n");
        printf("4. Deposit\n");
        printf("5. Transaction History\n");
        printf("6. Check Balance\n");
        printf("7. Display All Users\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle menu options
        switch (choice) {
            case 1: add_user(); break;
            case 2: delete_user(); break;
            case 3: withdraw(); break;
            case 4: deposit(); break;
            case 5: transaction_history(); break;
            case 6: check_balance(); break;
            case 7: display_users(); break;
            case 8: exit(0); // Exit the program
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new user
void add_user() {
    User new_user;
    printf("Enter name: ");
    scanf("%s", new_user.name);
    printf("Enter password: ");
    scanf("%s", new_user.password);

    // Generate a unique ID for the user
    srand(time(NULL));
    new_user.id = rand() % 10000 + 1000;

    printf("Enter initial deposit: ");
    scanf("%lf", &new_user.balance);

    // Initialize transaction history with the initial deposit
    new_user.transaction_count = 1;
    new_user.transactions[0] = new_user.balance;

    save_user(&new_user); // Save the new user to the file

    printf("User added successfully. ID: %d\n", new_user.id);
}

// Function to delete an existing user
void delete_user() {
    int id;
    char name[MAX_NAME_LENGTH], password[MAX_PASSWORD_LENGTH];

    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // Validate user credentials before deletion
    if (validate_user(id, name, password)) {
        remove_user(id); // Remove user from file
        printf("User deleted successfully.\n");
    } else {
        printf("Invalid credentials.\n");
    }
}

// Function to withdraw money from a user's account
void withdraw() {
    int id;
    char name[MAX_NAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    double amount;

    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // Retrieve user details from file
    User* user = get_user(id);
    if (user && validate_user(id, name, password)) {
        printf("Enter amount to withdraw: ");
        scanf("%lf", &amount);

        // Check if balance is sufficient
        if (amount > user->balance) {
            printf("Insufficient balance.\n");
        } else {
            user->balance -= amount; // Deduct amount from balance
            user->transactions[user->transaction_count++] = -amount; // Log transaction
            update_user(user); // Update user details in file
            printf("Withdrawal successful. New balance: %.2f\n", user->balance);
        }
    } else {
        printf("Invalid credentials.\n");
    }
    free(user); // Free allocated memory
}

// Function to deposit money into a user's account
void deposit() {
    int id;
    char name[MAX_NAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    double amount;

    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // Retrieve user details from file
    User* user = get_user(id);
    if (user && validate_user(id, name, password)) {
        printf("Enter amount to deposit: ");
        scanf("%lf", &amount);

        user->balance += amount; // Add amount to balance
        user->transactions[user->transaction_count++] = amount; // Log transaction
        update_user(user); // Update user details in file
        printf("Deposit successful. New balance: %.2f\n", user->balance);
    } else {
        printf("Invalid credentials.\n");
    }
    free(user); // Free allocated memory
}

// Function to display transaction history of a user
void transaction_history() {
    int id;
    char name[MAX_NAME_LENGTH], password[MAX_PASSWORD_LENGTH];

    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // Retrieve user details from file
    User* user = get_user(id);
    if (user && validate_user(id, name, password)) {
        printf("Transaction History:\n");
        // Display all recorded transactions
        for (int i = 0; i < user->transaction_count; i++) {
            printf("%d. %.2f\n", i + 1, user->transactions[i]);
        }
    } else {
        printf("Invalid credentials.\n");
    }
    free(user); // Free allocated memory
}

// Function to validate user credentials
int validate_user(int id, const char* name, const char* password) {
    User* user = get_user(id);
    // Check if ID, name, and password match
    if (user && strcmp(user->name, name) == 0 && strcmp(user->password, password) == 0) {
        free(user); // Free allocated memory after validation
        return 1;
    }
    free(user); // Free memory if validation fails
    return 0;
}

// Function to check and display user balance
void check_balance() {
    int id;
    char name[MAX_NAME_LENGTH], password[MAX_PASSWORD_LENGTH];

    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // Retrieve user details from file
    User* user = get_user(id);
    if (user && validate_user(id, name, password)) {
        printf("Current balance: %.2f\n", user->balance);
    } else {
        printf("Invalid credentials.\n");
    }
    free(user); // Free allocated memory
}

// Function to display all users in the system
void display_users() {
    FILE* file = fopen("users.dat", "rb");
    if (!file) {
        printf("No users found.\n");
        return;
    }

    User user;
    // Display all users with their ID, name, and balance
    printf("User List:\n");
    printf("ID\tName\tBalance\n");
    while (fread(&user, sizeof(User), 1, file) == 1) {
        printf("%d\t%s\t%.2f\n", user.id, user.name, user.balance);
    }

    fclose(file); // Close the file after reading
}

// Save a new user to the file
void save_user(User* user) {
    FILE* file = fopen("users.dat", "ab"); // Append mode
    if (file) {
        fwrite(user, sizeof(User), 1, file); // Write user to file
        fclose(file); // Close the file
    }
}

// Update an existing user's information in the file
void update_user(User* user) {
    FILE* file = fopen("users.dat", "r+b"); // Read-write mode
    if (file) {
        User temp;
        while (fread(&temp, sizeof(User), 1, file) == 1) {
            // Find the user by ID and update details
            if (temp.id == user->id) {
                fseek(file, -sizeof(User), SEEK_CUR); // Move back one record
                fwrite(user, sizeof(User), 1, file); // Write updated user info
                break;
            }
        }
        fclose(file); // Close the file
    }
}

// Retrieve a user from the file based on ID
User* get_user(int id) {
    FILE* file = fopen("users.dat", "rb"); // Read mode
    if (file) {
        User* user = malloc(sizeof(User)); // Allocate memory for user
        while (fread(user, sizeof(User), 1, file) == 1) {
            if (user->id == id) { // Find user by ID
                fclose(file); // Close the file and return user
                return user;
            }
        }
        fclose(file); // Close the file if not found
        free(user); // Free allocated memory
    }
    return NULL; // Return NULL if user not found
}

// Remove a user from the file
void remove_user(int id) {
    FILE* file = fopen("users.dat", "rb"); // Read mode
    FILE* temp_file = fopen("temp.dat", "wb"); // Temporary file

    if (file && temp_file) {
        User user;
        while (fread(&user, sizeof(User), 1, file) == 1) {
            // Copy all users except the one to be removed
            if (user.id != id) {
                fwrite(&user, sizeof(User), 1, temp_file);
            }
        }
        fclose(file); // Close original file
        fclose(temp_file); // Close temporary file

        remove("users.dat"); // Delete original file
        rename("temp.dat", "users.dat"); // Rename temp file to original
    }
}
