#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    char start[20][12]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    char stop[20][12]={"ahau","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac"};
    scanf("%d",&n);
    char mg[n][12];
    int day[n],year[n],total;
     for(int i=0;i<n;i++)
     {
        scanf("%d",&day[i]);
        getchar();
        scanf("%s",mg[i]);
        scanf("%d",&year[i]);
     } 
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<20;j++)
         if(strcmp(mg[i],start[j])==0)
            break;
        total=j*20+day[i]+1+year[i]*365;
        day[i]=total%13;
        if(day[i]==0)
          day[i]=13;
        year[i]=total/260;
        int k=total%20;
        if(day[i]==13 && k==0)
            year[i]--;
        printf("%d %s %d\n",day[i],stop[k],year[i]);  
    }       
    system("pause");
    return 0;
}
