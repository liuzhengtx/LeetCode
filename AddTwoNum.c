#include <stdio.h>
#include <stdlib.h>
//利用栈的性质后入先出 
typedef struct node
{
	int data ;
	struct node *next;	
}node,*PNODE;
typedef struct stack
{
	PNODE pTop;
	PNODE pBottom;
} STACK,*PSTACK;
//初始化空的栈 
void InitStack(PSTACK pStack)
{
	pStack->pTop=(PNODE)malloc(sizeof(node));
	if(NULL!=pStack->pTop)
	{
		pStack->pBottom=pStack->pTop;
		pStack->pTop->data=0;
		pStack->pTop->next=NULL;
	}
	else
	{
		printf("内存分配失败！\n");
		exit(-1);
	 } 
}
//压栈 
void pushStack(PSTACK pStack,int val)
{
	PNODE pNew=(PNODE)malloc(sizeof(node));
	pNew->data=val;
	
	pNew->next=pStack->pTop;
	pStack->pTop=pNew;
 } 
 //出栈
int popStack(PSTACK pStack) 
{
	int val;
	PNODE rNode=pStack->pTop;
	val=rNode->data;
	pStack->pTop=rNode->next;
	free(rNode);
	return val; 
}
//将栈打印
void printStack(PSTACK pStack)
{
	PNODE pNode=pStack->pTop;
	while(pStack->pBottom!=pNode)
	{
		printf("%d->", pNode->data);
 		pNode = pNode->next;
	}
	printf("\n");
} 
//将输入数字a的长度返回，并将a的拆分数字存入数组b 
int getLen(int a,int b[])
{
	int c,i;
	i=0;

	while(a!=0)
	{
		i++;
		c=a%10;
		a=a/10;	
		b[i-1]=c;
	}	
	return i;
 } 
int main(void)
{
	STACK stack1,stack2,stack3 ;
	int len1,len2,len3,val1,val2,ans,i;
	int a[10],b[10],c[10];

	InitStack(&stack1);
	printf("\n请输入一个数字：\n");
	scanf("%d",&val1);
	len1=getLen(val1,a);
	for(i=0;i<len1;i++)
	{
		pushStack(&stack1,a[len1-i-1]);
	}
	printStack(&stack1);
	
	InitStack(&stack2);
	printf("\n请输入一个数字：\n");
	scanf("%d",&val2);
	len2=getLen(val2,b);
	for(i=0;i<len2;i++)
	{
		pushStack(&stack2,b[len2-i-1]);
	}
	printStack(&stack2);
	
	ans=val1+val2;
	InitStack(&stack3);
	printf("\nans is：\n");
	len3=getLen(ans,c);
	for(i=0;i<len3;i++)
	{
		pushStack(&stack3,c[len3-i-1]);
	}
	printStack(&stack3);

	return 0;
}
