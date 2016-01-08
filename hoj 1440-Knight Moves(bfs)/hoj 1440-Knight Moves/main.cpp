#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct point{
    int x,y,s;
};
int mov[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};//8�����ܵķ���
int main()
{
    char order[6];
    while(cin.getline(order,6)){
        queue<point> steps;//����һ��������������
        while(!steps.empty())
            steps.pop();
        bool visited[8][8]={false};//��¼���ʱ�
        point first,temp,t1;
        first.x=order[0]-97;
        first.y=order[1]-49;
        first.s=0;//��һ���㣬s��¼����
        steps.push(first);//bfs��ʼʱֻ�����һ����
        while(!steps.empty()){
            temp=steps.front();//ȡ��������
            steps.pop();
            if(temp.x==(order[3]-97)&&temp.y==(order[4]-49)){//������Ŀ��
                cout<<"To get from "<<order[0]<<order[1]<<" to "<<order[3]<<order[4]<<" takes "<<temp.s<<" knight moves."<<endl;
                break;
            }
            else{
                for(int i=0;i<8;i++){//����8��������ƶ������Ŀ�ĵ�û�б����ʹ����������У���ʹ��sֵ+1
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
