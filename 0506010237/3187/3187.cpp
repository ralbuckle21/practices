#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int N,S,a[10],b[10];
    int i,j;
    scanf("%d%d",&N,&S);
    for(i=0;i<N;i++) a[i]=i+1;
    do
    {
        memcpy(b,a,sizeof(a));
        j=N;
        while(j--)
        {
            for(i=0;i<j;i++)
                b[i]+=b[i+1];
        }
        if(b[0]==S) break;
    }while(next_permutation(a,a+N));//ȫ����Ȼ��ÿһ������ʵ���Ƿ����S 
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    system( "pause ");//ʹ�������ͣ�� 
    return 0;
}

