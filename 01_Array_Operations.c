/* Menu-driven Array Operations in C
Create, display, insert, and delete elements in an array. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int a[MAX], pos, elem;
int n = 0;

/* Function Prototypes */
void create();
void display();
void insert();
void delete();

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n~~~~MENU~~~~");
        printf("\n=>1. Create an array of N integers");
        printf("\n=>2. Display array elements");
        printf("\n=>3. Insert element at a given position");
        printf("\n=>4. Delete element at a given position");
        printf("\n=>5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nPlease enter a valid choice.\n");
        }
    }
    return 0;
}

/* Create an array */
void create()
{
    int i;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

/* Display array elements */
void display()
{
    int i;
    if (n == 0)
    {
        printf("\nNo elements to display.\n");
        return;
    }

    printf("\nArray elements are: ");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

/* Insert element at a position */
void insert()
{
    int i;

    if (n == MAX)
    {
        printf("\nArray is full. Insertion not possible.\n");
        return;
    }

    do
    {
        printf("\nEnter a valid position to insert element: ");
        scanf("%d", &pos);
    } while (pos > n);

    printf("Enter the value to be inserted: ");
    scanf("%d", &elem);

    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = elem;
    n++;

    display();
}

/* Delete element from a position */
void delete()
{
    int i;

    if (n == 0)
    {
        printf("\nArray is empty. No elements to delete.\n");
        return;
    }

    do
    {
        printf("\nEnter a valid position to delete element: ");
        scanf("%d", &pos);
    } while (pos >= n);

    elem = a[pos];
    printf("\nDeleted element is: %d\n", elem);

    for (i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;

    display();
}

--------MENU-----------
1. CREATE
2. DISPLAY
3. INSERT
4. DELETE
5. EXIT
-----------------------
ENTER YOUR CHOICE: 1
Enter the number of elements: 3
Enter the elements: 10 25 30

ENTER YOUR CHOICE: 2
Array elements are: 10  25  30

ENTER YOUR CHOICE: 3
Enter a valid position where element to be inserted: 1
Enter the value to be inserted: 20
Array elements are: 10  20  25  30

ENTER YOUR CHOICE: 4
Enter a valid position from where element to be deleted: 3
Deleted element is: 30
Array elements are: 10  20  25

ENTER YOUR CHOICE: 5
EXIT
