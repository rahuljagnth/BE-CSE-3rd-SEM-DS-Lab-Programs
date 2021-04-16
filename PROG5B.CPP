#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
void tower(int n,char source,char temp,char dest);

void main()
{
int n;
printf("Enter the number of discs:");
scanf("%d",&n);
printf("The sequence of moves involved in towers of honai are :\n");
tower(n,'A','B','C');
}

void tower(int n, char source, char temp, char dest)
{
if(n==0)
	return;
tower(n-1,source,dest,temp);
	printf("move disk %d from peg %c to peg %c\n",n,source,dest);
tower(n-1,temp,source,dest);
}