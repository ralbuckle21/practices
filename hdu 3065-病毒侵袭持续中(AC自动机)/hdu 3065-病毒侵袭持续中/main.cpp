#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_NODE 50005
#define MAX_CHILD 26
using namespace std;
int ans[1005];
char pat[1005][55], tar[2000005];

class AC_Automaton {
public:
    int chd[MAX_NODE][MAX_CHILD];
    int fail[MAX_NODE];
    int val[MAX_NODE];
    int ID[128];

    int sz;
    queue<int> q;

    AC_Automaton() {
        for (int i = 0; i < 26; i++)
            ID[i + 'A'] = i;
        Clear();
    }

    void Clear() {
        memset(chd, 0, sizeof (chd));
        memset(fail, 0, sizeof (fail));
        memset(val, 0, sizeof (val));
        sz = 1;
    }

    void Insert(const char *s, int id) {
        int cur = 1;
        for (int i = 0; s[i]; i++) {
            if (!chd[cur][ID[s[i]]]) chd[cur][ID[s[i]]] = ++sz;
            cur = chd[cur][ID[s[i]]];
        }
        val[cur] = id;
    }

    void Build_AC() {
        while (!q.empty()) q.pop();
        q.push(1);
        fail[1] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < MAX_CHILD; i++)
                if (chd[cur][i]) {
                    if (cur == 1) fail[chd[cur][i]] = 1;
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

    void Query(const char *s) {
        //       int ret = 0;
        int cur = 1, tmp;
        for (int i = 0; s[i]; i++) {
            if (s[i] >= 'Z' || s[i] < 'A') {
                cur = 1;
                continue;
            }
            if (chd[cur][ID[s[i]]]) cur = chd[cur][ID[s[i]]];
            else {
                while (cur != 1 && chd[cur][ID[s[i]]] == 0) cur = fail[cur];
                if (chd[cur][ID[s[i]]]) cur = chd[cur][ID[s[i]]];
            }
            tmp = cur;
            while (tmp != 1 && val[tmp] != -1) {
                // ret += val[tmp];
                // val[tmp] = -1;
                ans[val[tmp]]++;
                tmp = fail[tmp];
            }
        }
        //        return ret;
    }
} AC;

int main() {
    int n;
    while (scanf("%d", &n) == 1) {

        AC.Clear();
        memset(ans, 0, sizeof (ans));
        for (int i = 1; i <= n; i++) {
            scanf(" %s", pat[i]);
            AC.Insert(pat[i], i);
        }
        AC.Build_AC();
        scanf(" %s", tar);
        AC.Query(tar);
        for (int i = 1; i <= n; i++)
            if (ans[i]) printf("%s: %d\n", pat[i], ans[i]);
    }
    return 0;
}