/*AC�Զ���
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
    int fail[MAX_NODE];//��kmp�е�next�������ƣ���¼ƥ��ʧ��ʱ֮ǰ��ƥ��ɹ�����
    int val[MAX_NODE];
    int ID[128];
    int sz;
    queue<int> q;

    AC_Automaton() {
        for (int i = 0; i < 26; i++)
            ID[i + 'a'] = i;//��ʼ��ID��
        Clear();
    }

    void Clear() {
        memset(chd, 0, sizeof (chd));
        memset(fail, 0, sizeof (fail));
        memset(val, 0, sizeof (val));
        sz = 1;
    }

    void Insert(const char *s) {//����һ���ؼ�����,�γ��ֵ���
        int cur = 1;
        for (int i = 0; s[i]; i++) {
            if (!chd[cur][ID[s[i]]]) chd[cur][ID[s[i]]] = ++sz;//���¹ؼ��ʲ��뵽trie���У�rootΪ��һ���ڵ㣬�����ڵ��±����
            cur = chd[cur][ID[s[i]]];//cul��¼�˹ؼ��ʽڵ���±�
        }
        val[cur]++;//�����ǰcur�±�Ľڵ���һ���ؼ��ʵĽ�β��val���1
    }
    void Build_AC() {//����AC�Զ��������ݽṹ����Ҫ��ʧ��ָ��Ĺ���
        while (!q.empty()) q.pop();
        q.push(1);//���ڵ�������
        fail[1] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < MAX_CHILD; i++)
                if (chd[cur][i]) {//ÿһ���ڵ㶼��ʧ��ָ�룬ָ����ڵ㣬����ָ������ֶ���ͬ�Ľڵ�
                    if (cur == 1) fail[chd[cur][i]] = 1;//����ʧ�ܽڵ�
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
        int cur = 1, tmp;//cur�ǵ�ǰ�ڵ�ı��
        for (int i = 0; s[i]; i++) {
            if (chd[cur][ID[s[i]]]) cur = chd[cur][ID[s[i]]];
            else {
                while (cur != 1 && chd[cur][ID[s[i]]] == 0) cur = fail[cur];//��ǰ��ƥ��
                if (chd[cur][ID[s[i]]]) cur = chd[cur][ID[s[i]]];
            }
            tmp = cur;
            while (tmp != 1 && val[tmp] != -1) {//ƥ��ɹ�
                ret += val[tmp];
                val[tmp] = -1;//����ƥ�䣬��ֹ���ֶ���ظ�ƥ��
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