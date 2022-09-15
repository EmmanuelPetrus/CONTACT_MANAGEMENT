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
    printf("step\n");
    while (fread(b, sizeof(CONTACT), 1, fp))

    {
        printf("\nName\t: %sPhone\t: %s\nAddress\t: %s\nEmail\t: %s\n", b->name,

               b->number, b->address, b->email);

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

    fflush(stdin);
    char name[] = {0};
    printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

    scanf("%[^\n]", &name);

    fp = fopen("contact.dat", "rb+");
    checkOpen(fp);
    // ft = fopen("temp.dat", "wb");
    ft = tmpfile();
    if (ft == NULL)
    {
        fprintf(stderr, "Could not create temporary FILE");
        exit(1);
    }

    while (fread(c, sizeof(CONTACT), 1, fp))
        if (strcmp(name, c->name))
            fwrite(c, sizeof(CONTACT), 1, ft);

    while (fread(c, sizeof(CONTACT), 1, ft))
        fwrite(c, sizeof(CONTACT), 1, fp);

    fclose(fp);

    fclose(ft);

    // remove("contact.dll");

    // rename("temp.dat", "contact.dll");
}

void editContact()
{
    CONTACT temp;
    system("cls");

    char name[] = {0};
    fp = fopen("contact.dat", "rb+");
    checkOpen(fp);

    // ft = fopen("temp.dat", "w");
    ft = tmpfile();

    if (ft == NULL)
    {
        fprintf(stderr, "Could not create temporary FILE");
        exit(1);
    }

    fflush(stdin);

    printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");

    scanf("%[^\n]", name);

    while (fread(&temp, sizeof(CONTACT), 1, fp) == 1)

    {

        if (strcmp(name, temp.name))

            fwrite(&temp, sizeof(CONTACT), 1, ft);
    }

    fflush(stdin);

    printf("\n\n..::Editing '%s'\n\n", name);

    printf("..::Name(Use identical):");

    scanf("%[^\n]", &temp.name);

    fflush(stdin);

    printf("..::Phone:");

    scanf("%ld", &temp.number);

    fflush(stdin);

    printf("..::address:");

    scanf("%[^\n]", &temp.address);

    fflush(stdin);

    printf("..::email address:");

    gets(temp.email);

    printf("\n");

    fwrite(&temp, sizeof(CONTACT), 1, ft);

    while (fread(&temp, sizeof(CONTACT), 1, ft))
        fwrite(&temp, sizeof(CONTACT), 1, fp);

    fclose(fp);

    fclose(ft);

    // remove("contact.dll");

    // rename("temp.dat", "contact.dll");
}

void searchContact()
{
    int len, found, ch = 1;
    CONTACT search;
    char query[] = {0};
    do
    {

        int found = 0;

        printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");

        fflush(stdin);

        scanf("%[^\n]", query);

        len = strlen(query);

        fp = fopen("contact.dat", "r");

        system("cls");

        printf("\n\n..::Search result for '%s' \n===================================================\n", query);

        while (fread(&search, sizeof(CONTACT), 1, fp) == 1)

        {

            // for (i = 0; i <= l; i++)

            //     name[i] = list.name[i];

            // name[l] = '\0';

            if (strcmp(search.name, query) == 0)

            {

                printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n", search.name, search.number, search.address, search.email);

                found++;

                // if (found % 4 == 0)

                // {

                //     printf("..::Press any key to continue...");

                //     getch();
                // }
            }
        }

        if (!found)

            printf("\n..::No match found!");

        else

            printf("\n..::%d match(s) found!", found);

        fclose(fp);

        printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

        scanf("%d", &ch);

    } while (ch == 1);
}