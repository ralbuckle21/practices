#include <cstring>//memset
#include <climits>//INT_MAX
#include <deque>//as a queue in the BFS

using namespace std;

const int MAX_VERTEX = 1010;

struct Edge {
    int to, cap, flow, cost;
    Edge *next, *rev;
    Edge(int t = 0, int ca = 0, int co = 0, Edge* n = NULL)
        :to(t), cap(ca), cost(co), next(n), flow(0) {}
};
Edge g_mem[MAX_VERTEX * MAX_VERTEX];
int g_allocN = 0;
Edge* newEdge(int t, int ca, int co = 0, Edge* n = NULL){ 
      g_mem[g_allocN] = Edge(t, ca, co, n);
      return &g_mem[g_allocN++]; 
}
class Network {
public:
    void addEdge(int from, int to, int cap, int revCap, int cost = 0) {
        m_adj[from] = newEdge( to,   cap,     cost, m_adj[from] );
        m_adj[to] =   newEdge( from, revCap, -cost, m_adj[to]   );
        m_adj[from]->rev = m_adj[to];  m_adj[to]->rev = m_adj[from];
    }
    void clear() { 
         memset( m_adj, 0, sizeof(m_adj) );
         g_allocN = 0; 
    }
    void init(int n, int source, int sink){ 
         clear();  
         m_n = n;  
         m_src = source;  
         m_snk = sink; 
    }
    //Before invoking this function, "minCostMaxFlow()" must be invoked.
    int minCost() const { return m_minC; }
    int minCostMaxFlow() {
        int result = 0;
        m_minC = 0;
		int cnt = 2;
        while ( cnt-- && findMinCostAugment() ) {
            for (int i = m_snk; i != m_src; i = m_path[i].pre)
                { m_path[i].edge->flow++;
                  m_path[i].edge->rev->flow--; }
            result++;
            m_minC += m_path[m_snk].cost;
        }
        return result;
    }

private:
    struct Path { int pre, cap, cost;//To store a vertex on an
                  Edge* edge; };     //augment path.

    //Find an augment path which has 1 unit of flow and minimum cost.
    bool findMinCostAugment() {
        for (int i = 0; i < m_n; i++) { m_path[i].pre = -1;
                                        m_path[i].cost = INT_MAX; }
        m_path[m_src].pre = m_src;  m_path[m_src].cost = 0;
        deque<int> que(1, m_src);
        while ( !que.empty() ) {
            int from = que.front();  que.pop_front();
            for (Edge* e = m_adj[from]; e; e = e->next)
                if (e->cap > e->flow) {
                    int cost = m_path[from].cost + e->cost, to = e->to;
                    if (cost < m_path[to].cost) {
                        m_path[to].cost = cost;
                        m_path[to].pre = from;
                        m_path[to].edge = e;
                        if (to != m_snk)  que.push_back(to);
                    }
                }
        }
        return m_path[m_snk].pre != -1;
    }

    Edge* m_adj[MAX_VERTEX];
    int m_n, m_src, m_snk, m_minC;
    Path m_path[MAX_VERTEX];
};

//Main algorithm.
#include <cstdio>
#include <set>

const int MAX_N = 210;
const int MAX_X = 110000;

struct Intv { int l, r, w; };

Intv g_intv[MAX_N];
int g_n;
int g_bnd;//Maximum overlap time allowed.
int g_newX[MAX_X + 1];//Map old coordinates to new ones.
int g_maxX;
Network g_net;

void solve() {
	int m;
	scanf("%d%d", &g_maxX, &m);
    g_net.init(g_maxX + 1, 0, g_maxX - 1);
    for (int x = 0; x < m; x++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--,b--;
        g_net.addEdge(a, b, 1, 0, c);
		g_net.addEdge(b, a, 1, 0, c);
	}
    int f = g_net.minCostMaxFlow();
    int cost = g_net.minCost();
    printf("%d\n", cost);
}

int main() {
	solve();
    return 0;
}