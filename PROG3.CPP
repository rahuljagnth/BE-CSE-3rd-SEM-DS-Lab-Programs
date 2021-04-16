#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACK_SIZE 5

int item,top,s[10];
int flag;
char str[20];
void push();
int pop();
int palindrome(char str[]);
void display();

void main()
{
top=-1;
int choice;

for(;;)
{
printf("\n MENU DRIVEN PROGRAM FOR STACK OPERATIONS\n");
printf("1.PUSH(Insert) an element into the stack\n");
printf("2.POP(Delete) an element from the stack\n");
printf("3.Check for Palindrome\n");
printf("4.Display\n");
printf("5.Exit\n");
printf("-----------------------");
printf("\nEnter your choice:\t");
scanf("%d",&choice);

switch(choice)
{
case 1: printf("Enter the element to be inserted:\t");
	  scanf("%d",&item);
	push();
	break;
case 2: item=pop();
	printf("Deleted item:%d",item);
	break;
case 3: printf("Enter a string:");
	scanf("%s",str);
	flag=palindrome(str);
	if(flag==0)
		printf("Not palindrome");
	else
		printf("Palindrome");
	break;
case 4: display();
	break;
default: exit(0);
}
}}

void push()
{
/*Inserting element in to the stack*/
if(top==STACK_SIZE-1)
{
	printf("\nStack Overflow:");
	return;
}
top=top+1;
s[top]=item;
}

int pop()
{
/*deleting an element from the stack*/
int item;
if(top==-1)
{
	printf("Stack Underflow:");
	return 0;
}
item=s[top--];
top=top-1;
return item;
}

void display()
{
int i;
if(top==-1)
{
	printf("\nStack is Empty:");
	return;
}
printf("\nThe stack elements are:\n" );
for(i=0;i<=top;i++)
	printf("%d\n",s[i]);
}

int palindrome(char str[])
{
int i,top;
char s[10],item;

top=-1;
for(i=0;i<strlen(str);i++)
	s[++top]=str[i];
for(i=0;i<strlen(str);i++)
{
	item=s[top--];
	if(str[i]!=item) return 0;
}
return 1;
}