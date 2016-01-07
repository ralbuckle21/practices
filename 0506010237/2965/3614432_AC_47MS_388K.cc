#include<iostream>
using namespace std;
char mg[5][5];
bool v[4][4]={0};
int n=0;
int main()
{
    for(int i=0;i<4;i++) scanf("%s",mg[i]);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
             if(mg[i][j]=='+'){
                 v[i][j]=!v[i][j];
                 for(int k=0;k<4;k++){
                     v[i][k]=!v[i][k];
                     v[k][j]=!v[k][j];        
                 }                  
             }        
        }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(v[i][j]) n++;
    printf("%d\n",n);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(v[i][j]) printf("%d %d\n",i+1,j+1);
    system("pause");
    return 0;
}
