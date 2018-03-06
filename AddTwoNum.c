#include <stdio.h>
#include <stdlib.h>
//����ջ�����ʺ����ȳ� 
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
//��ʼ���յ�ջ 
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
		printf("�ڴ����ʧ�ܣ�\n");
		exit(-1);
	 } 
}
//ѹջ 
void pushStack(PSTACK pStack,int val)
{
	PNODE pNew=(PNODE)malloc(sizeof(node));
	pNew->data=val;
	
	pNew->next=pStack->pTop;
	pStack->pTop=pNew;
 } 
 //��ջ
int popStack(PSTACK pStack) 
{
	int val;
	PNODE rNode=pStack->pTop;
	val=rNode->data;
	pStack->pTop=rNode->next;
	free(rNode);
	return val; 
}
//��ջ��ӡ
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
//����������a�ĳ��ȷ��أ�����a�Ĳ�����ִ�������b 
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
	printf("\n������һ�����֣�\n");
	scanf("%d",&val1);
	len1=getLen(val1,a);
	for(i=0;i<len1;i++)
	{
		pushStack(&stack1,a[len1-i-1]);
	}
	printStack(&stack1);
	
	InitStack(&stack2);
	printf("\n������һ�����֣�\n");
	scanf("%d",&val2);
	len2=getLen(val2,b);
	for(i=0;i<len2;i++)
	{
		pushStack(&stack2,b[len2-i-1]);
	}
	printStack(&stack2);
	
	ans=val1+val2;
	InitStack(&stack3);
	printf("\nans is��\n");
	len3=getLen(ans,c);
	for(i=0;i<len3;i++)
	{
		pushStack(&stack3,c[len3-i-1]);
	}
	printStack(&stack3);

	return 0;
}
