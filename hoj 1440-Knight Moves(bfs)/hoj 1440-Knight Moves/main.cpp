#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct point{
    int x,y,s;
};
int mov[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};//8个可能的方向
int main()
{
    char order[6];
    while(cin.getline(order,6)){
        queue<point> steps;//建造一个队列用于搜索
        while(!steps.empty())
            steps.pop();
        bool visited[8][8]={false};//记录访问表
        point first,temp,t1;
        first.x=order[0]-97;
        first.y=order[1]-49;
        first.s=0;//第一个点，s记录步数
        steps.push(first);//bfs初始时只有起点一个点
        while(!steps.empty()){
            temp=steps.front();//取出队列中
            steps.pop();
            if(temp.x==(order[3]-97)&&temp.y==(order[4]-49)){//搜索到目的
                cout<<"To get from "<<order[0]<<order[1]<<" to "<<order[3]<<order[4]<<" takes "<<temp.s<<" knight moves."<<endl;
                break;
            }
            else{
                for(int i=0;i<8;i++){//尝试8个方向的移动，如果目的地没有被访问过则将其加入队列，并使其s值+1
                    t1.x=temp.x+mov[i][0];
                    t1.y=temp.y+mov[i][1];
                    t1.s=temp.s;
                    if(visited[t1.x][t1.y]||t1.x>7||t1.x<0||t1.y>7||t1.y<0){
                        continue;
                    }
                    else{
                        visited[t1.x][t1.y]=true;
                        t1.s++;
                        steps.push(t1);
                    }
                }
            }
        }
    }
}
