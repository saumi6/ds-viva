//If you want to show the non recursive method then just change the function call in main and change the parameters
#include<stdio.h>
#include<conio.h>
int Search(int a[100],int n, int x)
{
	int min=0,max=n-1,mid;
	while(min<=max)
	{
		mid=(min+max)/2;
		if(a[mid]==x) return mid;
		if(x>a[mid]) min=mid+1;
		else max=mid-1;
	}
	return -1;
}

int SearchRec(int a[100],int low, int high, int ele)
{
	if(low>high) return -1;
    int mid = (low+high)/2;
    if(a[mid]==ele) return(mid+1);
    else if (ele<a[mid]) return SearchRec(a,low,mid-1,ele);
    else return SearchRec(a,mid+1,high,ele);
}
void main()
{
	int i,n,a[100],search;
	clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	printf("Enter the element to search:");
	scanf("%d",&search);
	i=SearchRec(a,0,n,search);
	if(i==-1) printf("Not found");
	else printf("Found at index: %d",i);
	getch();
}
