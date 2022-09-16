#include "contact.h"

void checkOpen(FILE *fs)
{
    if (fs == NULL)
    {
        fprintf(stderr, "Could not create temporary FILE");
        exit(1);
    }
}

void addNewContact(CONTACT *details)
{
    char m = 'Y';
    fp = fopen("contact.dat", "ab");
    checkOpen(fp);
    while (toupper(m) == 'Y')
    {
        fflush(stdin);

        printf("\nName (Use identical):");
        fgets(details->name, BUFFER, stdin);

        printf("Phone:");
        scanf("%ld", &details->number);
        fgetc(stdin);

        printf("Address:");
        fgets(details->address, BUFFER, stdin);

        printf("Email Address:");
        fgets(details->email, BUFFER, stdin);

        printf("\n");

        fwrite(details, sizeof(CONTACT), 1, fp);
        printf("Do you still want to add more contacts? [Y] or [N]\n");
        printf("Input your choice here: ");
        scanf("%c", &m);
        fflush(stdin);
    }
    fclose(fp);
}

void listContact(CONTACT *b)
{
    printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=================================================================\n\n");

    fp = fopen("contact.dat", "rb");
    checkOpen(fp);
    fflush(stdin);

    int found = 0;

    while (fread(b, sizeof(CONTACT), 1, fp))
    {
        printf("\nName\t: %sPhone\t: %ld\nAddress\t: %sEmail\t: %s\n", b->name, b->number, b->address, b->email);
        found++;
    }

    if (found)

    {
        printf("[Total Contact] = %d", found);
    }

    fclose(fp);
}

void deleteContact(CONTACT *c)

{
    system("cls");
    CONTACT temp;
    memset(&temp, 0, sizeof(CONTACT));
    fflush(stdin);

    char name[BUFFER] = {0};
    int ans = 0;
    printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

    fgets(name, BUFFER, stdin);

    fp = fopen("contact.dat", "rb");
    ft = fopen("temp.dat", "wb");

    checkOpen(fp);
    checkOpen(ft);

    while (fread(&temp, sizeof(CONTACT), 1, fp))

    {
        if (!strcmp(name, temp.name))
        {
            printf("Are you sure you want to delete this contact ?\nName\t: %sPhone\t: %ld\nAddress\t: %sEmail\t: %s\nYES[1]   NO[0]:", temp.name, temp.number, temp.address, temp.email);
            scanf("%d", &ans);
            while (ans)
            {
                break;
            }
        }
        else
            fwrite(&temp, sizeof(CONTACT), 1, ft);
    }

    fflush(stdin);

    if (ans)
    {
        printf("\n\n..::Deleted.............\n");
    }
    else
        printf("\nName doesn't exist in contact list!!!");

    fclose(fp);
    fclose(ft);

    remove("contact.dat");
    rename("temp.dat", "contact.dat");
}

void editContact()
{
    CONTACT temp;
    int ans = 0;
    memset(&temp, 0, sizeof(CONTACT));
    system("cls");

    char name[BUFFER] = {0};
    fp = fopen("contact.dat", "rb");
    ft = fopen("temp.dat", "wb");
    checkOpen(fp);
    checkOpen(ft);

    fflush(stdin);

    printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");

    fgets(name, BUFFER, stdin);

    while (fread(&temp, sizeof(CONTACT), 1, fp))

    {
        if (!strcmp(name, temp.name))
        {
            printf("Are you sure you want to edit this name ? -> %s\n YES[1]   NO[0]:", temp.name);
            scanf("%d", &ans);
            while (ans)
            {
                printf("\n\n..::Editing %s\n", name);

                fflush(stdin);
                printf("..::Name(Use identical):");
                fgets(temp.name, BUFFER, stdin);

                fflush(stdin);

                printf("..::Phone:");

                scanf("%ld", &temp.number);

                fflush(stdin);

                printf("..::address:");

                fgets(temp.address, BUFFER, stdin);

                fflush(stdin);

                printf("..::email address:");

                fgets(temp.email, BUFFER, stdin);

                printf("\n");
                fwrite(&temp, sizeof(CONTACT), 1, ft);
                break;
            }
        }
        else
            fwrite(&temp, sizeof(CONTACT), 1, ft);
    }

    fflush(stdin);

    if (ans)
    {
        printf("\nSuccessfully Edited\n");
    }

    fclose(fp);
    fclose(ft);

    remove("contact.dat");
    rename("temp.dat", "contact.dat");
}

void searchContact()
{
    int len, found, ch = 1;
    CONTACT search;
    char query[BUFFER];
    do
    {

        int found = 0;

        printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");

        fflush(stdin);

        fgets(query, BUFFER, stdin);

        len = strlen(query);

        fp = fopen("contact.dat", "r");

        system("cls");

        printf("\n\n..::Search result for '%s' \n===================================================\n", query);

        while (fread(&search, sizeof(CONTACT), 1, fp) == 1)

        {
            if (strcmp(search.name, query) == 0)

            {
                printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n", search.name, search.number, search.address, search.email);
                found++;
            }
        }

        if (!found)
        {
            printf("\n..::No match found!");
            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
        }
        else
            printf("\n..::%d match(s) found!", found);
        fclose(fp);

        scanf("%d", &ch);

    } while (ch == 1);
}