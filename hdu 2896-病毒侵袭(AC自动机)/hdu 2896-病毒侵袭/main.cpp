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
    int fail[MAX_NODE];//��kmp�е�next�������ƣ���¼ƥ��ʧ��ʱ֮ǰ��ƥ��ɹ�����
    int val[MAX_NODE];
	int num[MAX_NODE];
    int ID[128];
    int sz;
	int ans[10001];
    queue<int> q;

    /*AC_Automaton() {
        for (int i = 0; i < 26; i++)
            ID[i + 'a'] = i;//��ʼ��ID��
        Clear();
    }*/
	AC_Automaton() {
        for (int i = 2; i < 127; i++)
            ID[i] = i;//��ʼ��ID��
		Clear();
	}
    void Clear() {
        memset(chd, 0, sizeof (chd));
        memset(fail, 0, sizeof (fail));
        memset(val, 0, sizeof (val));
        sz = 1;
    }

    void Insert(const char *s,int j) {//����һ���ؼ�����,�γ��ֵ���
        int cur = 1;
        for (int i = 0; s[i]; i++) {
            if (!chd[cur][ID[s[i]]]) chd[cur][ID[s[i]]] = ++sz;//���¹ؼ��ʲ��뵽trie���У�rootΪ��һ���ڵ㣬�����ڵ��±����
            cur = chd[cur][ID[s[i]]];//cul��¼�˹ؼ��ʽڵ���±�
        }
        val[cur]++;//�����ǰcur�±�Ľڵ���һ���ؼ��ʵĽ�β��val���1
		num[cur]=j;
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
    int Query(const char *s,int j) {
		cnt=0;
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