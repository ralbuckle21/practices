#include<iostream>
using namespace std;
struct Point
{
    int x,y;
};
struct Segment
{
    Point a,b;
};//起点和终点
Segment seg[20];
int father[20],rk[20];//并查集数组
/*计算向量p1p2与向量p1p3的叉积，若p1p3在p1p2的逆时针方向，则返回>0，顺时针方向返回<0*/
int multiply(Point p1,Point p2,Point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
bool isIntersect(Point p1,Point p2,Point q1,Point q2)
{
    if(max(p1.x,p2.x)<min(q1.x,q2.x)||max(q1.x,q2.x)<min(p1.x,p2.x)||max(p1.y,p2.y)<min(q1.y,q2.y)||max(q1.y,q2.y)<min(p1.y,p2.y))
        return 0;//快速排斥，两个矩形不相交则两线段一定不相交
    if(multiply(q1,q2,p1)*multiply(q1,q2,p2)<=0&&multiply(p1,p2,q1)*multiply(p1,p2,q2)<=0)
        return 1;//跨立实验
    else return 0;
}
int findRoot(int v)//并查集部分
{
    if(father[v]==v)
        return v;
    else
    {
        father[v]=findRoot(father[v]);//路径压缩
        return father[v];
     }
}
void unionSet(int x,int y)
{
    int fx=findRoot(x);
    int fy=findRoot(y);
    if (rk[fx]>rk[fy])//比较两个集合的深度进行合并
        father[fy]=fx;
    else
    {
        father[fx]=fy;
        if(rk[fx]==rk[fy])
           rk[fy]++;
     }
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>seg[i].a.x>>seg[i].a.y>>seg[i].b.x>>seg[i].b.y;
            father[i]=i;//并查集部分的初始化
            rk[i]=0;
        }
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++)
                if(findRoot(i)!=findRoot(j)&&isIntersect(seg[i].a,seg[i].b,seg[j].a,seg[j].b))//相交且根不同则合并
                    unionSet(i,j);
        int a,b;
        while(cin>>a>>b)
        {
            if(a==0&&b==0)
                break;
            if(findRoot(a)==findRoot(b))
                cout<<"CONNECTED"<<endl;
            else
                cout<<"NOT CONNECTED"<<endl;
        }
	}
}