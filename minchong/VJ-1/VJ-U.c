#include<stdio.h>
#include<string.h>
int main()
{
    int i,m,n,h,k,l,ctr=0;
    char s[1000000],ch;
    scanf("%s",s);
    m=strlen(s);
    for(i=0;i<m;i++)
    if(s[i]=='[')
    {
    ctr++;
    break;
    }
    for(h=i+1;h<m;h++)
    if(s[h]==':')
    {
    ctr++;
    break;
    }
    for(n=m-1;n>h+1;n--)
    if(s[n]==']')
    {
    ctr++;
    break;
    }
    for(k=n-1;k>h+1;k--)
    if(s[k]==':')
    {
    ctr++;
    break;
    }
    if(ctr<4)
    printf("-1");
    else
    {
        for(i=h+1;i<k;i++)
        if(s[i]=='|')
        ctr++;
        printf("%d",ctr);
    }
}
