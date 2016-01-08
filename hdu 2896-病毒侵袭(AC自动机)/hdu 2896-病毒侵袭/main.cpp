#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_NODE 240005
#define MAX_CHILD 26
using namespace std;
int cnt=0,total=0;
class AC_Automaton 
{
public:
    int chd[MAX_NODE][MAX_CHILD];
    int fail[MAX_NODE];//和kmp中的next数组类似，记录匹配失败时之前的匹配成功次数
    int val[MAX_NODE];
	int num[MAX_NODE];
    int ID[128];
    int sz;
	int ans[10001];
    queue<int> q;

    /*AC_Automaton() {
        for (int i = 0; i < 26; i++)
            ID[i + 'a'] = i;//初始化ID表
        Clear();
    }*/
	AC_Automaton() {
        for (int i = 2; i < 127; i++)
            ID[i] = i;//初始化ID表
		Clear();
	}
    void Clear() {
        memset(chd, 0, sizeof (chd));
        memset(fail, 0, sizeof (fail));
        memset(val, 0, sizeof (val));
        sz = 1;
    }

    void Insert(const char *s,int j) {//插入一个关键词树,形成字典树
        int cur = 1;
        for (int i = 0; s[i]; i++) {
            if (!chd[cur][ID[s[i]]]) chd[cur][ID[s[i]]] = ++sz;//把新关键词插入到trie树中，root为第一个节点，其它节点下标递增
            cur = chd[cur][ID[s[i]]];//cul记录了关键词节点的下标
        }
        val[cur]++;//如果当前cur下标的节点是一个关键词的结尾，val变成1
		num[cur]=j;
    }
    void Build_AC() {//构造AC自动机的数据结构，主要是失败指针的构建
        while (!q.empty()) q.pop();
        q.push(1);//根节点进入队列
        fail[1] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < MAX_CHILD; i++)
                if (chd[cur][i]) {//每一个节点都有失败指针，指向根节点，或者指向和它字段相同的节点
                    if (cur == 1) fail[chd[cur][i]] = 1;//设置失败节点
                    else {
                        int tmp = fail[cur];
                        while (tmp != 1 && chd[tmp][i] == 0) tmp = fail[tmp];
                        if (chd[tmp][i]) fail[chd[cur][i]] = chd[tmp][i];
                        else fail[chd[cur][i]] = 1;
                    }
                    q.push(chd[cur][i]);
                }
        }
    }
    int Query(const char *s,int j) {
		cnt=0;
        int ret = 0;
        int cur = 1, tmp;//cur是当前节点的编号
        for (int i = 0; s[i]; i++) {
            if (chd[cur][ID[s[i]]]) cur = chd[cur][ID[s[i]]];
            else {
                while (cur != 1 && chd[cur][ID[s[i]]] == 0) cur = fail[cur];//当前不匹配
                if (chd[cur][ID[s[i]]]) cur = chd[cur][ID[s[i]]];
            }
            tmp = cur;
            while (tmp != 1 && val[tmp] != -1) {//匹配成功
                ret += val[tmp];
                val[tmp] = -1;//单次匹配，防止出现多次重复匹配
				if(num[tmp]!=0) 
				{
					ans[cnt]=num[tmp];//printf(" %d",num[tmp]);
					cnt++;
				}
                tmp = fail[tmp];
            }
			printf("fuck%d\n",i);
        }
		printf("shit\n");
		if(cnt)
		{
			printf("web %d:",j);
			for(int i=0;i<cnt;i++)
				printf(" %d",ans[i]);
			printf("\n");
			total++;
		}
        return ret;
    }
}AC;
char pat[201], tar[10001];
int main()
{
	int n,m;
	while(scanf("%d",&n)==1)
	{
	    for(int i=1;i<=n;i++)
		{
			scanf(" %s",pat);
			AC.Insert(pat,i);
		}
		AC.Build_AC();
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
		    scanf(" %s",tar);
			AC.Query(tar,i);
		}
		printf("total: %d\n",total);
	}
}