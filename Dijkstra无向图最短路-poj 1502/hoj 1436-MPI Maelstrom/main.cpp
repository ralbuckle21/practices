/*MPI Maelsorm
	Dijkstra无向图最短路
	BIT has recently taken delivery of their new supercomputer, a 32 processor Apollo Odyssey distributed shared memory machine with a hierarchical communication subsystem. Valentine McKee's research advisor, Jack Swigert, has asked her to benchmark the new system. 
``Since the Apollo is a distributed shared memory machine, memory access and communication times are not uniform,'' Valentine told Swigert. ``Communication is fast between processors that share the same memory subsystem, but it is slower between processors that are not on the same subsystem. Communication between the Apollo and machines in our lab is slower yet.'' 

``How is Apollo's port of the Message Passing Interface (MPI) working out?'' Swigert asked. 

``Not so well,'' Valentine replied. ``To do a broadcast of a message from one processor to all the other n-1 processors, they just do a sequence of n-1 sends. That really serializes things and kills the performance.'' 

``Is there anything you can do to fix that?'' 

``Yes,'' smiled Valentine. ``There is. Once the first processor has sent the message to another, those two can then send messages to two other hosts at the same time. Then there will be four hosts that can send, and so on.'' 

``Ah, so you can do the broadcast as a binary tree!'' 

``Not really a binary tree -- there are some particular features of our network that we should exploit. The interface cards we have allow each processor to simultaneously send messages to any number of the other processors connected to it. However, the messages don't necessarily arrive at the destinations at the same time -- there is a communication cost involved. In general, we need to take into account the communication costs for each link in our network topologies and plan accordingly to minimize the total time required to do a broadcast.''
Input

The input will describe the topology of a network connecting n processors. The first line of the input will be n, the number of processors, such that 1 <= n <= 100. 

The rest of the input defines an adjacency matrix, A. The adjacency matrix is square and of size n x n. Each of its entries will be either an integer or the character x. The value of A(i,j) indicates the expense of sending a message directly from node i to node j. A value of x for A(i,j) indicates that a message cannot be sent directly from node i to node j. 

Note that for a node to send a message to itself does not require network communication, so A(i,i) = 0 for 1 <= i <= n. Also, you may assume that the network is undirected (messages can go in either direction with equal overhead), so that A(i,j) = A(j,i). Thus only the entries on the (strictly) lower triangular portion of A will be supplied. 

The input to your program will be the lower triangular section of A. That is, the second line of input will contain one entry, A(2,1). The next line will contain two entries, A(3,1) and A(3,2), and so on.
Output

Your program should output the minimum communication time required to broadcast a message from the first processor to all the other processors.
Sample Input

5
50
30 5
100 20 50
10 x x 10
Sample Output

35
	*/
//dijkstra本质：按路径长度递增依次产生最短路径
/*
1.初始化所有结点并将起始点设为标记，进入以下循环
2.在到达某点的最短路径中找最小且未标记的点（可以用一维数组表示）
3.标记找到的点，以此标记点为中间点重新计算所有未标记点的最短路径（更新最短路径表）
4.循环1.2步至n-1次（n为顶点数，若最后还有未被标记的，说明无法到达此点）
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define N 105
#define inf 0x3f3f3f3f
//模板下标从1开始
struct node {
    int v, w;
    node() {}
    node(int _v, int _w):v(_v), w(_w) {}
};
vector<node> g[N];
int n, m, d[N];
bool vis[N];
int Dijkstra(int s, int t) {
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
    d[s] = 0;
    for (int i=0; i<n; i++) {
        int k = 0, mi = inf;
        for (int j=1; j<=n; j++) if (!vis[j] && d[j] < mi)
            mi = d[j], k = j;//找最小未标记
        if (k == 0) break;
        vis[k] = true;//标记点
        for (int j=0, v, w; j<g[k].size(); j++) {
            v = g[k][j].v, w = g[k][j].w;
            if (!vis[v] && d[v] > d[k] + w)
                d[v] = d[k] + w;//更新所有未标记点的最短路径
        }
    }
    return d[t];
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
              char ch[20];
              scanf("%s",ch);
              if(ch[0]!='x'){
				  int temp=atoi(ch);
				  g[i].push_back(node(j,temp));
				  g[j].push_back(node(i,temp));
			  }
        }
    }
	int res=0;
	for(int i=2;i<=n;i++){
          res=max(res,Dijkstra(1,i));
      }
      printf("%d\n",res) ;
}
