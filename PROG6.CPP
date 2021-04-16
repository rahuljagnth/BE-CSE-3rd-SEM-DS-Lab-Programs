#include<stdio.h>
#include<stdlib.h>
#define Q_SIZE 5

void CQinsert();
int CQdelete();
int item,q[Q_SIZE],count,front,rear;

void CQinsert()
{
if(count==Q_SIZE)
{
	printf("\nOverflow!!\n");
	return;
}
rear=(rear+1)%Q_SIZE;
q[rear]=item;
count++;
}

int CQdelete()
{
int item;
if(count==0)
{
	printf("\n\nUnderflow!!!!\n\n");
	return -1;
}
item=q[front];
front=(front+1)%Q_SIZE;
count=-1;
return item;
}

void display()
{
int i,f;
if(count==0)
{
	printf("\nEmpty Queue\n");
	return;
}
for(i=1,f=front;i<=count;i++)
{
	printf("%d\n",q[f]);
	f=(f+1)%Q_SIZE;
}
}

void main()
{
int choice;
front=0;
rear=-1;
count=0;

for(;;)
{
printf("\n ### Circular Queue Operations ### \n\n");
printf("\n 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
printf("\n Enter your choice\n");
scanf("%d",&choice);

switch(choice)
{
	case 1: printf("\nRead the element to be Inserted:");
		scanf("%d",&item);
		CQinsert();
		break;
	case 2: item=CQdelete();
		if(item==-1)
		{
			printf("Queue is empty\n");
			break;
		}
		printf("Deleted Element is %d\n",item);
		break;
	case 3: display();
		break;
	default: exit(0);
}
}}
