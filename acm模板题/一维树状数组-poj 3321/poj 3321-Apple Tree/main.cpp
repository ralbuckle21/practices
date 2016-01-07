/*Apple Tree Ò»Î¬Ê÷×´Êý×é
There is an apple tree outside of kaka's house. Every autumn, a lot of apples will grow in the tree. Kaka likes apple very much, so he has been carefully nurturing the big apple tree.

The tree has N forks which are connected by branches. Kaka numbers the forks by 1 to N and the root is always numbered by 1. Apples will grow on the forks and two apple won't grow on the same fork. kaka wants to know how many apples are there in a sub-tree, for his study of the produce ability of the apple tree.

The trouble is that a new apple may grow on an empty fork some time and kaka may pick an apple from the tree for his dessert. Can you help kaka?


Input

The first line contains an integer N (N ¡Ü 100,000) , which is the number of the forks in the tree.
The following N - 1 lines each contain two integers u and v, which means fork u and fork v are connected by a branch.
The next line contains an integer M (M ¡Ü 100,000).
The following M lines each contain a message which is either
"C x" which means the existence of the apple on fork x has been changed. i.e. if there is an apple on the fork, then Kaka pick it; otherwise a new apple has grown on the empty fork.
or
"Q x" which means an inquiry for the number of apples in the sub-tree above the fork x, including the apple (if exists) on the fork x
Note the tree is full of apples at the beginning

Output

For every inquiry, output the correspond answer per line.
Sample Input

3
1 2
1 3
3
Q 1
C 2
Q 1
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 1001000
using namespace std;
int head[N],next[N],to[N],d[N],cnt,num,st[N],end[N],n,m;
bool vis[N];
void add(int u,int v)
{
    to[cnt]=v; next[cnt]=head[u]; head[u]=cnt++;
}
void read()
{
    memset(head,-1,sizeof head);
    cnt=0;
    for(int i=1,a,b;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b); add(b,a);
    }
}
void dfs(int u)
{
    st[u]=++num;
    vis[u]=true;
    for(int i=head[u];~i;i=next[i])
        if(!vis[to[i]])
            dfs(to[i]);
    end[u]=num;
}
int lowbit(int k)
{
    return k&(-k);
}
void updata(int x,int nu)
{
    while(x<=num)
    {
        d[x]+=nu;
        x+=lowbit(x);
    }
}
int getsum(int x)
{
    int sum=0;
    while(x)
    {
        sum+=d[x];
        x-=lowbit(x);
    }
    return sum;
}
void go()
{
    memset(vis,0,sizeof vis);
    num=0;
    dfs(1);
    for(int i=1;i<=n;i++) updata(i,1);
    scanf("%d",&m);
    int a;char b;
    while(m--)
    {
        getchar();
        scanf("%c%d",&b,&a);
        if(b=='C') 
        {
            if(getsum(st[a])-getsum(st[a]-1)==1)
                updata(st[a],-1);
            else updata(st[a],1);
        }
        else printf("%d\n",getsum(end[a])-getsum(st[a]-1));
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        read();
        go();
    }
    return 0;
}