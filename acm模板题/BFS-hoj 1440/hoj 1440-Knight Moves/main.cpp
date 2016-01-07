/*Knight Moves BFS
	A friend of you is doing research on the Traveling Knight Problem (TKP) where you are to find the shortest closed tour of knight moves that visits each square of a given set of n squares on a chessboard exactly once. He thinks that the most difficult part of the problem is determining the smallest number of knight moves between two given squares and that, once you have accomplished this, finding the tour would be easy.
Of course you know that it is vice versa. So you offer him to write a program that solves the "difficult" part. 

Your job is to write a program that takes two squares a and b as input and then determines the number of knight moves on a shortest route from a to b. 

Input Specification

The input file will contain one or more test cases. Each test case consists of one line containing two squares separated by one space. A square is a string consisting of a letter (a-h) representing the column and a digit (1-8) representing the row on the chessboard. 

Output Specification

For each test case, print one line saying "To get from xx to yy takes n knight moves.". 

Sample Input 

e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6Sample Output To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.
	*/
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
