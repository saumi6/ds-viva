//Just keep the methods you are asked to do in the question
//Remove the method definitions and the method calls in the main function
//Make sure to make changes in the main function accordingly
//If possible, re-write the menu driven code in main
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int n;
    struct node *next;
} Node;
typedef struct
{
    Node *start;
} LL;
void initialize(LL *ll)
{
    ll->start = NULL;
}
int deleteE(LL *ll, int x)
{
    Node *prev, *temp;
    prev = temp = ll->start;
    if (temp == NULL)
        return -1;
    else if (temp->n == x)
    {
        ll->start = temp->next;
        free(temp);
        return x;
    }
    else if (temp->next == NULL)
        return -1;
    else
    {
        temp = temp->next;
        while (temp != NULL)
        {
            if (temp->n == x)
                break;
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return -1;
        else
        {
            prev->next = temp->next;
            free(temp);
            return x;
        }
    }
}
void insertB(LL *ll, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->n = x;
    temp->next = ll->start;
    ll->start = temp;
}
void insertR(LL *ll, int x)
{
    Node *trav;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->n = x;
    temp->next = NULL;

    if (ll->start == NULL)
        ll->start = temp;
    else
    {
        trav = ll->start;
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = temp;
    }
}
void insertP(LL *ll, int x, int p)
{
    int i;
    Node *trav = ll->start;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->n = x;
    if (p == 1)
    {
        temp->next = ll->start;
        ll->start = temp;
        return;
    }
    for (i = 2; i <= p - 1; i++)
    {
        trav = trav->next;
        if (trav == NULL)
            break;
    }
    if (trav == NULL)
    {
        printf("Position doesn&#39;t exist");
        return;
    }
    temp->next = trav->next;
    trav->next = temp;
}
void reverse(LL *ll)
{
    Node *prev = NULL;
    Node *trav = ll->start;
    Node *next = NULL;
    while (trav != NULL)
    {
        next = trav->next;
        trav->next = prev;
        prev = trav;
        trav = next;
    }
    ll->start = prev;
}
int count(LL *ll)
{
    Node *temp = ll->start;
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}
void display(LL *ll)
{
    Node *temp = ll->start;
    printf("List contains:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
void concat(LL *l1, LL *l2)
{
    Node *trav;
    if (l2->start == NULL)
        return;
    if (l1->start == NULL)
    {
        l1->start = l2->start;
        return;
    }
    trav = l1->start;
    while (trav->next != NULL)
    {
        trav = trav->next;
    }
    trav->next = l2->start;
}
int main()
{
    int choice, data, ch, posi, lchoice;
    Node *ptr;
    LL list, l1, l2;
    initialize(&list);
    initialize(&l1);
    initialize(&l2);
    do
    {
        lchoice = 0;
        printf("Press 3 tp exit program\nEnter list to work on: ");
        scanf("%d", &lchoice);
        switch (lchoice)
        {
        case 1:
            list = l1;
            break;
        case 2:
            list = l2;
            break;
        case 3:
            break;
        default:
            ("Invalid input");
            break;
        }
        if (lchoice == 3)
            break;
        do
        {

            printf("1.insert\n2.Delete\n3.Display\n4.Count number of nodes\n5.Reverse\n6.Concatenate other list\n7.Exit\nEnter your choice:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("1.Insert at Begninning\n2.Insert at End\n3.Insert at a given position\nEnter your choice:");
                scanf("%d", &ch);
                if (ch < 1 || ch > 3)
                {
                    printf("Invalid choice.");
                    break;
                }
                printf("Enter data to insert:");
                scanf("%d", &data);
                switch (ch)
                {
                case 1:
                    insertB(&list, data);
                    break;
                case 2:
                    insertR(&list, data);
                    break;
                case 3:
                    printf("Enter the position:");
                    scanf("%d", &posi);
                    insertP(&list, data, posi);
                    break;
                default:
                    printf("Invalid choice\n");
                }
                break;
            case 2:
                printf("Enter the element to delete:");
                scanf("%d", &data);
                data = deleteE(&list, data);
                if (data != -1)
                    printf("Deleted: %d\n", data);
                else
                    printf("Element not found\n");
                break;
            case 3:
                display(&list);
                break;
            case 4:
                printf("Number of nodes=%d\n", count(&list));
                break;
            case 5:
                reverse(&list);
                if (lchoice == 1)
                    reverse(&l1);
                else
                    reverse(&l2);
                break;
            case 6:
                if (lchoice == 1)
                    concat(&l1, &l2);
                else
                    concat(&l2, &l1);
                break;
            case 7:
                break;
            default:
                printf("Invalid choice\n");
            }
        } while (choice != 7);
    } while (lchoice != 3);
}