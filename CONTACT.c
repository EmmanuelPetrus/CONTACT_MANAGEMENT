#include "contact.h"

int main()

{

    int ch;
    CONTACT con;
    memset(&con, 0, sizeof(CONTACT));
    CONTACT *pCon = &con;

main:
    system("cls"); /* ************Main menu ***********************  */

    printf("\n\t **** Welcome to Contact Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d", &ch);

    switch (ch)

    {
    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* *********************Add new contacts************  */

    case 1:

        system("cls");
        addNewContact(pCon);
        break;

        /* *********************list of contacts*************************  */
    case 2:

        system("cls");
        listContact(pCon);
        break;

        /* *******************search contacts**********************  */

    case 3:

        system("cls");
        searchContact();
        break;

        /* *********************edit contacts************************/

    case 4:
        editContact();
        break;

        /* ********************delete contacts**********************/

    case 5:
        deleteContact(pCon);
        break;

    default:
        printf("Invalid choice");

        break;
    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d", &ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;
    }

    return 0;
}
