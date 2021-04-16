#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int key[20],n,m;
int *ht,hashindex;
int elecount=0;

void create_hashtable()
{
int i,a;
ht=(int*)malloc(m*sizeof(int));
if(ht==NULL)
	printf("\nUnable to create hash table\n");
else
	for(i=0;i<m;i++)
		a=key[i];
		ht[i]=a;
}

void insert_hashtable(int key)
{
hashindex=key%m;
while(ht[hashindex]!=-1)
{
	hashindex=(hashindex+1)%m;
}
ht[hashindex]=key;
elecount++;
}

void display()
{
int i;
if(elecount==0)
{
	printf("\nHash table is empty\n");
	return;
}
printf("Hash table contents are:\n");
for(i=0;i<m;i++)
	printf("T[%d]->%d \n",i,ht[i]);
}
void main()
{
int i;
printf("Enter the no. of employee records(N):");
scanf("%d",&n);
printf("Enter the four digit key value of N employee records\n");
for(i=0;i<n;i++)
	scanf("%d",key[i]);
printf("Enter the two digit memory location m for hash table:");
scanf("%d",&m);
create_hashtable();
printf("\nInserting key values of employee records into hash table:\n");
for(i=0;i<n;i++)
{
if(elecount==m)
{
	printf("\nHash table is full,cannot insert the record key value");
	break;
}
insert_hashtable(key[i]);
}
display();
}
