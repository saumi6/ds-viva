//To use the recursive method just change the function calls in main and change the parameters accordingly
#include <stdio.h>
#include <conio.h>
int Search(int a[100], int n, int x)
{
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        if (a[i] == x)
            break;
    }
    return i;
}
int SearchRec(int a[], int n, int x)
{
    if (n == 0)
        return -1;
    else if (a[n - 1] == x)
        return n;
    else
        return (SearchRec(a, n - 1, x));
}
void main()
{
int i, n, a[100], search;
clrscr();
printf("Enter the number of elements: ");
scanf("%d", &n);
for (i = 0; i <= n - 1; i++)
{
    printf("Enter a value: ");
    scanf("%d", &a[i]);
}
printf("Enter the element to search: ");
scanf("%d", &search);
i = Search(a, n, search);
if (i == n)
    printf("Not found ");
else
    printf("Found at index: % d", i);
getch();
}