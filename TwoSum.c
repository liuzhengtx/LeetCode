#include <stdio.h>

int main(void)
{
	int a[]={2,7,11,15,16,60};
	int tar;
	int len;
	int i,j;
	len=sizeof(a)/sizeof(int);
	printf("a[]=");
	for(i=0;i<len-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("������Ŀ��ֵ��");
	scanf("%d",&tar) ;
	for(i=0;i<len-1;i++)
		for(j=i+1;j<len;j++)
		{
			if(tar==(a[i]+a[j]))
			{
				printf("���Ϊ��");
				printf("%d %d",i,j);	
			}
		}
	
	return 0;
 } 
