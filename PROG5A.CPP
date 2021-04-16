#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>

int compute(char symbol,int op1,int op2)
{
switch(symbol)
{
	case '+':return op1+op2;
	case '-':return op1-op2;
	case '*':return op1*op2;
	case '/':return op1/op2;
	case '%':return op1%op2;
	case '^':return pow(op1,op2);
	default :printf("invalid opearator\n");
}
return 0;
}

void main()
{
int stack[30],res,op1,op2;
int top=-1,i;
char symbol,postfix[30];
clrscr();
printf("enter the postfix expression:");
	scanf("%s",postfix);
for(i=0;i<strlen(postfix);i++)
{
	symbol=postfix[i];
	if(symbol>='0' && symbol<='9')      //isdigit function
		stack[++top]=symbol-'0';
	else
	{
		op2=stack[top--];
		op1=stack[top--];
		res=compute(symbol,op1,op2);
		stack[++top]=res;
	}
}
printf("The value of the postfix expression is=%d",stack[top]);
getch();
}