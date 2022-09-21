#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER 30
typedef struct contact CONTACT;
typedef struct bst bArrange;

bArrange *pRoot;

struct bst
{
    CONTACT *data;
    int count;
    bArrange *pLeft;
    bArrange *pRight;
};

struct contact
{
    char name[BUFFER];
    char number[20];
    char address[BUFFER];
    char email[BUFFER];
};

void addNewContact(CONTACT *a);
void editContact();
void deleteContact(CONTACT *c);
void searchContact();
void listContact(CONTACT *b);
void checkOpen(FILE *fs);
bArrange *addNewNode(CONTACT *k, bArrange *m);
bArrange *createNode(CONTACT *m);
void listNode(bArrange *pNode);
void freenodes(bArrange *pNode);
FILE *fp, *ft;