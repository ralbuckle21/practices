/*WordStack
	As editor of a small-town newspaper, you know that a substantial number of your readers enjoy the daily word games that you publish, but that some are getting tired of the conventional crossword puzzles and word jumbles that you have been buying for years. You decide to try your hand at devising a new puzzle of your own. 

Given a collection of N words, find an arrangement of the words that divides them among N lines, padding them with leading spaces to maximize the number of non-space characters that are the same as the character immediately above them on the preceding line. Your score for this game is that number.
Input

Input data will consist of one or more test sets. 

The first line of each set will be an integer N (1 <= N <= 10) giving the number of words in the test case. The following N lines will contain the words, one word per line. Each word will be made up of the characters 'a' to 'z' and will be between 1 and 10 characters long (inclusive). 

End of input will be indicated by a non-positive value for N .
Output

Your program should output a single line containing the maximum possible score for this test case, printed with no leading or trailing spaces.
Sample Input

5 
abc 
bcd 
cde 
aaa 
bfcde 
0
Sample Output

8
Hint

Note: One possible arrangement yielding this score is: 
aaa 

abc 

 bcd

  cde 

bfcde
	*/
#include<stdio.h>
#include<string.h>

#define clear(a,b) memset(a,b,sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define maxn1 15
#define maxn2 2000

int f[maxn1][maxn2][maxn1],a[maxn1][maxn2],v[maxn1][maxn1],n;

int cal(int x)//二进制数的‘1’数量
{
  int s = 0,i;
  for(i = 0;i < n;i++)
     s += (x>>i)&1;
  return s;
}

int LCs(char s1[],char s2[])//求最长公共字串长度
{
  int i,j,l1 = strlen(s1),l2 = strlen(s2),ans = 0,b[maxn1][maxn1] = {0};
  for(i = 1;i <= l1;i++)
     for(j = 1;j <= l2;j++) {
        if (s1[i-1]==s2[j-1]) b[i][j] = b[i-1][j-1] + 1;
          else b[i][j] = b[i-1][j-1];
        ans = max(b[i][j],ans);
        }
   return ans;
}
void init()
{
    clear(a,0);
    int mi = (1 << n)-1,i,temp;
    for(i = 1;i <= mi;i++) {
       temp = cal(i);
      a[temp][++a[temp][0]] = i;//a是一个状态取值表，a[i]记录着全部已填i个字的数字编号，如a[1]=2,4,8,16...a[i][0]记录着这样数字的数量
       }
}
int work()
{
    char st[maxn1][maxn1];
    int i,j,k,t,ans = 0;

    scanf("%d",&n);//单词个数
    if (n == 0) return 0;
    init();
    clear(v,0);
    clear(f,0);
    for(i = 1;i <= n;i++) scanf("%s",st[i]);//st是单词
    for(i = 1;i <= n;i++)
       for(j = i+1;j <= n;j++) v[i][j] = v[j][i] = LCs(st[i],st[j]);//v存储单词之间最长字串长度表
    for(i = 2;i <= n;i++)//单词数量
       for(j = 1;j <= a[i][0];j++)//状态
           for(t = 0;t <= n-1;t++)
             for(k = 0;k <= n-1;k++){
               if ((t != k) &&((a[i][j]>>k)&1) &&((a[i][j]>>t)&1))  f[i][a[i][j]][k+1]  = max(f[i-1][a[i][j]-(1<<k)][t+1] + v[k+1][t+1],f[i][a[i][j]][k+1]);
			   //选择两个不同单词t,k且当前状态t和k都已经加入
			   //某点f=max(没加入k的f+k和t的lcs,自己f)
               ans = max(ans,f[i][a[i][j]][k+1]);
               }
    printf("%d\n",ans);
    return 1;
}

int main()
{
  while(work());
}
