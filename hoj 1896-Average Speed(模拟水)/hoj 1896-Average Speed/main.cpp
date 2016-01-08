#include<iostream>
#include<cstring>
#include<cmath>
char s[21];
int main()
{
    double ans,ptm;
    int prt=0,pts=0,sum,tmp,i;
    ptm=0.0;
    while(gets(s))
    {
        sum=0;
        if(s[0]!='2'||s[1]!='4')
        sum+=((s[0]-'0')*10+s[1]-'0')*3600;
        sum+=((s[3]-'0')*10+s[4]-'0')*60;
        sum+=(s[6]-'0')*10+s[7]-'0';
        if(strlen(s)>=10)
        {
            int l=1;
            tmp=0;
            for(i=strlen(s)-1;i>8;i--)
            {
                tmp+=(s[i]-'0')*l;
                l*=10;
            }
            ptm+=double(sum-prt)/3600.0*pts;
            pts=tmp;
            prt=sum;
        }
        else{
            ans=0.0;
            ans=double(sum-prt)/3600.0*pts+ptm;
            printf("%s %.2f km\n",s,ans);
        }
    }
	return 0;
}