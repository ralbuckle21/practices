#include <iostream>
using namespace std;

typedef pair<__int64,__int64> P;
const __int64 N = 50000;
unsigned __int64 Inf;

unsigned __int64 weight[N+1];
unsigned __int64 Mincost[N+1];

inline void InitInf()
{
    memset(&Inf,0xff,sizeof(Inf));
}

class Heap
{
private:
    __int64 Size;
    P arr[N+1];
    __int64 pos[N+1];
public:
    Heap()
    {
        memset(pos,0,sizeof(pos));
        Size = 0;
    }
    void Reset()
    {
        memset(pos,0,sizeof(pos));
        Size = 0;
    }
    void Push(const P &rhs)
    {
        __int64 p;
        if(pos[rhs.second] == 0)
        {
            p = ++Size;
        }
        else p = pos[rhs.second];
        while(p/2 > 0 && arr[p/2].first > rhs.first)
        {
            arr[p] = arr[p/2];
            pos[arr[p].second] = p;
            p /= 2;
        }
        arr[p] = rhs;
        pos[arr[p].second] = p;
    }
    void Pop()
    {
        P tmp = arr[Size--];
        __int64 p = 1;
        for(__int64 i=2*p;i<=Size;i=2*p)
        {
            if(i+1<=Size && arr[i].first>arr[i+1].first) ++i;
            if(tmp.first < arr[i].first) break;
            arr[p] = arr[i];
            pos[arr[p].second] = p;
            p = i;
        }
        arr[p] = tmp;
        pos[arr[p].second] = p;
    }
    const P &Top()
    {
        return arr[1];
    }
    bool Empty() const
    {
        return Size == 0;
    } 
};

class Map
{
private:
    struct Node
    {
        __int64 v,len,next;
        Node(__int64 a=0,__int64 b=0,__int64 c=0):v(a),len(b),next(c){}
    }Edge[2*N+1];
    Heap pq;
    P Header[N+1];
    __int64 Size;
public:
    Map()
    {
        memset(Header,0,sizeof(Header));
        Size = 1;
    }
    void Reset()
    {
        memset(Header,0,sizeof(Header));
        Size = 1;
        pq.Reset();
    }
    void Insert(__int64 a,__int64 b,__int64 c)
    {
        Edge[Size].v = b;
        Edge[Size].len = c;
        Edge[Size].next = 0;
        if(Header[a].first == 0)   Header[a] = P(Size,Size);
        else
        {
            Edge[Header[a].second].next = Size;
            Header[a].second = Size;
        }
        ++Size;
    }
    void Dijkstra()
    {
        memset(Mincost,0xff,sizeof(Mincost));
        Mincost[1] = 0;
        pq.Push(P(0,1));
        while(!pq.Empty())
        {
            __int64 len = pq.Top().first;
            __int64 v = pq.Top().second;
            pq.Pop();
            if(len != Mincost[v]) continue;
            for(__int64 i=Header[v].first;i!=0;i=Edge[i].next)
            {
                if(Mincost[Edge[i].v] > len + Edge[i].len)
                {
                    Mincost[Edge[i].v] = len + Edge[i].len;
                    pq.Push(P(Mincost[Edge[i].v],Edge[i].v));
                }
            }
        }
    }
}map;

int main()
{
    __int64 t,v,e,a,b,c;
    InitInf();
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&v,&e);
        for(__int64 i=1;i<=v;++i) scanf("%I64u",&weight[i]);
        for(__int64 i=1;i<=e;++i)
        {
            scanf("%I64d%I64d%I64d",&a,&b,&c);
            map.Insert(a,b,c);
            map.Insert(b,a,c);
        }
        map.Dijkstra();
        unsigned __int64 ans = 0;
        for(__int64 i=1;i<=v;++i)
        {
            if(Mincost[i] == Inf)
            {
                ans = Inf;
                break;
            }
            ans += Mincost[i] * weight[i];
        }
        if(ans == Inf) printf("No Answer\n");
        else printf("%I64u\n",ans);
        map.Reset();
    }
    return 0;
}
