/*�б���������  �߶����κ͵����
	Problem Description
C��������ͷA�����ʱ�����ڽ��о�����ϰ������C�����ͷ��Derek��������Tidy�ֿ�ʼæ���ˡ�A���ں�������ֱ�߲�����N������Ӫ��,Derek��Tidy���������Ҫ������Щ����Ӫ�صĻ��������ڲ�ȡ��ĳ���Ƚ��ļ���ֶΣ�����ÿ������Ӫ�ص�����C�������յ�һ�����,ÿ������Ӫ�ص��������п��ܷ����䶯���������ӻ������������,����Щ���Ӳ���C���ļ��ӡ�
�����鱨��Ҫ�о����˾�����ϰʲôս��,����TidyҪ��ʱ��Derek�㱨ĳһ�������Ĺ���Ӫ��һ���ж�����,����Derek��:��Tidy,���ϻ㱨��3��Ӫ�ص���10��Ӫ�ع��ж�����!��Tidy��Ҫ���Ͽ�ʼ������һ�ε����������㱨�����б�Ӫ�ص����������䶯����Derekÿ��ѯ�ʵĶζ���һ��������Tidy���ò�ÿ�ζ�һ��һ��Ӫ�ص�ȥ�����ܿ�;�ƣ�����ˣ�Derek��Tidy�ļ����ٶ�Խ��Խ����:"��������У������ô�����ҳ�������!��Tidy�룺�����Լ������㿴���������һ�����˵Ĺ���!�Һ޲����㳴��������!������֮�£�Tidyֻ�ô�绰������ר��Windbreaker���,Windbreaker˵���������У�����ƽʱ�����acm��Ϳ�����㷨�飬���ڳ�������˰�!��Tidy˵��"��֪���ˡ�����"��Windbreaker�Ѿ��ҵ��绰�ˡ�Tidy�ܿ��գ���ô������Ļ�����ģ������Ķ��ߣ�����д������������������𣿲��������ĳ���Ч�ʲ����ߵĻ���Tidy���ǻ��ܵ�Derek�������.

 

Input
��һ��һ������T����ʾ��T�����ݡ�
ÿ�����ݵ�һ��һ��������N��N<=50000��,��ʾ������N������Ӫ�أ���������N��������,��i��������ai�����i������Ӫ���￪ʼʱ��ai���ˣ�1<=ai<=50����
������ÿ����һ�����������4����ʽ��
(1) Add i j,i��jΪ������,��ʾ��i��Ӫ������j���ˣ�j������30��
(2)Sub i j ,i��jΪ������,��ʾ��i��Ӫ�ؼ���j���ˣ�j������30��;
(3)Query i j ,i��jΪ������,i<=j����ʾѯ�ʵ�i����j��Ӫ�ص�������;
(4)End ��ʾ����������������ÿ������������;
ÿ�����������40000������

 

Output
�Ե�i������,���������Case i:���ͻس�,
����ÿ��Queryѯ�ʣ����һ���������س�,��ʾѯ�ʵĶ��е�������,�����������int���ڡ�

 

Sample Input
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 
 

Sample Output
Case 1:
6
33
59

	*/
#include<iostream>
#include<cstdio>
#include<cstdarg>
#include<stdlib.h>
#include<cstring>
#include<cmath>
using namespace std;
const int N=50005;
struct Node
{
    int l;
    int r;
    int num;
}aNode[4*N];
int data[N];
void build(int l,int r,int n)//l����� r���Ҷ� n�ݹ��ã�һ���ʼΪ1
{
    int mid=(l+r)>>1;
    if(l==r){
        aNode[n].l=l;
        aNode[n].r=r;
        aNode[n].num=data[l];
    }
    else{
        aNode[n].l=l;
        aNode[n].r=r;
        build(l,mid,2*n);
        build(mid+1,r,2*n+1);
        aNode[n].num=aNode[2*n].num+aNode[2*n+1].num;
    }
}
int query(int l,int r,int n)
{
    int mid=(aNode[n].l+aNode[n].r)>>1;
    if((aNode[n].l==l)&&(aNode[n].r==r))
    return aNode[n].num;
    else{
        if(r<=mid)
            return(query(l,r,2*n));
        else if(l>mid)
            return query(l,r,2*n+1);
        else
            return (query(l,mid,2*n)+query(mid+1,r,2*n+1));
    }
}
void add(int nid,int d,int n)
{
    int mid=(aNode[n].l+aNode[n].r)>>1;
    if((aNode[n].l==nid)&&(aNode[n].r==nid)){
        aNode[n].num+=d;
        int newn=(n>>1);
        while(newn>=1){
            aNode[newn].num=aNode[2*newn].num+aNode[2*newn+1].num;
            newn=newn>>1;
        }
    }
    else{
        if(nid<=mid)
            add(nid,d,2*n);
        else if(nid>mid)
            add(nid,d,2*n+1);
    }
}
void sub(int nid,int d,int n)
{
    int mid=(aNode[n].l+aNode[n].r)>>1;
    if((aNode[n].l==nid)&&(aNode[n].r==nid)){
        aNode[n].num-=d;
        int newn=(n>>1);
        while(newn>=1){
            aNode[newn].num=aNode[2*newn].num+aNode[2*newn+1].num;
            newn=newn>>1;
        }
    }
    else{
        if(nid<=mid)
            sub(nid,d,2*n);
        else if(nid>mid)
            sub(nid,d,2*n+1);
    }
}
int main()
{
    int t,id=1,n;
    scanf("%d",&t);
    char cmd[20];
    while(id<=t){  
        int a,b;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&data[i]);
        build(1,n,1);//��ʼ���߶���
        printf("Case %d:\n",id);
        while(1){
        scanf("%s",cmd);
        if(cmd[0]=='Q')
        {
            scanf("%d%d",&a,&b);
            int ans=query(a,b,1);
            printf("%d\n",ans);
        }
        else if(cmd[0]=='A')
        {
            scanf("%d%d",&a,&b);
            add(a,b,1);
        }
        else if(cmd[0]=='S')
        {
            scanf("%d%d",&a,&b);
            sub(a,b,1);
        }
        else if(cmd[0]=='E')
            break;
        }
        id++;
    }
  //system("pause");
  return 0;
}