#include<iostream>
using namespace std;
struct Point
{
    int x,y;
};
struct Segment
{
    Point a,b;
};//�����յ�
Segment seg[20];
int father[20],rk[20];//���鼯����
/*��������p1p2������p1p3�Ĳ������p1p3��p1p2����ʱ�뷽���򷵻�>0��˳ʱ�뷽�򷵻�<0*/
int multiply(Point p1,Point p2,Point p3)
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
bool isIntersect(Point p1,Point p2,Point q1,Point q2)
{
    if(max(p1.x,p2.x)<min(q1.x,q2.x)||max(q1.x,q2.x)<min(p1.x,p2.x)||max(p1.y,p2.y)<min(q1.y,q2.y)||max(q1.y,q2.y)<min(p1.y,p2.y))
        return 0;//�����ų⣬�������β��ཻ�����߶�һ�����ཻ
    if(multiply(q1,q2,p1)*multiply(q1,q2,p2)<=0&&multiply(p1,p2,q1)*multiply(p1,p2,q2)<=0)
        return 1;//����ʵ��
    else return 0;
}
int findRoot(int v)//���鼯����
{
    if(father[v]==v)
        return v;
    else
    {
        father[v]=findRoot(father[v]);//·��ѹ��
        return father[v];
     }
}
void unionSet(int x,int y)
{
    int fx=findRoot(x);
    int fy=findRoot(y);
    if (rk[fx]>rk[fy])//�Ƚ��������ϵ���Ƚ��кϲ�
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
            father[i]=i;//���鼯���ֵĳ�ʼ��
            rk[i]=0;
        }
        for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++)
                if(findRoot(i)!=findRoot(j)&&isIntersect(seg[i].a,seg[i].b,seg[j].a,seg[j].b))//�ཻ�Ҹ���ͬ��ϲ�
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