#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Contact* head = NULL;  // Голова списка
Contact* tail = NULL;  // Хвост списка

// Функция для добавления контакта
void add_contact() {
    Contact* new_contact = (Contact*)malloc(sizeof(Contact));
    if (!new_contact) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter first name: \n");
    scanf("%s", new_contact->first_name);
    printf("Enter surname: \n");
    scanf("%s", new_contact->surname);

    // Остальные поля можно вводить по желанию или оставить пустыми
    printf("Enter last name (leave blank if not needed): \n");
    getchar(); // Очищаем буфер
    fgets(new_contact->last_name, MAX_NAME_LENGTH, stdin);
    new_contact->last_name[strcspn(new_contact->last_name, "\n")] = '\0';

    printf("Enter place of work (leave blank if not needed): \n");
    fgets(new_contact->work, MAX_WORK_LENGTH, stdin);
    new_contact->work[strcspn(new_contact->work, "\n")] = '\0';

    printf("Enter position (leave blank if not needed): \n");
    fgets(new_contact->position, MAX_POSITION_LENGTH, stdin);
    new_contact->position[strcspn(new_contact->position, "\n")] = '\0';

    printf("Enter phone number (leave blank if not needed): \n");
    fgets(new_contact->phone, MAX_PHONE_LENGTH, stdin);
    new_contact->phone[strcspn(new_contact->phone, "\n")] = '\0';

    printf("Enter email address (leave blank if not needed): \n");
    fgets(new_contact->email, MAX_EMAIL_LENGTH, stdin);
    new_contact->email[strcspn(new_contact->email, "\n")] = '\0';

    printf("Enter social network link (leave blank if not needed): \n");
    fgets(new_contact->social, MAX_SOCIAL_LENGTH, stdin);
    new_contact->social[strcspn(new_contact->social, "\n")] = '\0';

    // Вставка в отсортированный список
    if (!head) {
        new_contact->next = NULL;
        new_contact->prev = NULL;
        head = tail = new_contact;
    } else {
        Contact* current = head;
        while (current && strcmp(current->surname, new_contact->surname) < 0) {
            current = current->next;
        }

        if (!current) {
            new_contact->next = NULL;
            new_contact->prev = tail;
            tail->next = new_contact;
            tail = new_contact;
        } else {
            new_contact->prev = current->prev;
            new_contact->next = current;
            if (current->prev) {
                current->prev->next = new_contact;
            } else {
                head = new_contact;
            }
            current->prev = new_contact;
        }
    }

    printf("Contact added.\n");
}

// Функция редактирования контакта
void edit_contact(char first_name[MAX_NAME_LENGTH], char surname[MAX_NAME_LENGTH]) {
    Contact* current = head;
    while (current) {
        if (strcmp(current->first_name, first_name) == 0 && strcmp(current->surname, surname) == 0) {
            printf("Editing contact: %s %s\n", current->first_name, current->surname);

            // Обновляем данные
            printf("Enter new place of work: \n");
            fgets(current->work, MAX_WORK_LENGTH, stdin);
            current->work[strcspn(current->work, "\n")] = '\0';

            printf("Enter new position: \n");
            fgets(current->position, MAX_POSITION_LENGTH, stdin);
            current->position[strcspn(current->position, "\n")] = '\0';

            printf("Enter new phone number: \n");
            fgets(current->phone, MAX_PHONE_LENGTH, stdin);
            current->phone[strcspn(current->phone, "\n")] = '\0';

            printf("Enter new email address: \n");
            fgets(current->email, MAX_EMAIL_LENGTH, stdin);
            current->email[strcspn(current->email, "\n")] = '\0';

            printf("Enter new social network link: \n");
            fgets(current->social, MAX_SOCIAL_LENGTH, stdin);
            current->social[strcspn(current->social, "\n")] = '\0';

            printf("The contact has been updated.\n");
            return;
        }
        current = current->next;
    }

    printf("The contact was not found.\n");
}

// Функция удаления контакта
void delete_contact(char first_name[MAX_NAME_LENGTH], char surname[MAX_NAME_LENGTH]) {
    Contact* current = head;
    while (current) {
        if (strcmp(current->first_name, first_name) == 0 && strcmp(current->surname, surname) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            free(current);
            printf("The contact has been deleted.\n");
            return;
        }
        current = current->next;
    }

    printf("The contact was not found.\n");
}

// Функция отображения всех контактов
void list_contacts() {
    if (!head) {
        printf("The phone book is empty.\n");
        return;
    }

    Contact* current = head;
    while (current) {
        printf("Name: %s %s\n", current->first_name, current->surname);
        printf("Last name: %s\n", current->last_name);
        printf("Place of work: %s\n", current->work);
        printf("Position: %s\n", current->position);
        printf("Phone: %s\n", current->phone);
        printf("Email: %s\n", current->email);
        printf("Social network: %s\n", current->social);
        printf("\n");
        current = current->next;
    }
}

// Функция очистки памяти
void free_all_contacts() {
    Contact* current = head;
    while (current) {
        Contact* temp = current;
        current = current->next;
        free(temp);
    }
}
