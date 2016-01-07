#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct type1{
    char name[21];
};
int N;
vector<type1> A[26][26];
int CNT[26][26];
int IN[26], OUT[26];
int ANS;
bool MK[26]; 
int cmp(type1 a, type1 b){
    return strcmp(a.name, b.name) > 0 ? 1 : 0;
}
void dfs(int k){
    MK[k] = true;
    for (int i = 0; i < 26; i++)
        if (!MK[i] && CNT[k][i])
            dfs(i);
} 
bool conn(int k){
    memset(MK, 0, sizeof(MK));
    dfs(k);
    for (int i = 0; i < 26; i++) //
        if (!MK[i] && OUT[i]+IN[i] > 0)
            return false;  
    return true;
}
void go(int k){
    int t, i;
    while (1){ 
        t = -1; 
        for (i = 0; i < 26; i++){ 
            if (CNT[k][i] > 0){
                CNT[k][i]--;
                OUT[k]--; 
                if (conn(i)){ // //找一个字典序最小的的合法串 
                    if (t == -1 || strcmp(A[k][i][CNT[k][i]].name, A[k][t][CNT[k][t]-1].name) < 0)
                        t = i;
                }
                CNT[k][i]++;
                OUT[k]++;
            }
        }
        if (t == -1) break;
        CNT[k][t]--;
        OUT[k]--;
        IN[t]--;
        printf("%s", A[k][t][CNT[k][t]].name);
        ANS++;
        if (ANS == N){
            printf("\n");
            break;
        }
        else{
            printf(".");
            k = t;
        }
    }
}
int main(){
    int cas;
    int i, j;
    type1 tmp;
    int head, tail;
    int st, en, wa, begin;
    scanf("%d", &cas);
    while (cas--){
        for (i = 0; i < 26; i++)
            for (j = 0; j < 26; j++)
                A[i][j].clear();
        memset(CNT, 0, sizeof(CNT));
        memset(IN, 0, sizeof(IN));
        memset(OUT, 0, sizeof(OUT));
        scanf("%d", &N);  getchar();
        for (i = 0; i < N; i++){
            scanf("%s", tmp.name);  
            head = tmp.name[0] - 'a';
            tail = tmp.name[strlen(tmp.name)-1] - 'a';
            A[head][tail].push_back(tmp);
            CNT[head][tail]++;          
            OUT[head]++;
            IN[tail]++;
        }
        st = en = wa = 0;    
        for (i = 0; i < 26; i++){
            if (IN[i] != OUT[i]){
                if (OUT[i] - IN[i] == 1){
                    st++;
                    begin = i;
                }
                else if (IN[i] - OUT[i] == 1)  en++;
                else{
                    wa++;
                    break;
                }
            }
        }  
        if (wa || st != en || st > 1){
            printf("***\n");
            continue;
        }
        if (st == 0){
            for (i = 0; i < 26; i++){
                if (IN[i] > 0){
                    begin = i;
                    break;
                }
            }
        }
        if (!conn(begin)){
            printf("***\n");
            continue;
        }
        for (i = 0; i < 26; i++)
            for (j = 0; j < 26; j++)
                if (CNT[i][j])
                    sort(A[i][j].begin(), A[i][j].end(), cmp);
        ANS = 0;
        go(begin);
    }
}
