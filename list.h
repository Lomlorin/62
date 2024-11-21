#ifndef LIST_H
#define LIST_H

#define MAX_NAME_LENGTH 50
#define MAX_WORK_LENGTH 50
#define MAX_POSITION_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_SOCIAL_LENGTH 100

typedef struct Contact {
    char first_name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char work[MAX_WORK_LENGTH];
    char position[MAX_POSITION_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char social[MAX_SOCIAL_LENGTH];
    struct Contact* next;
    struct Contact* prev;
} Contact;

// Прототипы функций
void add_contact();
void edit_contact(char first_name[MAX_NAME_LENGTH], char surname[MAX_NAME_LENGTH]);
void delete_contact(char first_name[MAX_NAME_LENGTH], char surname[MAX_NAME_LENGTH]);
void list_contacts();
void free_all_contacts();

#endif

