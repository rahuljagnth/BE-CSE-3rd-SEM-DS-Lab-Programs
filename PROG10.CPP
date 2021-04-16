#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void createtree();
void search();

struct node
{
int info;
struct node *llink,*rlink;
};
typedef struct node *NODE;
NODE troot;

void inorder(NODE troot)	//function for inorder traversal
{
if(troot!=NULL)
{
	inorder(troot->llink);
	printf("%d\t",troot->info);
	inorder(troot->rlink);
}
}

void preorder(NODE troot)
{
if(troot!=NULL)
{
	//function for preorder traversal
	printf("%d\t",troot->info);
	preorder(troot->llink);
	preorder(troot->rlink);
}
}

void postorder(NODE troot)
{
	//function for postorder traversal
	if(troot!=NULL)
	{
	postorder(troot->llink);
	postorder(troot->rlink);
	printf("%d\t",troot->info);
}
}

//function to insert a node to the tree
void insert(int item)
{
NODE temp,cur,prev;
temp=new node;
temp->llink=temp->rlink=NULL;
temp->info=item;
if(troot==NULL)
{
	troot=temp;
	return;
}
else
{
	prev=NULL;
	cur=troot;
	while(cur!=NULL)
	{
		prev=cur;
	if(item<=cur->info)
		cur=cur->llink;
	else
		cur=cur->rlink;
}
if(item<=prev->info)
	prev->llink=temp;
else
	prev->rlink=temp;
}
}

//function to create a tree
void createtree()
{
int i,n,item;
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++)
{
	scanf("%d",&item);
	insert(item);
}
}

//function to search
void search(int item,NODE troot)
{
NODE cur;
int found;
if(troot==NULL) 			//empty tree
	printf("Tree is Empty\n");
cur=troot;
while(cur!=NULL)			//search for the item
{
if(item==cur->info)
{					//If found return the node
	found=1;
}
if(found==1)
	break;
if(item<cur->info)
	cur=cur->llink;
else
	cur=cur->rlink;
}
if(found!=1)
	printf("UnSuccessful search\n");
else
	printf("Successful Search\n");
}

int main()
{
int key,ele;
int ch;
while(1)
{
printf("\n MENU \n1.insert \t 2.inorder \t 3.preorder \t 4.postorder\n5.Search\n");
printf("\n Enter the choice:");
 scanf("%d",&ch);
switch(ch)
{
	case 1: createtree();
		break;
	case 2: inorder(troot);
		break;
	case 3: preorder(troot);
		break;
	case 4: postorder(troot);
		break;
	case 5: printf("Enter the key element to be searched\n");
		scanf("%d",&key);
		search(key,troot);
		break;
	default: exit(0);
}
getch();
}
}