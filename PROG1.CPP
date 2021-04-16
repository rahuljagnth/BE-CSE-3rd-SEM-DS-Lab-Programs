#include<stdlib.h>
#include<stdio.h>

int a[20],b[20],c[40];
int m,n,p,val,i,j,key,pos,temp;

void create();
void display();
void insert();
void delet();

void main()
{
int choice;
for(;;)
{
printf("\n\n******** Menu Driven C Program ********\n");
printf("1.Create\n");
printf("2.Display\n");
printf("3.Insert\n");
printf("4.Delete\n");
printf("5.Exit\n");
printf("-----------------------");
printf("\nEnter your choice:\t");
scanf("%d",&choice);
switch(choice)
{
case 1:create();
	break;
case 2:display();
	break;
case 3:insert();
	break;
case 4:delet();
	break;
default:exit(0);
} } }
void create()
{
printf("\nEnter the size of the array elements:\t");
scanf("%d",&n);
printf("\nEnter the elements for the array:\n");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}
void display()
{
int i;
printf("\nThe array elements are:\n");
for(i=0;i<n;i++)
	printf("a[%d]=%d\t",i,a[i]);
}
void insert()
{
printf("\nEnter the position for the new element:\t");
scanf("%d",&pos);
printf("\nEnter the element to be inserted :\t");
scanf("%d",&val);

for(i=n-1;i>=pos;i--)
	a[i+1]=a[i];

a[pos]=val;
n=n+1;
}
void delet()
{
printf("\nEnter the position of the element to be deleted:\t");
scanf("%d",&pos);

if(pos+1>n)
	printf("Deletion not possible\n");
else
{
	val=a[pos];
	for(i=pos;i<n-1;i++)
		a[i]=a[i+1];
	n=n-1;
	printf("\nThe deleted element is =%d",val);
}
}
