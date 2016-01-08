/*
    dp���������⡣
    ���⣺
    ��n�����䣬��n-1�������ͨ������ʵ���Ͼ��γ���һ������
    �ӽ��1��������ʼ�ߣ���ÿ�����i����3�ֿ��ܣ�
        1.��ɱ�����ص����1��������Ϊki��
        2.�ҵ����ڣ��߳��Թ� ������Ϊei��
        3.�͸õ�������m���ߣ������һ��
    ���߳��Թ���Ҫ�ߵı���������ֵ��

    �� E[i]��ʾ�ڽ��i����Ҫ�߳��Թ���Ҫ�ߵı�����������E[1]��Ϊ����

    Ҷ�ӽ�㣺
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)*(E[father[i]] + 1);
         = ki*E[1] + (1-ki-ei)*E[father[i]] + (1-ki-ei);

    ��Ҷ�ӽ�㣺��mΪ���������ı�����
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)/m*( E[father[i]]+1 + ��( E[child[i]]+1 ) );
         = ki*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei)/m*��(E[child[i]]) + (1-ki-ei);

    ���ÿ����㣺E[i] = Ai*E[1] + Bi*E[father[i]] + Ci;

    ���ڷ�Ҷ�ӽ��i����jΪi�ĺ��ӽ�㣬��
    ��(E[child[i]]) = ��E[j]
                   = ��(Aj*E[1] + Bj*E[father[j]] + Cj)
                   = ��(Aj*E[1] + Bj*E[i] + Cj)
    ���������ʽ�ӵ�
    (1 - (1-ki-ei)/m*��Bj)*E[i] = (ki+(1-ki-ei)/m*��Aj)*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei) + (1-ki-ei)/m*��Cj;
    �ɴ˿ɵ�
    Ai =        (ki+(1-ki-ei)/m*��Aj)   / (1 - (1-ki-ei)/m*��Bj);
    Bi =        (1-ki-ei)/m            / (1 - (1-ki-ei)/m*��Bj);
    Ci = ( (1-ki-ei)+(1-ki-ei)/m*��Cj ) / (1 - (1-ki-ei)/m*��Bj);

    ����Ҷ�ӽ��
    Ai = ki;
    Bi = 1 - ki - ei;
    Ci = 1 - ki - ei;

    ��Ҷ�ӽ�㿪ʼ��ֱ����� A1,B1,C1;

    E[1] = A1*E[1] + B1*0 + C1;
    ����
    E[1] = C1 / (1 - A1);
    �� A1������1���޽�...

*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
const int MAXN=10010;
const double eps=1e-9;//����1e-8��WA����Ϊ1e-9��1e-10����
double k[MAXN],e[MAXN];
double A[MAXN],B[MAXN],C[MAXN];

vector<int>vec[MAXN];//����

bool dfs(int t,int pre)//t�ĸ������pre����t=1,pre=-1��ʼ��������Ǹ��ڵ㣬����������Ľ������A[1]B[1]C[1]�������ֵ
{
    int m=vec[t].size();//��t�Ķ�
    A[t]=k[t];
    B[t]=(1-k[t]-e[t])/m;
    C[t]=1-k[t]-e[t];
    double tmp=0;
    for(int i=0;i<m;i++){
        int v=vec[t][i];
        if(v==pre)continue;
        if(!dfs(v,t))return false;//һ��������������Ĺ��̣�ֱ��������Ҷ�ڵ㣬Ȼ���Ҷ�ڵ��ABCֵ���֣�һֱ���㵽���ڵ�
        A[t]+=(1-k[t]-e[t])/m*A[v];
        C[t]+=(1-k[t]-e[t])/m*C[v];
        tmp+=(1-k[t]-e[t])/m*B[v];
    }
    if(fabs(tmp-1)<eps)return false;//impossible
    A[t]/=(1-tmp);
    B[t]/=(1-tmp);
    C[t]/=(1-tmp);
    return true;
}
int main()
{
    int T;
    int n;
    int u,v;
    int iCase=0;
    scanf("%d",&T);
    while(T--){
        iCase++;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)vec[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);//���������
            vec[u].push_back(v);//��vec[u]������������������v
            vec[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&k[i],&e[i]);
            k[i]/=100;
            e[i]/=100;
        }
        printf("Case %d: ",iCase);
        if(dfs(1,-1)&&fabs(1-A[1])>eps){//fabs(1-A[1])�����ж�impossible��dfs����ABC�ļ���
            printf("%.6lf\n",C[1]/(1-A[1]));
        }
        else printf("impossible\n");
    }
}