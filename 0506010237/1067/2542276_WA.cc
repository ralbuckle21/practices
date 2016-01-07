#include<iostream>
using namespace std;
int main()
{
    int mg[500][2];
    int k=2;
    mg[0][0]=2;
    mg[0][1]=1;
    mg[1][0]=5;
    mg[1][1]=3;
    mg[2][0]=7;
    mg[2][1]=4;
    int a,b;
    while(cin>>a && cin>>b)
    {
        if(a==0 || b==0 || a==b)
           cout<<"1"<<endl;
        else
        {
             if(a<b)
             {
                int t=a;
                a=b;
                b=t;       
             }
             int h=0;
             while(h<=k && mg[h][0]<a)
                 h++;
             if(h<=k)
             {
                if(mg[h][0]==a && mg[h][1]==b)
                  cout<<"0"<<endl;
                else
                  cout<<"1"<<endl; 
                continue;      
             }
             while(mg[k][0]<a)
             {
                   k++;
                   mg[k][0]=mg[k-2][0]+mg[k-1][0];
                   mg[k][1]=mg[k-2][1]+mg[k-1][1];
             }
             if(mg[k][0]==a && mg[h][1]==b)
                  cout<<"0"<<endl;
             else
                  cout<<"1"<<endl;    
        }           
    }
    system("pause");
    return 0;
}
