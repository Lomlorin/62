#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    while (1) {
        printf("\nPhone book:\n");
        printf("1. Add a contact\n");
        printf("2. Edit a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Show all contacts\n");
        printf("5. Exit\n");
        printf("Select an action: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2: {
                char first_name[MAX_NAME_LENGTH], surname[MAX_NAME_LENGTH];
                printf("Enter the first name of the contact to edit: \n");
                scanf("%s", first_name);
                printf("Enter the surname of the contact to edit: \n");
                scanf("%s", surname);
                edit_contact(first_name, surname);
                break;
            }
            case 3: {
                char first_name[MAX_NAME_LENGTH], surname[MAX_NAME_LENGTH];
                printf("Enter the first name of the contact to delete: \n");
                scanf("%s", first_name);
                printf("Enter the surname of the contact to delete: \n");
                scanf("%s", surname);
                delete_contact(first_name, surname);
                break;
            }
            case 4:
                list_contacts();
                break;
            case 5:
                // Освобождаем всю память перед выходом
                free_all_contacts();
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Wrong choice. Try again.\n");
        }
    }

    return 0;
}
