#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
char data[20][20];
bool fd[20][20][4]={0};
vector <int> data1;
vector <int> data2;
int x;int y;
void findnum(int i,int j){
    int num=0;
    if(data[i][j]=='1'){
        if(fd[i][j][1]==0){
            fd[i][j][1]=1;
            while(++num){
                if(i+num>19||data[i][j]!=data[i+num][j])break;
                fd[i+num][j][1]=1;
            }
            data1.push_back(num);
            if(num==5){x=i;y=j;}
        }
        num=0;
        if(fd[i][j][0]==0){
            fd[i][j][0]=1;
            while(++num){
                if(j+num>19||data[i][j]!=data[i][j+num])break;
                fd[i][j+num][0]=1;
            }
            data1.push_back(num);
            if(num==5){x=i;y=j;}
        }
        num=0;
        if(fd[i][j][2]==0){
            fd[i][j][2]=1;
            while(++num){
                if(j-num<=0||i+num>19||data[i][j]!=data[i+num][j-num])break;
                fd[i-num][j+num][2]=1;
            }
            data1.push_back(num);
            if(num==5){x=i+4;y=j-4;}
        }
        num=0;
        if(fd[i][j][3]==0){
            fd[i][j][3]=1;
            while(++num){
                if(i+num>19||j+num>19||data[i][j]!=data[i+num][j+num])break;
                fd[i+num][j+num][3]=1;
            }
            data1.push_back(num);
            if(num==5){x=i;y=j;}
        }
        num=0;
    }
    else if(data[i][j]=='2'){
        if(fd[i][j][1]==0){
            fd[i][j][1]=1;
            while(++num){
                if(i+num>19||data[i][j]!=data[i+num][j])break;
                fd[i+num][j][1]=1;
            }
            data2.push_back(num);
            if(num==5){x=i;y=j;}
        }
        num=0;
        if(fd[i][j][0]==0){
            fd[i][j][0]=1;
            while(++num){
                if(j+num>19||data[i][j]!=data[i][j+num])break;
                fd[i][j+num][0]=1;
            }
            data2.push_back(num);
            if(num==5){x=i;y=j;}
        }
        num=0;
        if(fd[i][j][2]==0){
            fd[i][j][2]=0;
            while(++num){
                if(j-num<=0||i+num>19||data[i][j]!=data[i+num][j-num])break;
                fd[i-num][j+num][2]=1;
            }
            data2.push_back(num);
            if(num==5){x=i+4;y=j-4;}
        }
        num=0;
        if(fd[i][j][3]==0){
            fd[i][j][3]=0;
            while(++num){
                if(i+num>19||j+num>19||data[i][j]!=data[i+num][j+num])break;
                fd[i+num][j+num][3]=1;
            }
            data2.push_back(num);
            if(num==5){x=i;y=j;}
        }
    }

}
int main()
{
    int num;
    bool flag;
    int max1,max2;
    cin>>num;
    while(num--){
        while(data1.size()){data1.pop_back();}
        while(data2.size()){data2.pop_back();}
        for(int i=1;i<=19;++i)
        for(int j=1;j<=19;++j){
            cin>>data[i][j];
            for(int m=0;m<4;++m)fd[i][j][m]=0;
        }
        for(int i=1;i<=19;++i)
        for(int j=1;j<=19;++j){
            findnum(i,j);
        }
        max1=0;
        max2=0;
        for(int i=0;i<data1.size();++i){
            if(data1[i]>max1)max1=data1[i];
        }
        for(int j=0;j<data2.size();++j){
            if(data2[j]>max2)max2=data2[j];
        }
        if(max1==5){printf("1\n%d %d\n",x,y);}
        else if(max2==5){printf("2\n%d %d\n",x,y);}
        else {printf("0\n");continue;}
    }
    system("pause");
    return 0;
}
