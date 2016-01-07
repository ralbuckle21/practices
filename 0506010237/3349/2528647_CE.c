            #include <stdio.h>
#include <stdlib.h>
int mg[100000][7];
int main()
{
    int n,result=0,min,k,xu,j,w,i,h;
    char c;
    int ex[6];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(h=0;h<6;h++)
        {
            c=getchar();
            ex[h]=0;
           while(c>='9' || c<='0')
           {
                c=getchar();
           }
           while(c>='0' && c<='9')
           {
               ex[h]=ex[h]*10+int(c-'0');
               c=getchar();
           }
        }
         if(result==0)
         {
           k=0;
           xu=0;
           mg[i][6]=min=ex[0];
           for(j=1;j<6;j++)
           {
              if(min>ex[j])
              {
                 min=ex[j];
                 k=j;
              }
              mg[i][6]=ex[j]+mg[i][6];
          }
          if(ex[(k+5)%6]<ex[(k+7)%6])
              xu=1;
          if(xu==0)
            for(j=0;j<6;j++)
              mg[i][j]=ex[(k+j)%6];
          else if(xu==1)
            for(j=0;j<6;j++)
               mg[i][j]=ex[(k+6-j)%6];
          for(w=0;w<i;w++)
          {
             if(mg[w][6]==mg[i][6])
             {
                if(mg[i][0]==mg[w][0] && mg[i][1]==mg[w][1] && mg[i][2]==mg[w][2] && mg[i][3]==mg[w][3] && mg[i][4]==mg[w][4] && mg[i][5]==mg[w][5])
                {
                   printf("%s\n","Twin snowflakes found.");
                   result=1;
                }
             }
             if(result==1)
               break;
         }
       }
    }
    if(result==0)
       printf("%s\n","No two snowflakes are alike.");
    return 0;
}

