#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct node
{
	int USN,SEM,PHNO;
	char NAME[20],BRANCH[10];
	struct node *link;
};
typedef struct node *NODE;

NODE first=NULL;
int count=0;
int usn,sem,phno;
char name[20],branch[10];

NODE insert_front()
{
NODE temp;
temp=(NODE)malloc(sizeof(struct node));	/*obtain the new node*/
printf("Enter the student details:\n");
printf("USN\t NAME\t BRANCH\t SEM\t PHNO\n"); scanf("%d%s%s%d%d",&usn,name,branch,&sem,&phno);
temp->USN=usn;
strcpy(temp->NAME,name);
strcpy(temp->BRANCH,branch);
temp->SEM=sem;
temp->PHNO=phno;
temp->link=first;
count++;
return temp;
}

void create()
{
int i,n;
printf("Enter number of students\n");
scanf("%d",&n);
for(i=0;i<n;i++)
	first=insert_front();
}

NODE delete_front()
{
NODE temp;
if(first==NULL)	/*check for empty list*/
{
	printf("List is empty cannot delete\n");
	return first;
}
temp=first;
temp=temp->link;
/*return address of the node to be deleted*/
/*obtain address of the second node*/
/*access first node*/
printf("Student usn=%d,name=%s\n",first->USN,first->NAME);
free(first);
count--;
return temp;
}

NODE insert_rear()
{
NODE temp;
NODE cur;
temp=(NODE)malloc(sizeof(struct node));
printf("Enter the student details:\n");
printf("USN\t NAME\t BRANCH\t SEM\t PHNO\n");
 scanf("%d%s%s%d%d",&usn,name,branch,&sem,&phno);
temp->USN=usn;
strcpy(temp->NAME,name);
strcpy(temp->BRANCH,branch);
temp->SEM=sem;
temp->PHNO=phno;
temp->link=NULL;
if(first==NULL)
{
	count++;
	return temp;
}
cur=first;
while(cur->link!=NULL)
{
	cur=cur->link;
	/*insert the node at the end*/
}
cur->link=temp;
count++;
return first;
/*return address of the first node*/
}

NODE delete_rear()
{
NODE temp,cur,prev;
if(first==NULL)	/*check for empty list*/
{
	printf("list is empty cannot delete\n");
	return first;
}
if(first->link==NULL)
{
	printf("%d\t%s\n",temp->USN,temp->NAME);
	count--;
	free(first);
	return NULL;
}
prev=NULL;
cur=first;
while(cur->link!=NULL)
{
	prev=cur;
	cur=cur->link;
}
/*delete the last node */
printf("Student usn=%d,name=%s\n",cur->USN,cur->NAME);
free(cur);
prev->link=NULL;	/*make last but one node at the last node*/
count--;
return first;		/*return address of the last node*/
}

void display()
{
NODE temp;
if(first==NULL)		/*check for the empty list*/
{
	printf("List is Empty\n");
	return;
}
printf("The contents of singly linked list:\n");
temp=first;		/*holds address of the first node*/
while(temp!=NULL)	/*as long as no end of list*/
{
	printf("%d\t %s\t %s\t %d\t %d \n",temp->USN, temp->NAME, temp->BRANCH,temp->SEM,temp->PHNO);
	temp=temp->link;
}
printf("The number of nodes in the Singly Linked List=%d\n",count);
}

void main()
{
int choice;
for(;;)
{
clrscr();
printf("\n1.Create\t2.Display\n");
printf("3.Insert_rear\t4.Delete_rear\n");
printf("5.Demonstration of stack-Insert_front,Delete_front");
printf("\nEnter your choice\n");
scanf("%d",&choice);

switch(choice)
 {
	case 1:	create();
		break;
	case 2:	display();
		break;
	case 3:	first=insert_rear();
		break;
	case 4:	first=delete_rear();
		break;
	case 5:	printf("Push\n");
		insert_front();
		printf("Pop\n");
		delete_front();
		break;
	default:printf("Invalid choice\n");
		exit(0);
 }
getch();
}
}