#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int lens(char *s,int L,int R)
{
    int len;
    len=strlen(s);
    while(L>=0&&R<len&&(s[L]==s[R]))
    {
        L--;
        R++;
    }
    return (R-L-1);
}
char* longestPalindrome(char* s) {
    char *ans;
    int len,i,len1,len2,start,end,ii,j,lenmax;
    j=start=end=0;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        len1=lens(s,i,i);//ÆæÊý
        len2=lens(s,i,i+1);//Å¼Êý
        lenmax=(len1>=len2?len1:len2);
        if(lenmax>(end-start))
        {
            start=i-(lenmax-1)/2;
            end=i+lenmax/2;
        }
    }
    for(ii=start;ii<=end;ii++)
    {
        ans[j]=s[ii];
        j++;
    }
    return ans;
}
int main(void)
{
	char s[]="ababababanfgnc";
	int j;
	for(j=0;j<strlen(s);j++)
	{
		printf("%c ",s[j]);
	}
	printf("\n");
	char *t = malloc(sizeof(s) * sizeof(char));
//	printf("%d ",strlen(t));
	int i;
	t=longestPalindrome(s);
	for(i=0;i<strlen(t);i++)
	{
		printf("%c ",t[i]);
	}
	
	return 0;
 } 
