#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char txt[20000000];
long long hash[1000000];
const int prime=999983;
double gold=0.618033;
int n,nc;
int flag;
long long sum=0;
int num;
void insert(int p)
{
    if(hash[p]==0)
    {
        hash[p]=sum;
        flag=1;
    }
    else
    {
        if(hash[p]==sum)
            flag=0;
        else
            insert(p%prime+1);
    }
}
int main()
{
    scanf("%d%d",&n,&nc);
    getchar();
    gets(txt);
    int len=strlen(txt);
    memset(hash,0,sizeof(hash));
    for(int i=0;i<=len-n;i++)
    {
        sum=0;
        for(int j=i;j<i+n;j++)
        {
            sum*=26;
            sum+=txt[j]-97;
        }
        int k=int (prime*(sum*gold-floor(sum*gold)));   
        insert(k);
        if(flag)
            num++;
    }
    printf("%d\n",num);
    scanf("\n");
    return 0;
}


