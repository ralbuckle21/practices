#include<stdio.h>
#include <stack>
using namespace std;
int main()
{
int n;
while(scanf("%d", &n) && n)
{
   stack<int> sta;
   int s[1001],i;
   while(scanf("%d", &s[0]))
   {
    while(!sta.empty()) sta.pop();
    if(s[0]==0) { putchar('\n'); break;}
    for(i=1; i<n; i++)
     scanf("%d", &s[i]);
    int j=0;
    for(i=1; i<=n;)
    {
     while(sta.empty() || (!sta.empty() && sta.top()<s[j]))
      sta.push(i++);
     while(!sta.empty() && sta.top()==s[j])
      j++,sta.pop();
     if(!sta.empty() && j<n && sta.top()>s[j])
      break;
    }
    puts(sta.empty()?"Yes":"No");
   }
}
}