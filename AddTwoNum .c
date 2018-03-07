#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;
PNODE creatLink()
{
	PNODE head=(PNODE)malloc(sizeof(NODE));
	head->data=0;
	head->next=NULL;
	return head;
}
void insert(PNODE *head,int i,int val)
{
	PNODE p=*head;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
		PNODE pNew;
		pNew=(PNODE)malloc(sizeof(NODE));
		pNew->data=val;
		pNew->next=NULL;
	
		p->next=pNew;
		p=pNew;

}
void print(PNODE head)
{
	PNODE temp;
	temp=head->next;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(void)
{
	PNODE head1,head2,head3;
	int val1,val2,ans,temp1,temp2;
	int i=1;
	int j=1;
	int k=1;
	head1=creatLink();
	printf("«Î ‰»Îval1=\n");
	scanf("%d",&val1);
	temp1=val1;
	while(val1)
	{
		insert(&head1,i,val1%10);
		val1=val1/10; 
		i++;
	}
	print(head1);
	
	head2=creatLink();
	printf("«Î ‰»Îval2=\n");
	scanf("%d",&val2);
	temp2=val2;
	while(val2)
	{
		insert(&head2,j,val2%10);
		val2=val2/10; 
		j++;
	}
	print(head2);
	
	head3=creatLink();
	ans=temp1+temp2;
	printf("answer is:%d\n",ans);
	while(ans)
	{
		insert(&head1,k,ans%10);
		ans=ans/10; 
		k++;
	}
	print(head1);
	
	return 0;
 } 
