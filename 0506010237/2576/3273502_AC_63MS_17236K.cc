#include <iostream>
using namespace std;
int data[110];
int sum;
int result[101][25000][2]={0};
int temp=0;


int main()
{
    int num,i,sum=0,j;
    cin>>num;
    for(i=1;i<=num;i++)
    {
        cin>>data[i];
        sum+=data[i];
    }
    /*
    本题用动态规划来做，用的是0/1背包的算法。 
    */
    for(i=1;i<num+1;i++)
    {
        for(j=1;j<=sum/2+1;j++)
        {
            if(j>=data[i])
            {
                if(result[i-1][j][0]>result[i-1][j-data[i]][0]+data[i])
                {
                    result[i][j][0]=result[i-1][j][0];
                    result[i][j][1]=result[i-1][j][1];
                }
                else
                {
                    result[i][j][0]=result[i-1][j-data[i]][0]+data[i];
                    result[i][j][1]=result[i-1][j-data[i]][1]+1;
                }
            }
            else
            {
                result[i][j][0]=result[i-1][j][0];
                result[i][j][1]=result[i-1][j][1];
            }  
        }
    }
    j=0;
    for(i=num/2-1;i<num+1;i++)
    {
        for(j=0;j<=sum/2+1;j++)
        {
            if(abs(num-2*result[i][j][1])<=1&&(abs(sum-2*temp)>abs(sum-2*result[i][j][0])))
            temp=result[i][j][0];
        }
    }
    if(temp<(sum-temp))
    cout<<temp<<" "<<sum-temp<<endl;
    else
    cout<<sum-temp<<" "<<temp<<endl;
    system("pause");
    return 0;
}

