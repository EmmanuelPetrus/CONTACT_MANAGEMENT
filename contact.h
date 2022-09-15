#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER 30
typedef struct contact CONTACT;

struct contact
{
    char name[BUFFER];
    long int number;
    char address[BUFFER];
    char email[BUFFER];
};

void addNewContact(CONTACT *a);
void editContact();
void deleteContact(CONTACT *c);
void searchContact();
void listContact(CONTACT *b);
void checkOpen(FILE *fs);

FILE *fp, *ft;