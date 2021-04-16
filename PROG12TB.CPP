#include<stdio.h>
#include<stdlib.h>
#define HASH_SIZE 5
void initialize_ht(int a[])
{
int i;
for(i=0;i<HASH_SIZE;i++)
	a[i]=0;
}

int H(int k)
{
return k%HASH_SIZE;
}

void insert_ht(int item,int a[])
{
int i,index,h_value;
h_value=H(item);
for(i=0;i<HASH_SIZE;i++)
{
	index=(h_value+i)%HASH_SIZE;
	if(a[index]==0) break;
}
if(a[index]==0)
	a[index]=item;
else
	printf("Hash table is full\n");
}

void display(int a[],int n)
{
int i;
for(i=0;i<n;i++)
	printf("%d",a[i]);
}
void main()
{
int a[10],item,choice,n;
initialize_ht(a);
for(;;)
{
	printf("1.Insert 2.Display 3.Exit");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("Enter item:");
			scanf("%d",&item);
			insert_ht(item,a);
			break;
		case 2:printf("Contents of hash table:\n");
			display(a,n);
			printf("\n");
			break;
		default:exit(0);
	}
}
}