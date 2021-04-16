#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
int cf,px,py,pz;
struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
	printf("Insuffcient memory");
	exit(0);
}
return x;
}

NODE insert_rear(int cf,int px,int py,int pz,NODE head)
{
NODE temp,cur;
temp=getnode();
temp->cf=cf;
temp->px=px;
temp->py=py;
temp->pz=pz;
cur=head->link;
while(cur->link!=head)
{
 cur=cur->link;
}
cur->link=temp;
temp->link=head;
return head;
}

NODE read_poly(NODE head)
{
int i,n;
int cf,px,py,pz;
printf("\nEnter the number of terms in polynomial:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	printf("Enter term:%d\n",i);
	scanf("%d%d%d%d",&cf,&px,&py,&pz);
	head=insert_rear(cf,px,py,pz,head);
}
return head;
}

void display(NODE head)
{
NODE temp;
if(head->link==head)
{
	printf("Polynomial does not exist");
	return;
}
temp=head->link;
while(temp!=head)
{
	if(temp->cf<0)
		printf("%d",temp->cf);
	else
		printf("%d",temp->cf);
	if(temp->px!=0)printf("x^%d",temp->px);
	if(temp->py!=0) printf("y^%d",temp->py);
	if(temp->pz!=0)printf("z^%d",temp->pz);
	printf("\t");
	temp=temp->link;
}
printf("\n");
}

float evaluate(NODE head)
{
int x,y,z;
float sum=0;
NODE p;

printf("Enter the value of x,y,z");
scanf("%d %d %d",&x,&y,&z);
p=head->link;
while(p!=head)
{
	sum+=p->cf*pow(x,p->px)*pow(y,p->py)*pow(z,p->pz);
	p=p->link;
}
return sum;
}

NODE search(NODE p1,NODE h2)
{
int cf1,px1,py1,pz1,cf2,px2,py2,pz2;
NODE p2;
cf1=p1->cf;
px1=p1->px;
py1=p1->py;
pz1=p1->pz;
p2=h2->link;
while(p2!=h2)
{
	cf2=p2->cf;
	px2=p2->px;
	py2=p2->py;
	pz2=p2->pz;
	if(px1==px2 && py1==py2 && pz1==pz2)
		break;
	p2=p2->link;
}
return p2;
}

NODE copy_poly(NODE h2,NODE h3)
{
NODE p2;
int cf2,px2,py2,pz2;
p2=h2->link;
while(p2!=h2)
{
	if(p2->cf!=-999)
	{
	cf2=p2->cf;
	px2=p2->px;
	py2=p2->py;
	pz2=p2->pz;
	h3=insert_rear(cf2,px2,py2,pz2,h3);
}
p2=p2->link;
}
return h3;
}

NODE add_poly(NODE h1,NODE h2,NODE h3)
{
NODE p1,p2;
int cf1,px1,py1,pz1,sum;
p1=h1->link;
while(p1!=h1)
{
	cf1=p1->cf;
	px1=p1->px;
	py1=p1->py;
	pz1=p1->pz;
	p2=search(p1,h2);
	if(p2!=h2)
	{
		sum=cf1+p2->cf;
		h3=insert_rear(sum,px1,py1,pz1,h3);
		p2->cf=-999;
	}
	else
		h3=insert_rear(cf1,px1,py1,pz1,h3);
	p1=p1->link;
}
h3=copy_poly(h2,h3);
return h3;
}
void main()
{
NODE h1,h2,h3;
clrscr();
h1=getnode();
h2=getnode();
h3=getnode();
h1->link=h1;
h2->link=h2;
h3->link=h3;
printf("Enter the first poly:-");
h1=read_poly(h1);
display(h1);
printf("\nEnter the second poly:-");
h2=read_poly(h2);
display(h2);
h3=add_poly(h1,h2,h3);
printf("Sum:Poly 3");
printf("\n");
display(h3);
getch();
}