/*AC自动机
Problem Description
In the modern time, Search engine came into the life of everybody like Google, Baidu, etc.
Wiskey also wants to bring this feature to his image retrieval system.
Every image have a long description, when users type some keywords to find the image, the system will match the keywords with description of image and show the image which the most keywords be matched.
To simplify the problem, giving you a description of image, and some keywords, you should tell me how many keywords will be match.

Input
First line will contain one integer means how many cases will follow by.
Each case will contain two integers N means the number of keywords and N keywords follow. (N <= 10000)
Each keyword will only contains characters 'a'-'z', and the length will be not longer than 50.
The last line is the description, and the length will be not longer than 1000000.

Output
Print how many keywords are contained in the description.

Sample Input
1
5
she
he
say
shr
her
yasherhs

Sample Output
3*/
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_NODE 240005
#define MAX_CHILD 26
using namespace std;
class AC_Automaton 
{
public:
    int chd[MAX_NODE][MAX_CHILD];
    int fail[MAX_NODE];//和kmp中的next数组类似，记录匹配失败时之前的匹配成功次数
    int val[MAX_NODE];
    int ID[128];
    int sz;
    queue<int> q;

    AC_Automaton() {
        for (int i = 0; i < 26; i++)
            ID[i + 'a'] = i;//初始化ID表
        Clear();
    }

    void Clear() {
        memset(chd, 0, sizeof (chd));
        memset(fail, 0, sizeof (fail));
        memset(val, 0, sizeof (val));
        sz = 1;
    }

    void Insert(const char *s) {//插入一个关键词树,形成字典树
        int cur = 1;
        for (int i = 0; s[i]; i++) {
            if (!chd[cur][ID[s[i]]]) chd[cur][ID[s[i]]] = ++sz;//把新关键词插入到trie树中，root为第一个节点，其它节点下标递增
            cur = chd[cur][ID[s[i]]];//cul记录了关键词节点的下标
        }
        val[cur]++;//如果当前cur下标的节点是一个关键词的结尾，val变成1
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

    int Query(const char *s) {
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
                tmp = fail[tmp];
            }
        }
        return ret;
    }
}AC;
char pat[60], tar[1000001];
int main() 
{
    int cas, n;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        AC.Clear();
        while (n--) {
            scanf(" %s", pat);
            AC.Insert(pat);
        }
		
        AC.Build_AC();
        scanf(" %s", tar);
        printf("%d\n", AC.Query(tar));
    }
    return 0;
}